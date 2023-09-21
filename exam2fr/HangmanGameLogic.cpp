#include "HangmanGameLogic.h"

namespace ProjectGame
{
    namespace usingForGameAssembly
    {
        namespace HangmanGameLogic
        {
            std::string HangmanGame::getSecretWord() const
            {
                return secretWord;
            }

            bool HangmanGame::isGameOver() const
            {
                return (currentAttempts >= maxAttempts) || (guessedWord.find('_') == std::string::npos);
            }

            bool HangmanGame::isLetterAlreadyGuessed(char letter) const
            {
                return guessedWord.find(letter) != std::string::npos || std::find(incorrectLetters.begin(), incorrectLetters.end(), letter) != incorrectLetters.end();
            }

            bool HangmanGame::guessLetter(char letter)
            {
                letter = std::toupper(letter);

                // Лямбда-функция для проверки, была ли буква уже угадана верно или неверно.
                auto isAlreadyGuessed = [&](const std::vector<char>& container) {
                    return std::any_of(container.begin(), container.end(), [&](char c) {
                        return std::toupper(c) == letter;
                        });
                };

                if (isAlreadyGuessed(guessedLetters) || isAlreadyGuessed(incorrectLetters))
                {
                    return false; // Буква уже была угадана верно или неверно.
                }

                guessedLetters.push_back(letter); // Добавить угаданную букву в список угаданных букв.
                bool letterGuessed = false;

                // Проход по секретному слову и обновление guessedWord соответственно.
                for (size_t i = 0; i < secretWord.length(); ++i)
                {
                    if (std::toupper(secretWord[i]) == letter)
                    { // Сравнение букв в верхнем регистре.
                        guessedWord[i] = secretWord[i];
                        letterGuessed = true;
                    }
                }

                if (!letterGuessed)
                {
                    incorrectLetters.push_back(letter);
                    ++currentAttempts;
                }

                return letterGuessed;
            }

            void HangmanGame::displayGameStatus() const
            {
                std::cout << "Secret Word: ";
                for (char letter : guessedWord)
                {
                    std::cout << letter << " ";
                }
                std::cout << std::endl;

                std::cout << "Incorrect Letters: ";
                for (char letter : incorrectLetters)
                {
                    std::cout << letter << " ";
                }
                std::cout << std::endl;

                std::cout << "Attempts Left: " << maxAttempts - currentAttempts << std::endl;
            }

            void HangmanGame::drawHangman() const
            {
                int stage = currentAttempts <= maxAttempts ? currentAttempts : maxAttempts;
                std::cout << std::endl << hangmanDrawing[stage] << std::endl;
            }
        }
    }
}