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
                std::string secretWord;          // Секретное слово, которое нужно угадать
                std::string guessedWord;         // Слово с угаданными буквами (символы '_')
                static const int maxAttempts = 7; // Фиксированное количество попыток
                int currentAttempts;             // Текущее количество попыток
                std::vector<char> incorrectLetters; // Вектор для хранения неправильно угаданных букв
                std::vector<char> guessedLetters;   // Вектор для хранения угаданных букв
                // Вектор с поэтапными изображениями "Виселицы" для отображения игрового прогресса
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
                // Конструктор для инициализации объекта HangmanGame
                HangmanGame(const std::string& word) : secretWord(word), currentAttempts(0)
                {
                    guessedWord = std::string(secretWord.length(), '_');
                }
                // Метод для получения секретного слова, которое нужно угадать.
                std::string getSecretWord() const;
                // Проверка, завершилась ли игра (достигнут максимальный лимит попыток или слово угадано)
                bool isGameOver() const;
                // Проверка, была ли буква уже угадана ранее
                bool isLetterAlreadyGuessed(char letter) const;
                // Обработка угаданной буквы
                bool guessLetter(char letter);
                // Отображение текущего состояния игры
                void displayGameStatus() const;
                // Отображение текущего состояния "Виселицы" в зависимости от количества ошибок
                void drawHangman() const;
            };
        }
    }
}