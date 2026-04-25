@echo off
setlocal
cd /d "%~dp0"

echo [1/2] Compiling Test3.java ...
javac Test3.java
if errorlevel 1 (
  echo Compile failed.
  pause
  exit /b 1
)

echo.
echo [2/2] Running Test3 ...
java Test3

echo.
echo Done.
pause
