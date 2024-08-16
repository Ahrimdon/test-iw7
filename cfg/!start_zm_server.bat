@echo off
::///////////////////////////////////////////////////////////////////////
:://             IW7-Mod Server Configuration startup file             //
::///////////////////////////////////////////////////////////////////////
::// This config best view with Notepad++ or other non-windows notepad //
::///////////////////////////////////////////////////////////////////////
:://        Your edited server_zm.cfg goes in the "main" folder        //
:://     This is were you edit your hostname, map & gamemodes from     //
::///////////////////////////////////////////////////////////////////////

set cfg=server_zm.cfg
set port=27017
set name="IW7 ZM 1"
set mod=

::///////////////////////////////////////////////////////////////////////
:://  You're done! WARNING! Do not mess with anything below this line  //
::///////////////////////////////////////////////////////////////////////

set game_exe=iw7-mod.exe

title IW7 - %name% - Server restarter
echo Server "%name%" will load %cfg% and listen on port %port% UDP!
echo To shut down the server close this window first!
echo (%date%) - (%time%) %name% server start.

cd /D "%~dp0"
:server
start /wait /abovenormal %game_exe% -dedicated +cpMode +set onlinegame 1 +set fs_game "%mod%" +set net_port "%port%" +exec %cfg% +map_rotate +set g_hardcore 0 +set xblive_privatematch 0 +set sv_lanOnly 0
echo (%date%) - (%time%) WARNING: %name% server closed or dropped... server restarts.
goto server
