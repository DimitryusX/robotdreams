#pragma once

const int SIZE = 5;
const int ROWS = 3;
const int COLS = 3;

enum class SortingDirection {
    ByRows,
    ByColumns
};

void bubbleSort(int arr[], int size);
int partition(int arr[][COLS], const int index, const int low, const int high, const SortingDirection direction);
void quickSort(int arr[][COLS], const int index, const int low, const int high, const SortingDirection direction);
void sort(int arr[][COLS], const int rows, const int cols, const SortingDirection direction);