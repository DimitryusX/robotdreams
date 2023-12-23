#include <iostream>
#include "utils.h"

int main()
{
    std::cout << "Welcome to homework 11!" << std::endl;

    std::cout << std::endl << "Task #1" << std::endl << std::endl;

    int arrayOfNumbers[ROWS][COLS]{
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    const size_t size = sizeof(arrayOfNumbers) / sizeof(int);

    int numberToFind = 10;
    std::cout << "Let's find number " << numberToFind << std::endl;
    bool result = find(&arrayOfNumbers[0][0], size, numberToFind);
    std::cout << "Search result: " << std::boolalpha << result << std::endl;

    numberToFind = 25;
    std::cout << "Let's find number " << numberToFind << std::endl;
    result = find(&arrayOfNumbers[0][0], ROWS, COLS, numberToFind);
    std::cout << "Search result: " << std::boolalpha << result << std::endl;

    numberToFind = 16;
    std::cout << "Let's find number " << numberToFind << std::endl;
    result = find(arrayOfNumbers, numberToFind);
    std::cout << "Search result: " << std::boolalpha << result << std::endl;

    std::cout << std::endl << "Task #2" << std::endl << std::endl;

    int ascendingArray[COLS]{ 1, 2, 3, 4, 5 };
    int descentingArray[COLS]{ 5, 4, 3, 2, 1 };

    bool isSorderdResult = isSorted(ascendingArray, COLS, SortingDirection::ascending);
    std::cout << "Is array sorted by ascending: " << std::boolalpha << isSorderdResult << std::endl;

    isSorderdResult = isSorted(descentingArray, COLS, SortingDirection::ascending);
    std::cout << "Is array sorted by ascending: " << std::boolalpha << isSorderdResult << std::endl;

    isSorderdResult = isSorted(descentingArray, COLS, SortingDirection::descending);
    std::cout << "Is array sorted by descending: " << std::boolalpha << isSorderdResult << std::endl;

    isSorderdResult = isSorted(ascendingArray, COLS, SortingDirection::descending);
    std::cout << "Is array sorted by descending: " << std::boolalpha << isSorderdResult << std::endl;

    std::cout << std::endl << "Task #3" << std::endl << std::endl;

    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            std::cout << arrayOfNumbers[j][COLS - i - 1] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    bool reverse = false;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int position = reverse ? (COLS - j - 1) : j;
            std::cout << arrayOfNumbers[ROWS - i - 1][position] << " ";
        }

        reverse = !reverse;

        std::cout << std::endl;
    }

    std::cout << std::endl << "Bye ... " << std::endl;
}