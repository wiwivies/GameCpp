#include "CursornScreen.h"

namespace ProjectGame
{
    namespace Settings
    {
        void CursornScreen::hideConsoleCursor()
        {
            HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_CURSOR_INFO cursorInfo;
            GetConsoleCursorInfo(out, &cursorInfo);
            cursorInfo.bVisible = false;
            SetConsoleCursorInfo(out, &cursorInfo);
        }

        void CursornScreen::showConsoleCursor()
        {
            HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_CURSOR_INFO cursorInfo;
            GetConsoleCursorInfo(out, &cursorInfo);
            cursorInfo.bVisible = true;
            SetConsoleCursorInfo(out, &cursorInfo);
        }

        void CursornScreen::clearScreen()
        {
            system("cls");
        }

        void CursornScreen::sleepMilliseconds(int milliseconds)
        {
            Sleep(milliseconds);
        }

        void CursornScreen::printWithColor(char letter)
        {
            letter = std::toupper(letter);
            switch (letter)
            {
            case 'A':
                // Black text color
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
                break;
            case 'B':
                // Red text color
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                break;
            case 'C':
                // Green text color
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                break;
            case 'D':
                // Blue text color
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                break;
            case 'E':
                // Yellow text color
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
                break;
            case 'F':
                // Purple text color (Magenta)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
                break;
            case 'G':
                // Cyan text color
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
            case 'H':
                // White text color
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
            case 'I':
                // Orange text color -
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                break;
            case 'J':
                // Light gray text color
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
                break;
            case 'K':
                // pink
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                break;
            }
        }
    }
}