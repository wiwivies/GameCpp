#include "CaesarCipher.h"

namespace ProjectGame
{
    namespace usingForGameAssembly
    {
        namespace WordsEncryption
        {
            std::string CaesarCipher::encrypt(const std::string& plainText) const
            {
                // Создаем копию входного текста, в которой будем выполнять шифрование
                std::string encryptedText = plainText;
                // Вычисляем базовый символ в зависимости от направления сдвига
                char base = shift >= 0 ? 'A' : 'Z';

                // Лямбда-функция для шифрования одной буквы
                auto encryptLetter = [&](char letter)
                {
                    if (std::isalpha(letter))
                    {
                        char baseLetter = std::isupper(letter) ? 'A' : 'a';
                        // Выполняем сдвиг и вычисляем зашифрованную букву с учетом длины алфавита (26 символов)
                        return static_cast<char>((letter - baseLetter + shift + 26) % 26 + baseLetter);
                    }
                    // Если символ не является буквой, возвращаем его без изменений
                    return letter;
                };

                // Применяем лямбда-функцию encryptLetter к каждой букве в строке, чтобы зашифровать текст
                std::transform(encryptedText.begin(), encryptedText.end(), encryptedText.begin(), encryptLetter);
                return encryptedText;
            }

            std::string CaesarCipher::decrypt(const std::string& encryptedText) const
            {
                // Создаем объект шифра Цезаря для дешифрования с помощью обратного сдвига
                CaesarCipher decryptionCipher(26 - shift);
                // Дешифруем зашифрованный текст с помощью метода encrypt класса CaesarCipher
                return decryptionCipher.encrypt(encryptedText);
            }

            std::vector<std::string> CaesarCipher::readWordsFromFile(const std::string& filename, int shift)
            {
                std::vector<std::string> words;
                std::ifstream file(filename);
                if (file.is_open())
                {
                    std::string word;
                    while (file >> word)
                    {
                        CaesarCipher cipher(shift);
                        // Дешифруем слово с помощью метода decrypt класса CaesarCipher
                        std::string decryptedWord = cipher.decrypt(word);
                        // Добавляем дешифрованное слово в вектор
                        words.push_back(decryptedWord);
                    }
                    file.close();
                }
                return words;
            }

            // Функция для зашифрования слова и записи его в файл с новой строки
            void CaesarCipher::writeWordToFile(const std::string& filename, const std::string& word) const
            {
                // Открыть файл для записи в режиме добавления
                std::ofstream file(filename, std::ios::app);
                if (file.is_open())
                {
                    // Зашифровать слово
                    std::string encryptedWord = encrypt(word);
                    file << encryptedWord;
                    // Записать символ новой строки, чтобы перейти на следующую строку
                    file << '\n';
                    file.close();
                }
            }

            // Метод для чтения списка стран из одного файла, шифрования на 3 и записи зашифрованных стран в другой файл
            void CaesarCipher::encryptCountriesFromFile(const std::string& inputFilename, const std::string& outputFilename) const
            {
                std::ifstream inputFile(inputFilename);
                std::ofstream outputFile(outputFilename);

                if (!inputFile.is_open())
                {
                    std::cout << "Error opening input file: " << inputFilename << std::endl;
                    return;
                }

                if (!outputFile.is_open())
                {
                    std::cout << "Error opening output file: " << outputFilename << std::endl;
                    inputFile.close();
                    return;
                }

                std::string country;
                while (std::getline(inputFile, country))
                {
                    // Зашифровать страну с помощью объекта CaesarCipher
                    std::string encryptedCountry = encrypt(country);
                    // Записать зашифрованную страну в файл, зашифрованные страны разделяются символом новой строки
                    outputFile << encryptedCountry << '\n';
                }

                inputFile.close();
                outputFile.close();
            }
        }
    }
}