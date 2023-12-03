#include <iostream>
#include <string>
#include "Utils.h"

const int numbersArraySize = 10;
const char charsArraySize = 5;
const int stringMaxSize = 20;

int main()
{
    std::cout << "Homework 9!\n";

    breakLine("Task #1");

    std::cout << "Please, input 10 numbers: " << std::endl;

    int numbers[numbersArraySize]{};
    int i = 0;

    do {
        std::cin >> numbers[i];
        i++;
    } while (i < numbersArraySize);

    std::cout << "Processing ... " << std::endl;

    translateArray(numbers, numbersArraySize);

    breakLine("Task #2");

    char stringForUppercase[stringMaxSize]{};

    // Should clear input 
    std::cin.getline(stringForUppercase, stringMaxSize);

    std::cout << "Enter string for uppercase: ";
    std::cin.getline(stringForUppercase, stringMaxSize);

    toUppercase(stringForUppercase);

    breakLine("Task #3");

    std::string word;

    std::cout << "Enter word for palindrom test: ";
    std::getline(std::cin, word);
    
    std::cout << "Is correct: " << std::boolalpha << isPalindrom(word) << std::endl;

    breakLine("Task #4");

    char str[stringMaxSize]{};

    std::cout << "Enter word for count vowels and consonants: ";
    std::cin.getline(str, stringMaxSize);

    int vowelsCount = 0;
    int consonantsCount = 0;

    parseStringLetters(str, vowelsCount, consonantsCount);

    std::cout << "Vowels count: " << vowelsCount << std::endl;
    std::cout << "Consonants count: " << consonantsCount << std::endl;

    breakLine("Task #5");

    char str1[stringMaxSize]{};
    char str2[stringMaxSize]{};

    std::cout << "Enter first work for compare: ";
    std::cin.getline(str1, stringMaxSize);

    std::cout << "Enter second work for compare: ";
    std::cin.getline(str2, stringMaxSize);

    std::cout << "Is this string equal: " << std::boolalpha << isEqual(str1, str2) << std::endl;
}