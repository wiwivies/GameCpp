#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono> // Для измерения времени выполнения

#include "CursornScreen.h" // Подключение класса для работы с экраном
#include "HangmanGameLogic.h" // Подключение класса для игры "Виселица"
#include "CaesarCipher.h" // Подключение класса для шифра Цезаря
#include "InitialComposition.h"

namespace ProjectGame
{
    namespace usingForGameAssembly
    {
        namespace HangmanGameLogic
        {
            namespace GeneralGame
            {
                class Play
                {
                private:
                    HangmanGame game;
                    ProjectGame::usingForGameAssembly::WordsEncryption::CaesarCipher cipher;
                    ProjectGame::Settings::CursornScreen settings;
                public:
                    // Конструктор с инициализацией объектов через список инициализации
                    Play() : game(), cipher(), settings()
                    {
                        // Инициализация генератора случайных чисел на основе текущего времени
                        srand(static_cast<unsigned int>(time(0)));
                        // Чтение слов из файла, предполагая, что слова зашифрованы сдвигом 3
                        std::vector<std::string> words = cipher.readWordsFromFile("words.txt", 3);
                        if (words.empty())
                        {
                            std::cout << "Error: Unable to read words from the file." << std::endl;
                            return;
                        }
                        // Выбор случайного слова из списка
                        std::string selectedWord = words[rand() % words.size()];
                        // Инициализация игры "Виселица" выбранным словом
                        game = HangmanGame(selectedWord);
                    }
                protected:
                    size_t nameOfGame(); // Отображение главного названия игры
                    void firstScreen(); // Отображение первого экрана (заставка 1)
                    void secondScreen(); // Отображение второго экрана (заставка 2)
                public:
                    void playGame(); // Метод для запуска игры
                };
            }
        }
    }
}