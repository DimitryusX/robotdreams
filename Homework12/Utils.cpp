#include <iostream>
#include "utils.h"

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int partition(int arr[][COLS], const int index, const int low, const int high, const SortingDirection direction) {
    int pivot = (direction == SortingDirection::ByRows) ? arr[index][high] : arr[high][index];
    int pointerIdx = low - 1;

    for (int j = low; j <= high - 1; j++) {
        int temp = (direction == SortingDirection::ByRows) ? arr[index][j] : arr[j][index];

        if (temp <= pivot) {
            pointerIdx++;

            if (direction == SortingDirection::ByRows) {
                std::swap(arr[index][pointerIdx], arr[index][j]);
            }
            else {
                std::swap(arr[pointerIdx][index], arr[j][index]);
            }
        }
    }

    pointerIdx++;

    if (direction == SortingDirection::ByRows) {
        std::swap(arr[index][pointerIdx], arr[index][high]);
    }
    else {
        std::swap(arr[pointerIdx][index], arr[high][index]);
    }

    return pointerIdx;
}

void quickSort(int arr[][COLS], const int index, const int low, const int high, const SortingDirection direction) {
    if (low < high) {
        int pivot = partition(arr, index, low, high, direction);

        quickSort(arr, index, low, pivot - 1, direction);
        quickSort(arr, index, pivot + 1, high, direction);
    }
}

void sort(int arr[][COLS], const int rows, const int cols, const SortingDirection direction) {
    if (direction == SortingDirection::ByRows) {
        for (int i = 0; i < rows; i++) {
            quickSort(arr, i, 0, cols - 1, direction);
        }
    }
    else if (direction == SortingDirection::ByColumns) {
        for (int i = 0; i < cols; i++) {
            quickSort(arr, i, 0, rows - 1, direction);
        }
    }
    else {
        std::cerr << "Error: Unknown sorting direction." << std::endl;
    }
}