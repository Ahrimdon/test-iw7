# IW7-Mod

[![discord](https://img.shields.io/badge/Repackers-_Discord-blue)](https://discord.com/invite/YcZv2Stt2w)
[![website](https://img.shields.io/badge/Repackers-_Website-red)](https://rimmyscorner.com/)

<p align="center">
  <img src="assets/gitea/banner-iw7.png?raw=true" />
</p>

> [!IMPORTANT]
> - ### You do ***<u>NOT</u>*** need to own *Call of Duty®: Infinite Warfare* to run this mod. Cracked or pirated versions of the game ***<u>ARE</u>*** supported (see [below](#pirated-versions))
> - ### Steam Verification has been removed.
> - ### Dedicated servers are now working with the latest build!

## Table of Contents
- [Client Download](#downloads)
- [Requirements](#requirements)
- [Install Instructions](#install-instructions)
  - [Installer](#installer)
  - [Zip Archive](#zip-archive)
- [Cloning the repository](#cloning-the-repository)
  - [Using Git](#using-git)
  - [Download as ZIP](#download-as-zip)
  - [Installing Git (Optional)](#installing-git-optional)
- [Where can I get the game?](#where-can-i-get-the-game)
  - [Downloading qBittorrent](#downloading-qbittorrent)
- [What if I have a pirated version of *Call of Duty®: Infinite Warfare*](#pirated-versions)
  - [Common Issues & Solutions](#common-issues)
- [Hosting a Dedicated Server](#dedicated-server)
  - [Requirements](#requirements-1)
  - [Server Setup](#server-setup)
  - [Connecting](#connecting)
- [Compile from Source Code](#compile-from-source-code)
  - [Prerequisites](#prerequisites)
  - [Build](#build)
    - [Build Using Scripts](#build-using-scripts)
    - [Build Using Tasks](#build-using-tasks)
  - [Premake Arguments](#premake-arguments)
- [Credits](#credits)
- [Disclaimer and Limitation of Liability](#disclaimer)

## Client Download<a id="downloads"></a>
[Click here for all client related downloads](https://git.rimmyscorner.com/Rim/iw7-mod/releases/tag/latest#downloads)

## Requirements<a id="requirements"></a>

- Call of Duty Infinite Warfare game files (see below for cracked versions)
- Windows 10/11 Operating System (if using Wine on Linux you shouldn't need this guide)
- Steam installed

## Install Instructions<a id="instructions"></a>

<a id="installer"></a>
### <u>Installer</u>
1. Download or compile [`iw7Installer.exe`](https://git.rimmyscorner.com/Rim/iw7-mod/releases/download/latest/iw7Installer.exe)
1. Place in Call of Duty Infinite Warfare game directory and run

(*The installer is fully [Open Source](https://git.rimmyscorner.com/Rim/iw7-mod/src/branch/main/installer/iw7_Installer.nsi) and created using NSIS*)

  > [!NOTE]
  > * Run installer as Administrator if your game installation is in a protected folder (e.g. `C:\Program Files`)
  > * You **DO NOT** need to disable your anti-virus to run the installer

  > [!NOTE]
  > - Installs the IW7-Mod Client
  > - Places the required client files and scripts
  > - Places the server configuration files in
  > - Gives you the option to a Desktop shortcut for the IW7-Mod Client
  > - Creates uninstaller to remove all files

  > [!WARNING]
  > Running the uninstaller will remove **ALL** files, including savegames, player stats, loadouts, etc. If you wish to uninstall and play in the future, make a backup of the `iw7-mod/*` folder located in your game directory

<a id="zip-archive"></a>
### <u>Zip Archive</u>
1. Download `iw7-mod.zip`
2. Extract the contents of `iw7-mod.zip` into your Call of Duty Infinite Warfare game directory
    > **Note:** The default Steam installation path is usually `C:\Program Files (x86)\Steam\steamapps\common\Call of Duty - Infinite Warfare`
3. Launch the game using either `iw7-mod.exe` or `!launch_iw7_mod.bat`

## Cloning the repository<a id="cloning-the-repository"></a>

<a id="using-git"></a>
### <u>Using Git</u>
1. Ensure you have Git installed on your computer and added to your PATH environment variable
2. Open a terminal or command prompt
3. Run the following command:
    ```
    git clone http://git.rimmyscorner.com/Rim/iw7-mod.git
    ```

<a id="download-as-zip"></a>
### <u>Download as ZIP</u>
1. Click on the three dots at the top of the repo ( `◘◘◘` )
2. Click `Download ZIP`
3. Extract the zip archive

### Installing Git (Optional)<a id="installing-git"></a>

If you don't have `git` installed on your machine, follow these steps:

1. Visit the [Git download page](https://git-scm.com/downloads).
2. Download the appropriate version for your operating system.
3. Run the installer.
   - During the installation, you will be asked if you want to add Git to your system's PATH environment variable. Ensure you choose the option to do so. This allows you to use Git from the command line without specifying its full path.
4. After installation, open a terminal or command prompt and type `git --version` to ensure Git is correctly installed.

## Where can I get the game?<a id="where-can-i-get-the-game"></a>
1. You can get the game on [Steam](https://store.steampowered.com/agecheck/app/292730/) (preferred)
2. If you can't afford the game. Oh well, you tried. You can get the game for free by [torrent](https://git.rimmyscorner.com/Rim/cod-games-download/releases/download/latest/iw7_full_game.zip) or [magnet](magnet:?xt=urn:btih:LVMN5UHPVZZ65KPW4FB32TQBMWHRQXQQ&dn=Call%20of%20Duty%20Infinite%20Warfare-Rui.7z&xl=102090401846&tr=udp%3A%2F%2Ftracker.opentrackr.org%3A1337%2Fannounce)

    > [!TIP]
    Use a a free, open source and ad-free torrenting software such as [qBittorrent](https://www.qbittorrent.org/download) and a VPN to avoid copyright letters from your ISP (i.e. https://iknowwhatyoudownload.com)

### Downloading qBittorrent<a id="downloading-qbittorrent"></a>

1. Visit the [qBittorrent Download Page](https://www.qbittorrent.org/download).
2. Open `.torrent` or `.magnet` files in qBittorrent
3. Set your game(s) folder as your download directory (***e.g.*** `C:\Program Files (x86)\Steam\steamapps\common\Call of Duty...` or `D:\Games\Call of Duty...`)
4. On the "content layout" drop-down menu, select "Don't create subfolder"
5. Start the download and wait until it says "100% - Seeding"
6. You can now remove the torrent from qBittorrent (right click -> remove) or keep seeding to help others download faster
    > [!CAUTION]
    Make sure "Also Permanently Delete the Files" is **UNCHECKED**!
7. Once files are downloaded, move on to installing the clients

### What if I have a pirated version of *Call of Duty®: Infinite Warfare*<a id="pirated-versions"></a>
If you torrent the .7z archive, it is missing some of the latest game files. In order to update your game, download and extract the [`patch.7z`](https://git.rimmyscorner.com/Rim/iw7-mod/releases/download/latest/patch.7z) archive below into your `Call of Duty Infinite Warfare/` game directory and overwrite any files it prompts.

### Common Issues & Solutions<a id="common-issues"></a>
* *If you encounter issues extracting the 7z archive (e.g., 'The parameter is incorrect'), open the file in 7-Zip GUI, navigate to the `Call of Duty Infinite Warfare` folder in the archive, select all files, click `Extract`, and specify your game folder path. This will directly extract the game files to the location.*

# Hosting a Dedicated Server<a id="dedicated-server"></a>

### Requirements<a id="#requirements-1"></a>
* The [Visual C++ 2010 Redistributable Package](https://www.microsoft.com/en-us/download/details.aspx?id=5555) and the [Visual C++ 2015-2019 Redistributable Package](https://aka.ms/vs/16/release/vc_redist.x86.exe).
* [Visual Code](https://code.visualstudio.com/), [Notepad++](https://notepad-plus-plus.org/) or [Sublime Text](https://www.sublimetext.com/) (You may use whatever editor you choose but we don't recommend Windows Notepad).
* A computer or VPS that is online 24/7 with a decent connection and above-average specs (VPS is strongly advised).
* Some technical knowledge/background knowledge of computers.
* An original copy of the game.

### Server Setup<a id="server-setup"></a>
1. Download the `IW7DedicatedConfigs.zip` and extract into `Call of Duty Infinite Warfare/` game directory.
2. Edit your `!start_mp_server.bat`, changing the ***CFG***, ***PORT***, ***WINDOW TITLE (NAME)***, and ***MOD*** (leave blank for now).
3. Edit the `main/server_mp.cfg` to your liking (i.e. changing the ***map rotation*** and ***hostname***)
4. If using Windows, set an *Inbound* and *Outbound* firewall rule for the program executable and the port you chose (default: 27017) for UDP (Optional: Add the same rule for TCP to be safe)
5. <a id="forward-ports"></a>Forward the TCP and UDP port (27017). If you changed the default port or are adding another server, you may need to open the following additional ports: 27018, 21019, etc. This step is not required on a dedicated server or VPS.
6. Run the `!start_mp_server.bat`

### Connecting<a id="connecting"></a>
1. You can either connect using the built-in *Server Browser* or by executing the in-game command `/connect ip:port`. This can either be your Local or WAN IPv4 address
   - Obtain your Local IPv4 address by pressing `Win + R`, typing `cmd`, entering `ipconfig` and pressing `Enter`
   - Obtain your WAN IPv4 address by visiting a site like [WhatIsMyIP](https://www.whatismyip.com/) or [IPChicken](https://ipchicken.com/). If you have `curl` installed, you run the command `curl ifconfig.me`
> Local Example: Connecting locally would look like `/connect 192.168.0.202:27017`\
> WAN Example: Connecting over the internet would look like `/connect 192.145.117.83:27017` (*you must [forward ports](#forward-ports) on your router*)

## Compile from Source Code<a id="compile-from-source-code"></a>

### <u>Prerequisites</u><a id="#prerequisites"></a>

* [Visual Studio 2022](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&cid=2030&passive=false)
* The required code libraries installed using [VSBuildTools](https://aka.ms/vs/17/release/vs_BuildTools.exe)

### <u>Build</u><a id="build"></a>

Clone the Git repository using `git clone https://git.rimmyscorner.com/Rim/iw7-mod.git` (It is recommended to clone, however you can `Download ZIP` as all submodules have been localized).

<a id="using-scripts"></a>
#### Build Using Scripts
  1. Run `generate.bat` to initialize the submodules and build the VS `.sln` file.
  2. Open the project in Visual Studio, change the top drop down lists to `Release`, `x64`. You can also modify (or leave same) the Visual Studio edition/path in the `build.bat` file and build the solution via the batch script.
  3. Build the application.

<a id="using-tasks"></a>
#### Build Using Tasks
  1. Open the folder workspace in [VSCode](https://code.visualstudio.com/download) or [VSCodium](https://github.com/VSCodium/vscodium)
  2. Bring up `Run Task` dialog
     - By default, press `Ctrl + Shift + P` and enter `Run Task`\
    or
     - Press `Ctrl + Shift + B` to bring up the tasks menu directly
  3. Run the task

### <u>Premake Arguments</u><a id="premake-arguments"></a>
| Argument                    | Description                                    |
|:----------------------------|:-----------------------------------------------|
| `--copy-to=PATH`            | Optional, copy the EXE to a custom folder after build, define the path here if wanted. |
| `--dev-build`               | Enable development builds of the client. |

## Credits<a id="credits"></a>

- [h1-mod](https://github.com/h1-mod/h1-mod) - codebase and research
- [h2-mod](https://github.com/fedddddd/h2-mod) - research (successor of MWR)
- [momo5502](https://github.com/momo5502) - Arxan/Steam research, former lead developer of [XLabsProject](https://github.com/XLabsProject)

## Disclaimer and Limitation of Liability<a id="disclaimer"></a>

i. **Purpose and Use**  
   This software ("Software") is developed solely for academic research and educational purposes. It is expressly not designed or intended for use in any manner that would involve unauthorized access, attack, or compromise of other computer systems or networks.

ii. **No Liability for Misuse**  
   The project maintainers, developers, and contributors (collectively, "Project Team") disclaim any and all liability for any damages or consequences arising from the use, misuse, or inability to use the Software. The Project Team shall not be held responsible for any claims, losses, or damages, including but not limited to indirect, incidental, consequential, or punitive damages, resulting from or related to the use of the Software.

iii. **As-Is Basis**  
   The Software is provided on an "as-is" and "as-available" basis, without any representations or warranties, express or implied, of any kind. The Project Team makes no warranty regarding the accuracy, reliability, completeness, or suitability of the Software for any purpose. By using the Software, you acknowledge and agree that you bear the sole responsibility for its use and that the Project Team shall have no obligation or liability for any issues or damages that may arise.

iv. **Responsibility and Risk**  
   You agree to use the Software at your own risk. The Project Team shall not be responsible or liable for any actions taken by you in connection with the Software. You assume all responsibility for any consequences resulting from your use of the Software, and you agree to indemnify and hold harmless the Project Team from any claims or demands arising from such use.

v. **Prohibition of Illegal Activities**  
   The Project Team does not endorse or condone piracy or any illegal activities. Requests for, provision of, or discussion of illegal download links or methods are strictly prohibited within any community or platform associated with the Software. Violation of this policy may result in removal from the community and/or legal action.

<!-- ## Repository Contents
  - IW7-Mod Client
  - All Necessary Files

## Added Features
  - Removed IW7-Mod Watermark
  - Remove "--dirty" commit version on build
  - Remove Steam/Ownership verification -->