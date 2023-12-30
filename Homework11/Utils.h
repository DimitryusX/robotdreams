#pragma once

const size_t ROWS = 4;
const size_t COLS = 5;

enum class SortingDirection {
    ascending,
    descending
};

bool find(const int arr_2d[ROWS][COLS], const int toFind);
bool find(const int* arr_2d, const size_t size, const int toFind);
bool find(const int* arr_2d, const size_t rows, const size_t cols, const int toFind);
bool isSorted(const int arr[], int size, SortingDirection direction);