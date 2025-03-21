SetCompressor /SOLID lzma
SetCompressorDictSize 64
; /SOLID: Improves compression ratio by treating files as a single stream
; SetCompressorDictSize: Controls compression memory and efficiency
;  - Larger values (32-64) improve compression but use more memory
;  - Smaller values (16-32) use less memory but compress less effectively

!include "MUI2.nsh"
!include "WinVer.nsh"
!include "nsDialogs.nsh"
!include "FileFunc.nsh"
!include "x64.nsh"

; Constants
!define PRODUCT_NAME "IW7-Mod"
!define PRODUCT_DESCRIPTION "Call of Duty: Infinite Warfare - Client"
!define COPYRIGHT "Copyright © 2024 AlterWare"
!define PRODUCT_VERSION "1.0.0.0"
!define SETUP_VERSION "1.0.0.0"

; Attributes
Name "${PRODUCT_NAME}"
OutFile "build\iw7-installer.exe"
InstallDir "$EXEDIR"
RequestExecutionLevel user ; Request user-level execution, not admin

; Version Info
VIProductVersion "${PRODUCT_VERSION}"
VIAddVersionKey "ProductName" "${PRODUCT_NAME}"
VIAddVersionKey "ProductVersion" "${PRODUCT_VERSION}"
VIAddVersionKey "FileDescription" "${PRODUCT_DESCRIPTION}"
VIAddVersionKey "LegalCopyright" "${COPYRIGHT}"
VIAddVersionKey "FileVersion" "${SETUP_VERSION}"

; Modern UI Appearance
!define MUI_ICON "assets\graphics\icons\icon.ico"
!define MUI_UNICON "assets\graphics\icons\icon.ico"
!define MUI_HEADERIMAGE
!define MUI_FINISHPAGE_NOAUTOCLOSE
; !define MUI_FINISHPAGE_RUN "$INSTDIR\iw7-mod.exe"
!define MUI_FINISHPAGE_TEXT "Setup has finished installing ${PRODUCT_NAME} on your computer.$\nClick Finish to close this wizard.$\n$\nRun the iw7-mod.exe application from within your Call of Duty Infinite Warfare game folder or use the Desktop shortcut."

; Modern UI Settings
!define MUI_ABORTWARNING
!define MUI_UNABORTWARNING
!define MUI_FINISHPAGE_SHOWREADME ""
!define MUI_FINISHPAGE_SHOWREADME_CHECKED
!define MUI_FINISHPAGE_SHOWREADME_TEXT "Create Desktop Shortcut"
!define MUI_FINISHPAGE_SHOWREADME_FUNCTION finishpageaction

; Show details by default
ShowInstDetails show
ShowUninstDetails show

; Installer Images
!define MUI_WELCOMEFINISHPAGE_BITMAP "assets\graphics\assets\logo-cropped.bmp"
!define MUI_HEADERIMAGE_BITMAP "assets\graphics\assets\banner-iw7-title.bmp" ; For installer header

; Uninstaller Images
!define MUI_UNHEADERIMAGE_BITMAP "assets\graphics\assets\banner-iw7-title.bmp" ; For uninstaller header
!define MUI_UNWELCOMEFINISHPAGE_BITMAP "assets\graphics\assets\logo-cropped.bmp" ; For uninstaller finish page

; Pages
!insertmacro MUI_PAGE_WELCOME
; !insertmacro MUI_PAGE_LICENSE "assets\text\license.txt"
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

; Languages
!insertmacro MUI_LANGUAGE "English"

; Conditional Debug Details
!ifdef DEBUG
    ShowInstDetails always
!endif

Function .onInit
    ; X64 Filesystem Redirection
    ${If} ${RunningX64}
        ${DisableX64FSRedirection}
    ${EndIf}
    ; Check for Silent Install arguments
    ${GetParameters} $R0
    ${GetOptions} $R0 "/s" $0
    IfErrors +3
    SetSilent silent
    Goto done

    ${GetOptions} $R0 "-s" $0
    IfErrors +3
    SetSilent silent
    Goto done

    ; GUI install
    MessageBox MB_OKCANCEL|MB_ICONINFORMATION "Place the installer in your Call of Duty Infinite Warfare game folder. Click OK to continue or Cancel to exit." IDOK done
    Abort
    done:
