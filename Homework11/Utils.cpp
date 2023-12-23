#include <iostream>
#include "Utils.h"

bool find(const int arr_2d[ROWS][COLS], const int toFind) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (toFind == arr_2d[i][j]) {
                return true;
            }
        }
    }

    return false;
}

bool find(const int* arr_2d, const size_t size, const int toFind) {
    for (int i = 0; i < size; i++) {
        if (toFind == *(arr_2d + i)) {
            return true;
        }
    }

    return false;
}

bool find(const int* arr_2d, const size_t rows, const size_t cols, const int toFind) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (toFind == *(arr_2d + i * cols + j)) {
                return true;
            }
        }
    }

    return false;
}

bool isSorted(const int arr[], const int size, SortingDirection direction)
{
    if (size <= 1) {
        return true;
    }

    if (direction == SortingDirection::ascending) {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
    }
    else if (direction == SortingDirection::descending) {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                return false;
            }
        }
    }
    else {
        std::cerr << "Error: Unknown sorting direction." << std::endl;
        return false;
    }

    return true;
}
