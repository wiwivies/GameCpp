#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono> // ��� ��������� ������� ����������

#include "CursornScreen.h" // ����������� ������ ��� ������ � �������
#include "HangmanGameLogic.h" // ����������� ������ ��� ���� "��������"
#include "CaesarCipher.h" // ����������� ������ ��� ����� ������
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
                    // ����������� � �������������� �������� ����� ������ �������������
                    Play() : game(), cipher(), settings()
                    {
                        // ������������� ���������� ��������� ����� �� ������ �������� �������
                        srand(static_cast<unsigned int>(time(0)));
                        // ������ ���� �� �����, �����������, ��� ����� ����������� ������� 3
                        std::vector<std::string> words = cipher.readWordsFromFile("words.txt", 3);
                        if (words.empty())
                        {
                            std::cout << "Error: Unable to read words from the file." << std::endl;
                            return;
                        }
                        // ����� ���������� ����� �� ������
                        std::string selectedWord = words[rand() % words.size()];
                        // ������������� ���� "��������" ��������� ������
                        game = HangmanGame(selectedWord);
                    }
                protected:
                    size_t nameOfGame(); // ����������� �������� �������� ����
                    void firstScreen(); // ����������� ������� ������ (�������� 1)
                    void secondScreen(); // ����������� ������� ������ (�������� 2)
                public:
                    void playGame(); // ����� ��� ������� ����
                };
            }
        }
    }
}