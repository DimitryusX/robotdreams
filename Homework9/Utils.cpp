#include <iostream>
#include <string>
#include <cctype>

void breakLine(std::string title, const int symbolLength = 16)
{
    std::cout << std::endl << std::endl;
    for (int i = 0; i < symbolLength; i++) {
        std::cout << "*";
    }

    std::cout << std::endl << "*";

    std::cout << " " << title << " ";

    size_t clearSpace = symbolLength - title.length() - 4;

    for (int i = 0; i < clearSpace; i++) {
        std::cout << " ";
    }

    std::cout << "*" << std::endl;

    for (int i = 0; i < symbolLength; i++) {
        std::cout << "*";
    }
    std::cout << std::endl << std::endl;
}

void translateArray(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] > 0)
        {
            numbers[i] *= 2;
        }
        else if (numbers[i] < 0)
        {
            numbers[i] = 0;
        }
    }
}

void toUppercase(char str[])
{
    for (int i = 0; i < sizeof(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
}

bool isPalindrom(std::string word)
{
    std::string reversed;

    int i = 0;

    for (int i = word.length() - 1; i >= 0; --i) {
        reversed += word[i];
    }

    return word == reversed;
}

void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount)
{
    for (int i = 0; str[i] != '\0'; i++) {
        char currentChar = std::tolower(str[i]);

        if (std::isalpha(currentChar)) {
            switch (currentChar) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowelsCount++;
                    break;
                default:
                    consonantsCount++;
            }
        }
    }
}

bool isEqual(const char str1[], const char str2[]) 
{
    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {

        char test1 = str1[i];
        char test2 = str2[i];

        if (str1[i] != str2[i])
        {
            return false;
        }
    }

    return true;
}