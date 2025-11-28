@echo off

set "src=%~1"
set "out=%~2"

if "%src%"=="" goto :eof
if "%out%"=="" goto :eof

if not exist "%out%" mkdir "%out%"

xcopy "%src%dll\Debug\*.dll" "%out%\" /y /s /i
xcopy "%src%\res\*" "%out%\res\" /y /s /i