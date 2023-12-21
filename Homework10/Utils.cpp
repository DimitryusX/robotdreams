#include <iostream>

void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

bool calculateSum(const double* arr, int arrSize, double& sum) {
    if (arrSize == 0) {
        return false;
    }

    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];
    }

    return true;
}

bool find(const int* arr, int size, int elem) {
    if (size == 0) {
        return false;
    }

    const int* finish = arr + size;

    for (; arr < finish; arr++) {
        if (*arr == elem) {
            return true;
        }
    }

    return false;
}