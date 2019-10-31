@echo off

set VER=25

cd postbuild
copy ..\Release\rom2me.dll rom2me.dll >nul
copy "original\ROM2 Map Editor.exe" rom2me.exe >nul
dllinject rom2me.dis
