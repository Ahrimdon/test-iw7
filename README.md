# IW7-Mod

[![discord](https://img.shields.io/badge/Repackers-_Disocrd-blue)](https://discord.com/invite/YcZv2Stt2w)
[![website](https://img.shields.io/badge/Repackers-_Website-blue)](https://rimmyscorner.com/)

<p align="center">
  <img src="assets/gitea/banner-iw7.png?raw=true" />
</p>

## Prerequisites: Installing Git (Optional)

If you don't have `git` installed on your machine, follow these steps:

1. Visit the [Git download page](https://git-scm.com/downloads).
2. Download the appropriate version for your operating system.
3. Run the installer.
   - During the installation, you will be asked if you want to add Git to your system's PATH environment variable. Ensure you choose the option to do so. This allows you to use Git from the command line without specifying its full path.
4. After installation, open a terminal or command prompt and type `git --version` to ensure Git is correctly installed.

## Download
Clone the Git repository or download as ZIP.

- <u>**Download Release (EASIEST)**</u>
  - Click on `Releases` at the top and navigate to the latest release
  - Click `iw7-mod.zip`

- <u>**Download ZIP**</u>
  - Click on the three dots at the top of the repo ( `◘◘◘` )
  - Click `Download ZIP`

- <u>**Clone the repository:**</u>
  - Open a terminal or command prompt.
  - Run the following command:
    ```
    git clone http://git.rimmyscorner.com/Rim/iw7-mod.git
    ```

## Repository Contents
  - IW7-Mod Client
  - All Necessary Files

## Added Features
  - Removed IW7-Mod Watermark
  - Remove "--dirty" commit version on build
  - Remove Steam/Ownership verification

## Installation

1. Extract `iw7-mod.exe`, `runner.exe` & `tlsdll.dll` in your `Infinite Warfare` directory.
    > **Note**: Usual location is `C:\Program Files (x86)\Steam\steamapps\common\Call of Duty - Infinite Warfare`
2. Launch `iw7-mod.exe`

## Compile from source

- Clone the Git repo. Do NOT download it as ZIP, that won't work.
- Update the submodules and run `premake5 vs2022` or simply use the delivered `generate.bat`.
- Build via solution file in `build\iw7-mod.sln`.

### Premake arguments

| Argument                    | Description                                    |
|:----------------------------|:-----------------------------------------------|
| `--copy-to=PATH`            | Optional, copy the EXE to a custom folder after build, define the path here if wanted. |
| `--dev-build`               | Enable development builds of the client. |

## Credits

- [h1-mod](https://github.com/h1-mod/h1-mod) - codebase and research
- [h2-mod](https://github.com/fedddddd/h2-mod) - research (successor of MWR)
- [momo5502](https://github.com/momo5502) - Arxan/Steam research, former lead developer of [XLabsProject](https://github.com/XLabsProject)

## Disclaimer

This software has been created purely for the purposes of academic research. It is not intended to be used to attack other systems. Project maintainers are not responsible or liable for misuse of the software. Use responsibly.
