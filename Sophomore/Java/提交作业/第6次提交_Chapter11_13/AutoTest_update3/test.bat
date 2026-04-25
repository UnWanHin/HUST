@echo off
set JAVA_HOME=C:\Program Files\Eclipse Adoptium\jdk-21.0.10.7-hotspot
set PATH=%JAVA_HOME%/bin;%PATH%

rem ��������TestNG������Jar������Ŀ¼����ǰĿ¼��lib��Ŀ¼��
set LIB_DIR=.\lib

rem ���ñ��������Ŀ¼��������Ŀ¼�ĸ�Ŀ¼��
set TO_BE_TEST_CLASSPAH=.\betest

rem ���ò������Ŀ¼(������Ŀ¼�ĸ�Ŀ¼��,Ϊ��ǰĿ¼��test��Ŀ¼
set TEST_SUITE_CLASSPATH=.\test

rem ������TestNG������Jar���Ž�CLASSPATH
setlocal EnableDelayedExpansion
set DEP_JAR=""
for /r %LIB_DIR% %%i in (*.jar) do if !DEP_JAR!=="" (set DEP_JAR=%%i) else (set DEP_JAR=!DEP_JAR!;%%i) 

set CLASSPATH=%CLASSPATH%;%TO_BE_TEST_CLASSPAH%;%TEST_SUITE_CLASSPATH%;%DEP_JAR%


java  --add-opens java.base/java.lang=ALL-UNNAMED --add-opens java.base/java.math=ALL-UNNAMED --add-opens java.base/sun.net.util=ALL-UNNAMED org.testng.TestNG testng.xml -d test-output
