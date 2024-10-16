#pragma once
#include <include.hpp>

void SetupConsole()
{
    HWND hwnd = GetConsoleWindow();
    if (hwnd == NULL)
    {
        MessageBoxA(0, xorstr_("Application Could not get console window handle."), NULL, MB_ICONERROR);
        ExitProcess(0);
    }

    RECT rect;
    GetWindowRect(hwnd, &rect);
    MoveWindow(hwnd, rect.left, rect.top, 700, 400, TRUE);

    LONG style = GetWindowLong(hwnd, GWL_STYLE);
    style &= ~WS_SIZEBOX;
    style &= ~WS_MAXIMIZEBOX;
    SetWindowLong(hwnd, GWL_STYLE, style);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize;
    bufferSize.X = 700 / 8;
    bufferSize.Y = 400 / 16;
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    LONG exStyle = GetWindowLong(hwnd, GWL_EXSTYLE);
    exStyle |= WS_EX_LAYERED;
    SetWindowLong(hwnd, GWL_EXSTYLE, exStyle);
    SetLayeredWindowAttributes(hwnd, 0, 230, LWA_ALPHA);

    SetConsoleTitleA(Config::app_name.c_str());

    CONSOLE_SCREEN_BUFFER_INFOEX csbi;
    csbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(hConsole, &csbi);
    csbi.dwSize.Y = bufferSize.Y;
    SetConsoleScreenBufferInfoEx(hConsole, &csbi);

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    SetConsoleTextAttribute(hConsole, consoleInfo.wAttributes);
}