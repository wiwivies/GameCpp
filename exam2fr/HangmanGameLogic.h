#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <windows.h>
#include "InitialComposition.h"

namespace ProjectGame
{
    namespace usingForGameAssembly
    {
        namespace HangmanGameLogic
        {
            class HangmanGame
            {
            protected:
                std::string secretWord;          // ��������� �����, ������� ����� �������
                std::string guessedWord;         // ����� � ���������� ������� (������� '_')
                static const int maxAttempts = 7; // ������������� ���������� �������
                int currentAttempts;             // ������� ���������� �������
                std::vector<char> incorrectLetters; // ������ ��� �������� ����������� ��������� ����
                std::vector<char> guessedLetters;   // ������ ��� �������� ��������� ����
                // ������ � ���������� ������������� "��������" ��� ����������� �������� ���������
                std::vector<std::string> hangmanDrawing =
                {
                    "\t\t\t\t\t\t      +---------\n\t\t\t\t\t\t      |     |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      "
                    "|\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t______|_________",

                    "\t\t\t\t\t\t      +---------\n\t\t\t\t\t\t      |     |\n\t\t\t\t\t\t      |     O\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      "
                    "|\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t______|_________",

                    "\t\t\t\t\t\t      +---------\n\t\t\t\t\t\t      |     |\n\t\t\t\t\t\t      |     O\n\t\t\t\t\t\t      |     |\n\t\t\t\t\t\t      |"
                    "\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t______|_________",

                    "\t\t\t\t\t\t      +---------\n\t\t\t\t\t\t      |     |\n\t\t\t\t\t\t      |     O\n\t\t\t\t\t\t      |    /|\n\t\t\t\t\t\t      "
                    "|\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t______|_________",

                    "\t\t\t\t\t\t      +---------\n\t\t\t\t\t\t      |     |\n\t\t\t\t\t\t      |     O\n\t\t\t\t\t\t      |    /|\\\n\t\t\t\t\t\t      "
                    "|\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t______|_________",

                    "\t\t\t\t\t\t      +---------\n\t\t\t\t\t\t      |     |\n\t\t\t\t\t\t      |     O\n\t\t\t\t\t\t      |    /|\\\n\t\t\t\t\t\t      |     "
                    "|\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t______|_________",

                    "\t\t\t\t\t\t      +---------\n\t\t\t\t\t\t      |     |\n\t\t\t\t\t\t      |     O\n\t\t\t\t\t\t      |    /|\\\n\t\t\t\t\t\t      |     "
                    "|\n\t\t\t\t\t\t      |    /\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t______|_________",

                    "\t\t\t\t\t\t      +---------\n\t\t\t\t\t\t      |     |\n\t\t\t\t\t\t      |     O\n\t\t\t\t\t\t      |    /|\\\n\t\t\t\t\t\t      |     "
                    "|\n\t\t\t\t\t\t      |    / \\\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t      |\n\t\t\t\t\t\t______|_________"
                };
            public:

                HangmanGame() : currentAttempts(0) { }
                // ����������� ��� ������������� ������� HangmanGame
                HangmanGame(const std::string& word) : secretWord(word), currentAttempts(0)
                {
                    guessedWord = std::string(secretWord.length(), '_');
                }
                // ����� ��� ��������� ���������� �����, ������� ����� �������.
                std::string getSecretWord() const;
                // ��������, ����������� �� ���� (��������� ������������ ����� ������� ��� ����� �������)
                bool isGameOver() const;
                // ��������, ���� �� ����� ��� ������� �����
                bool isLetterAlreadyGuessed(char letter) const;
                // ��������� ��������� �����
                bool guessLetter(char letter);
                // ����������� �������� ��������� ����
                void displayGameStatus() const;
                // ����������� �������� ��������� "��������" � ����������� �� ���������� ������
                void drawHangman() const;
            };
        }
    }
}