@echo off
setlocal
cd /d "%~dp0"

echo [1/2] Compiling Fan.java and TestFan.java ...
javac Fan.java TestFan.java
if errorlevel 1 (
  echo Compile failed.
  pause
  exit /b 1
)

echo.
echo [2/2] Running TestFan ...
java TestFan

echo.
echo Done.
pause
