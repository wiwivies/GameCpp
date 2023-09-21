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
                // ����������� ��� ������������� ������� CaesarCipher � ������������ ��������� ������
                CaesarCipher(int shiftValue) : shift(shiftValue) {}
                // ���������� ������ � ������� ����� ������
                std::string encrypt(const std::string& plainText) const;
                // ������������ �������������� ������ � ������� ����� ������
                std::string decrypt(const std::string& encryptedText) const;
                // ������ ���� �� ���������� ����� � ���������� �� � ������� ����� ������
                std::vector<std::string> readWordsFromFile(const std::string& filename, int shift);
                // ������� ��� ������������ ����� � ������ ��� � ���� � ����� ������
                void writeWordToFile(const std::string& filename, const std::string& word) const;
                // ����� ��� ������ ������ ����� �� ������ �����, ���������� �� 3 � ������ ������������� ����� � ������ ����
                void encryptCountriesFromFile(const std::string& inputFilename, const std::string& outputFilename) const;
            };
        }
    }
}