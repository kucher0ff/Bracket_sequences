@echo off
chcp 65001 > nul
setlocal enabledelayedexpansion

:: Проверка наличия программы
if not exist "Bracket_sequences.exe" (
    echo [ERROR] Bracket_sequences.exe not found!
    dir /b
    pause
    exit /b
)

:: === ТЕСТ 1 ===
echo.
echo [TEST 1] 1 pair of round brackets

:: Создаем временный файл с вводом
echo 1 > input.tmp
echo ( >> input.tmp
echo ) >> input.tmp

:: Запускаем программу с таймаутом
(
    type input.tmp | Bracket_sequences.exe > output.tmp 2>&1
    call :check_result output.tmp expected1.txt 1
)

:: === ТЕСТ 2 ===
echo.
echo [TEST 2] 2 pairs of round brackets
echo 2 > input.tmp
echo ( >> input.tmp
echo ) >> input.tmp

(
    type input.tmp | Bracket_sequences.exe > output.tmp 2>&1
    call :check_result output.tmp expected2.txt 2
)

:: Очистка
del input.tmp output.tmp 2>nul
pause
exit /b

:: === Функция проверки ===
:check_result
if not exist "%~1" (
    echo [FAIL] Test %~3 - No output file!