FunctionEnd

; Check and Cleanup Old Files
Section "Cleanup Old Files"
    ; Check if each file exists before deleting
    ${If} ${FileExists} "$INSTDIR\iw7-mod.exe"
        Delete "$INSTDIR\iw7-mod.exe"
    ${EndIf}

    ${If} ${FileExists} "$INSTDIR\tlsdll.dll"
        Delete "$INSTDIR\tlsdll.dll"
    ${EndIf}

    ; Directory cleanup
    ${If} ${FileExists} "$INSTDIR\iw7-mod\custom_scripts"
        RMDir /r "$INSTDIR\iw7-mod\custom_scripts"
    ${EndIf}

    ${If} ${FileExists} "$INSTDIR\iw7-mod\sounddata"
        RMDir /r "$INSTDIR\iw7-mod\sounddata"
    ${EndIf}

    ${If} ${FileExists} "$INSTDIR\iw7-mod\ui_scripts"
        RMDir /r "$INSTDIR\iw7-mod\ui_scripts"
    ${EndIf}

    ${If} ${FileExists} "$INSTDIR\iw7-mod\zone"
        RMDir /r "$INSTDIR\iw7-mod\zone"
    ${EndIf}

    ; IfFileExists "$INSTDIR\*.*" 0 +2
    ;     RMDir /r "$INSTDIR\*.*"
SectionEnd

; Sections
Section "Main Application" SecMain
    SetOutPath $INSTDIR
    File "..\build\bin\x64\Release\iw7-mod.exe"
    File "..\build\bin\x64\Release\tlsdll.dll"
    WriteUninstaller "$INSTDIR\Uninstall.exe"
SectionEnd

Section "Custom Game Files Files" SecData
    SetOutPath $INSTDIR\iw7-mod
    File /r "..\data\cdata\*.*"
SectionEnd

Section "Server Config Files" SecConfigData
    SetOutPath $INSTDIR\main
    File "..\cfg\main\*.*"
SectionEnd

Section "Batch Files" SecBatchData
    SetOutPath $INSTDIR
    File "..\cfg\!start_client.bat"
    File "..\cfg\!start_mp_server.bat"
    File "..\cfg\!start_zm_server.bat"
SectionEnd

Function finishpageaction
    SetOutPath $INSTDIR
    CreateShortcut "$DESKTOP\${PRODUCT_NAME}.lnk" "$INSTDIR\iw7-mod.exe" "" "$INSTDIR\iw7-mod.exe"
FunctionEnd

; Display informational message after silent installation is complete
Function .onInstSuccess
    ${If} ${Silent}
        MessageBox MB_ICONINFORMATION|MB_OKCANCEL "Install complete! Launch IW7-Mod?" IDOK launchGame
        Return
        
        launchGame:
        Exec "$INSTDIR\iw7-mod.exe"
    ${EndIf}
FunctionEnd

; Uninstaller
Section "Uninstall"
    ; ; Check for Silent Uninstall arguments
    ; ${GetParameters} $R0
    ; ${GetOptions} $R0 "/s" $0
    ; IfErrors +3
    ; SetSilent silent

    ; ${GetOptions} $R0 "-s" $0
    ; IfErrors +3
    ; SetSilent silent

    Delete "$DESKTOP\${PRODUCT_NAME}.lnk"
    Delete $INSTDIR\iw7-mod.exe
    Delete $INSTDIR\tlsdll.dll
    Delete $INSTDIR\main\server_mp.cfg
    Delete $INSTDIR\main\server_zm.cfg
    Delete "$INSTDIR\!start_client.bat"
    Delete "$INSTDIR\!start_mp_server.bat"
    Delete "$INSTDIR\!start_zm_server.bat"

    RMDir /r $INSTDIR\iw7-mod

    Delete "$INSTDIR\Uninstall.exe"
    ; RMDir $INSTDIR
SectionEnd
