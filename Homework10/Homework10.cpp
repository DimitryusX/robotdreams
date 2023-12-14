#include <iostream>
#include "utils.h"

int main()
{
    std::cout << "Welcome to homework 9!" << std::endl;

    std::cout << std::endl << "Task #1" << std::endl << std::endl;

    int a = 5;
    int b = 10;

    std::cout << "Start A is " << a << " and B is " << b << "." << std::endl;

    std::cout << "Processing ..." << std::endl;
    swap(&a, &b);

    std::cout << "And now A is " << a << " and B is " << b << "." << std::endl;

    std::cout << "Processing again ..." << std::endl;
    swap(a, b);

    std::cout << "And now A is " << a << " and B is " << b << "." << std::endl;

    std::cout << std::endl << "Task #2" << std::endl << std::endl;

    const int size = 5;
    double arrayOfNumbers[size] = { 1.2, 3.4, 5.6, 7.8, 9.1 };
    double sum = 0.0;

    calculateSum(arrayOfNumbers, size, sum);

    std::cout << "Sum of array " << sum << "." << std::endl;

    std::cout << std::endl << "Task #3" << std::endl << std::endl;

    int arrayOfNumbers2[size] = { 1, 2, 3, 4, 5 };
    int searchNumber = 3;

    std::cout << "Let's find " << searchNumber << " in array." << std::endl;

    std::cout << "Processing ..." << std::endl;
    bool searchResult = find(arrayOfNumbers2, size, searchNumber);

    std::cout << "Result: " << std::boolalpha << searchResult << std::endl;

    searchNumber = 10;
    std::cout << "Now let's find " << searchNumber << " in array." << std::endl;

    std::cout << "Processing ..." << std::endl;
    searchResult = find(arrayOfNumbers2, size, searchNumber);

    std::cout << "Result: " << std::boolalpha << searchResult << std::endl;
}