@echo off

if not exist "build" mkdir "build"
"tools\makensis.exe" "iw7_Installer.nsi"

echo.
echo Compiled successfully!
echo.

pause