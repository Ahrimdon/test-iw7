@echo off

set cfg="config_mp.cfg"
set name="IW7 MP 1"
set mod=

set game_exe=iw7-mod.exe

cd /D %cd%
start /B /wait /abovenormal %game_exe% +set onlinegame 1 +set fs_game "%mod%" -nosteam