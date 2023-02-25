@echo off

set BAT_BASE_PATH=%~p0

if exist "%BAT_BASE_PATH%set" (
    RD /S /Q "%BAT_BASE_PATH%set"
)

MD "%BAT_BASE_PATH%set\lib"

clang -shared -o "%BAT_BASE_PATH%set\lib\set.dll" -I "%BAT_BASE_PATH%include" -I "%BAT_BASE_PATH%library\linkedlist\include" -L "%BAT_BASE_PATH%library\linkedlist\lib" -l linkedlist "%BAT_BASE_PATH%src\*.c"

IF %ERRORLEVEL% EQU 0 (
    MD "%BAT_BASE_PATH%set\include"

    COPY /Y "%BAT_BASE_PATH%include\*.h" "%BAT_BASE_PATH%set\include"
)
