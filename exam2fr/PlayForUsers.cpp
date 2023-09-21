#include "PlayForUsers.h"

namespace ProjectGame
{
    namespace usingForGameAssembly
    {
        namespace HangmanGameLogic
        {
            namespace GeneralGame
            {
                size_t Play::nameOfGame()
                {
                    std::vector<std::string> asciiArt =
                    {
                        "HH   HH   AAA   NN   NN   GGGG  MM    MM   AAA   NN   NN",
                        "HH   HH  AAAAA  NNN  NN  GG  GG MMM  MMM  AAAAA  NNN  NN",
                        "HHHHHHH AA   AA NN N NN GG      MM MM MM AA   AA NN N NN",
                        "HH   HH AAAAAAA NN  NNN GG   GG MM    MM AAAAAAA NN  NNN",
                        "HH   HH AA   AA NN   NN  GGGGGG MM    MM AA   AA NN   NN"
                    };

                    // Определение ширины консоли и вычисление количества пробелов для центрирования
                    CONSOLE_SCREEN_BUFFER_INFO csbi;
                    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
                    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
                    size_t spaces = (consoleWidth - asciiArt[0].length()) / 2;

                    std::cout << "\n";
                    settings.printWithColor(char('b'));
                    for (const auto& line : asciiArt)
                    {
                        // Вывод названия игры в виде ASCII-арта
                        std::cout << std::string(spaces, ' ') << line << std::endl;
                    }
                    std::cout << "\n";
                    return spaces;
                }

                void Play::firstScreen()
                {
                    size_t spaces = nameOfGame();
                    std::vector<std::string> hangmanInstructions =
                    {
                        "",
                        "RULES:",
                        "1.The game begins with a hidden word.",
                        "2.The player can guess one letter at a time. If the guessed letter is part of the secret word,",
                        "  it will be revealed in its corresponding position(s). If the letter is not part of the word,",
                        "  the game will deduct one attempt.",
                        "3.The player's goal is to correctly guess all the letters in the word before running out of attempts.",
                        "4.The number of attempts allowed is limited, typically 7 attempts. Once the player reaches this limit,",
                        "  the game is over, and the hangman figure is complete.",
                        ""
                    };
                    settings.printWithColor(char('c'));
                    for (const auto& line : hangmanInstructions)
                    {
                        // Вывод инструкций для игры "Виселица"
                        std::cout << std::string(spaces / 3, ' ') << line << std::endl;
                    }

                    std::vector<std::string> tips =
                    {
                        "TIPS:",
                        "1.All the words used in this version of the Hangman game are names of countries.",
                        "2.Use common country names to make the game more enjoyable and accessible.",
                        ""
                    };
                    settings.printWithColor(char('g'));
                    for (const auto& line : tips)
                    {
                        // Вывод советов для успешной игры
                        std::cout << std::string(spaces / 3, ' ') << line << std::endl;
                    }

                    std::vector<std::string> endInstruction =
                    {
                        "Remember, the Hangman game is a fun way to test players' vocabulary and deduction skills while",
                        "learning about different countries.",
                        "Enjoy playing and have fun guessing the secret country names!"
                    };
                    settings.printWithColor(char('i'));
                    for (const auto& line : endInstruction)
                    {
                        // Вывод завершающих инструкций и ожидание нажатия Enter
                        std::cout << std::string(spaces / 3, ' ') << line << std::endl;
                    }
                    settings.printWithColor(char('j'));
                    std::cout << "\n\n" << std::string(spaces / 3, ' ') << "PRESS ENTER TO CONTINUE...";
                    settings.printWithColor(char('a'));
                    settings.hideConsoleCursor();
                    while (std::cin.get() != '\n') {} // Wait for Enter key press
                    settings.clearScreen();
                }

