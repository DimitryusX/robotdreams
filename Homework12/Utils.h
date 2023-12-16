#pragma once

enum class SortingDirection {
    ByRows,
    ByColumns
};

void bubbleSort(int arr[], int size);
int partition(int arr[][3], int index, int low, int high, SortingDirection direction);
void quickSort(int arr[][3], int index, int low, int high, SortingDirection direction);
void sort(int arr[][3], int rows, int cols, SortingDirection direction);