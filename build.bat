@echo off

"C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\msbuild.exe" build\iw7-mod.sln /p:Configuration=Release /p:Platform=x64

pause