@echo off

set cfg="config_mp.cfg"
set mod=

set game_exe=iw7-mod.exe

cd /D "%~dp0"
start /B /wait /abovenormal %game_exe% -nosteam +set onlinegame 1 +set fs_game "%mod%"
