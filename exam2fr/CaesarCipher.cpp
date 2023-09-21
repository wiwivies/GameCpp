#include "CaesarCipher.h"

namespace ProjectGame
{
    namespace usingForGameAssembly
    {
        namespace WordsEncryption
        {
            std::string CaesarCipher::encrypt(const std::string& plainText) const
            {
                // ������� ����� �������� ������, � ������� ����� ��������� ����������
                std::string encryptedText = plainText;
                // ��������� ������� ������ � ����������� �� ����������� ������
                char base = shift >= 0 ? 'A' : 'Z';

                // ������-������� ��� ���������� ����� �����
                auto encryptLetter = [&](char letter)
                {
                    if (std::isalpha(letter))
                    {
                        char baseLetter = std::isupper(letter) ? 'A' : 'a';
                        // ��������� ����� � ��������� ������������� ����� � ������ ����� �������� (26 ��������)
                        return static_cast<char>((letter - baseLetter + shift + 26) % 26 + baseLetter);
                    }
                    // ���� ������ �� �������� ������, ���������� ��� ��� ���������
                    return letter;
                };

                // ��������� ������-������� encryptLetter � ������ ����� � ������, ����� ����������� �����
                std::transform(encryptedText.begin(), encryptedText.end(), encryptedText.begin(), encryptLetter);
                return encryptedText;
            }

            std::string CaesarCipher::decrypt(const std::string& encryptedText) const
            {
                // ������� ������ ����� ������ ��� ������������ � ������� ��������� ������
                CaesarCipher decryptionCipher(26 - shift);
                // ��������� ������������� ����� � ������� ������ encrypt ������ CaesarCipher
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
                        // ��������� ����� � ������� ������ decrypt ������ CaesarCipher
                        std::string decryptedWord = cipher.decrypt(word);
                        // ��������� ������������� ����� � ������
                        words.push_back(decryptedWord);
                    }
                    file.close();
                }
                return words;
            }

            // ������� ��� ������������ ����� � ������ ��� � ���� � ����� ������
            void CaesarCipher::writeWordToFile(const std::string& filename, const std::string& word) const
            {
                // ������� ���� ��� ������ � ������ ����������
                std::ofstream file(filename, std::ios::app);
                if (file.is_open())
                {
                    // ����������� �����
                    std::string encryptedWord = encrypt(word);
                    file << encryptedWord;
                    // �������� ������ ����� ������, ����� ������� �� ��������� ������
                    file << '\n';
                    file.close();
                }
            }

            // ����� ��� ������ ������ ����� �� ������ �����, ���������� �� 3 � ������ ������������� ����� � ������ ����
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
                    // ����������� ������ � ������� ������� CaesarCipher
                    std::string encryptedCountry = encrypt(country);
                    // �������� ������������� ������ � ����, ������������� ������ ����������� �������� ����� ������
                    outputFile << encryptedCountry << '\n';
                }

                inputFile.close();
                outputFile.close();
            }
        }
    }
}