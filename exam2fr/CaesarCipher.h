#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "InitialComposition.h"

namespace ProjectGame
{
    namespace usingForGameAssembly
    {
        namespace WordsEncryption
        {
            class CaesarCipher
            {
            private:
                int shift;
            public:
                CaesarCipher() : shift(0) { }
                // Конструктор для инициализации объекта CaesarCipher с определенным значением сдвига
                CaesarCipher(int shiftValue) : shift(shiftValue) {}
                // Шифрование текста с помощью шифра Цезаря
                std::string encrypt(const std::string& plainText) const;
                // Дешифрование зашифрованного текста с помощью шифра Цезаря
                std::string decrypt(const std::string& encryptedText) const;
                // Чтение слов из указанного файла и дешифровка их с помощью шифра Цезаря
                std::vector<std::string> readWordsFromFile(const std::string& filename, int shift);
                // Функция для зашифрования слова и записи его в файл с новой строки
                void writeWordToFile(const std::string& filename, const std::string& word) const;
                // Метод для чтения списка стран из одного файла, шифрования на 3 и записи зашифрованных стран в другой файл
                void encryptCountriesFromFile(const std::string& inputFilename, const std::string& outputFilename) const;
            };
        }
    }
}