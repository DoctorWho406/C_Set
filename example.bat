@echo off

set BAT_BASE_PATH=%~p0

IF EXIST "%BAT_BASE_PATH%examples\bin" (
    RD /S /Q "%BAT_BASE_PATH%examples\bin"
)

MD "%BAT_BASE_PATH%examples\bin"

COPY "%BAT_BASE_PATH%library\linkedlist.dll" "%BAT_BASE_PATH%examples\bin\linkedlist.dll"

if exist "%BAT_BASE_PATH%library\hash.dll" (
    DEL /Q "%BAT_BASE_PATH%library\hash.dll"
)

if exist "%BAT_BASE_PATH%library\hash.exp" (
    DEL /Q "%BAT_BASE_PATH%library\hash.exp"
)

if exist "%BAT_BASE_PATH%library\hash.lib" (
    DEL /Q "%BAT_BASE_PATH%library\hash.lib"
)

clang -shared -o "%BAT_BASE_PATH%library\hash.dll" "%BAT_BASE_PATH%src\Hash.c"

clang -o "%BAT_BASE_PATH%examples\bin\Example.exe" -I "%BAT_BASE_PATH%include" -I "%BAT_BASE_PATH%examples\include" "%BAT_BASE_PATH%examples\src\main.c" "%BAT_BASE_PATH%examples\src\StringItem.c" "%BAT_BASE_PATH%src\Set.c" -l hash -l linkedlist -L "%BAT_BASE_PATH%library" 

COPY "%BAT_BASE_PATH%library\hash.dll" "%BAT_BASE_PATH%examples\bin\hash.dll"

IF EXIST "%BAT_BASE_PATH%examples\bin\Example.exp" (
    DEL /Q "%BAT_BASE_PATH%examples\bin\Example.exp"
)

IF EXIST "%BAT_BASE_PATH%examples\bin\Example.lib" (
    DEL /Q "%BAT_BASE_PATH%examples\bin\Example.lib"
)