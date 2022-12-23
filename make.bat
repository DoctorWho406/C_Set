@echo off

set BAT_BASE_PATH=%~p0

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

if exist "%BAT_BASE_PATH%library\set.dll" (
    DEL /Q "%BAT_BASE_PATH%library\set.dll"
)

if exist "%BAT_BASE_PATH%library\set.exp" (
    DEL /Q "%BAT_BASE_PATH%library\set.exp"
)

if exist "%BAT_BASE_PATH%library\set.lib" (
    DEL /Q "%BAT_BASE_PATH%library\set.lib"
)

clang -shared -o "%BAT_BASE_PATH%library\set.dll" -I "%BAT_BASE_PATH%include" "%BAT_BASE_PATH%src\Set.c" -l hash -l linkedlist -L "%BAT_BASE_PATH%library"