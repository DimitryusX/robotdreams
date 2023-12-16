#include <iostream>
#include "Utils.h"

int main()
{
    std::cout << "Welcome to homework 12!" << std::endl;

    std::cout << std::endl << "Task #1" << std::endl << std::endl;

    const int SIZE = 5;

    int arrayOfNumbers[SIZE]{ 5, 1, 9, 7, 3 };

    std::cout << "Original array: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << arrayOfNumbers[i] << " ";
    }

    std::cout << std::endl;

    bubbleSort(arrayOfNumbers, SIZE);

    std::cout << "Sorted array after bubble sort: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << arrayOfNumbers[i] << " ";
    }

    std::cout << std::endl;

    std::cout << std::endl << "Task #2" << std::endl << std::endl;

    const int ROWS = 3;
    const int COLS = 3;

    int arr[ROWS][COLS]{
        {1, 5, 4},
        {3, 8, 6},
        {9, 5, 1}
    };

    std::cout << "Original array:" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    sort(arr, ROWS, COLS, SortingDirection::ByRows);

    std::cout << std::endl << "Sorted array by rows:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    int arr2[ROWS][COLS]{
        {1, 5, 4},
        {3, 8, 6},
        {9, 5, 1}
    };

    std::cout << "Original array:" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << arr2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    sort(arr2, ROWS, COLS, SortingDirection::ByColumns);

    std::cout << std::endl << "Sorted array by columns:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << arr2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "Bye ... " << std::endl;
}