                void Play::secondScreen()
                {
                    size_t spaces = nameOfGame();
                    std::vector<std::string> end =
                    {
                        "",
                        "Here's the end of the game...!",
                        "",
                        "Remember, the Hangman game is a fun way to test players' vocabulary and deduction skills while",
                        "learning about different countries.",
                        "",
                        "Thank you for playing the Hangman game and exploring various countries around the world.",
                        "Your word-guessing prowess can save the Hangman from his perilous fate again!",
                        "",
                        "We hope you enjoyed the game and found it both entertaining and educational.",
                        "Challenge yourself to guess more countries and expand your knowledge.",
                        "",
                        "Have a great day and happy exploring!"
                    };
                    settings.printWithColor(char('g'));
                    for (const auto& line : end)
                    {
                        // Вывод сообщения об окончании игры и благодарности за участие
                        std::cout << std::string(spaces / 3, ' ') << line << std::endl;
                    }
                    settings.printWithColor(char('j'));
                    std::cout << "\n\n" << std::string(spaces / 3, ' ') << "PRESS ENTER TO END...";
                    settings.printWithColor(char('a'));
                    settings.hideConsoleCursor();
                    // Ожидание нажатия Enter
                    while (std::cin.get() != '\n') {}
                }

                void Play::playGame()
                {
                    firstScreen();

                    // Захват времени начала перед началом игрового цикла
                    auto startTime = std::chrono::high_resolution_clock::now();
                    std::chrono::seconds::rep duration = 0;

                    // Запуск игрового цикла
                    while (!game.isGameOver())
                    {
                        // Вычисление прошедшего времени во время игры
                        auto currentTime = std::chrono::high_resolution_clock::now();
                        duration = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

                        settings.clearScreen();
                        settings.printWithColor(char('b'));
                        nameOfGame();
                        game.drawHangman();
                        std::cout << "\n\n";
                        settings.printWithColor(char('g'));
                        game.displayGameStatus();

                        char guess;

                        do
                        {
                            // Отображение состояния игры, ввод пользовательских данных
                            settings.printWithColor(char('g'));
                            settings.showConsoleCursor();
                            std::cout << "Enter your guess: ";
                            settings.printWithColor(char('h'));
                            std::cin >> guess;
                            std::cin.ignore(32767, '\n');

                            guess = std::toupper(guess);
                            if (!std::isalpha(guess))
                            {
                                settings.printWithColor(char('e'));
                                std::cout << "Invalid input. Please enter an English letter." << std::endl;
                                settings.sleepMilliseconds(1000);
                            }
                            else if (game.isLetterAlreadyGuessed(guess))
                            {
                                settings.printWithColor(char('e'));
                                std::cout << "You have already guessed this letter. Try again." << std::endl;
                                settings.sleepMilliseconds(1000);
                            }
                        } while (!std::isalpha(guess) || game.isLetterAlreadyGuessed(guess));

                        if (!game.guessLetter(guess))
                        {
                            settings.hideConsoleCursor();
                            settings.printWithColor(char('e'));
                            std::cout << "Incorrect guess!";
                            settings.sleepMilliseconds(650);
                        }
                        else
                        {
                            settings.hideConsoleCursor();
                            settings.printWithColor(char('i'));
                            std::cout << "Great job! You guessed a correct letter: " << guess << '.';
                            settings.printWithColor(char('g'));
                            settings.sleepMilliseconds(1000);
                        }
                        // Вывод результатов игры, продолжение или завершение игры
                    }
                    settings.clearScreen();
                    nameOfGame();
                    game.drawHangman();
                    settings.printWithColor(char('g'));
                    std::cout << "\n\n";
                    game.displayGameStatus();
                    /// Отображение прошедшего времени во время игры
                    std::cout << "Time: " << duration << " seconds" << std::endl;
                    settings.hideConsoleCursor();

                    if (game.isLetterAlreadyGuessed('_'))
                    {
                        settings.printWithColor(char('f'));
                        std::cout << "\nYou lose! The word was: " << game.getSecretWord() << '.' << std::endl;
                    }
                    else
                    {
                        settings.printWithColor(char('e'));
                        std::cout << "\nCongratulations! You guessed the word: " << game.getSecretWord() << '.' << std::endl;
                    }

                    settings.printWithColor(char('j'));
                    std::cout << "\n" << "PRESS ENTER TO CONTINUE...";
                    settings.printWithColor(char('a'));
                    settings.hideConsoleCursor();
                    while (std::cin.get() != '\n') {} // Wait for Enter key press
                    settings.clearScreen();
                    secondScreen();
                    settings.printWithColor(char('h'));
                    return;
                }
            }
        }
    }
}