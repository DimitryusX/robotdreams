#include <iostream>
#include "Utils.h"
#include "Loop.h"
#include "Recursion.h"

int main()
{
    std::cout << "Homework 8!\n";

    int count;

    std::cout << "How many numbers you want check ?" << std::endl;

    do {
        std::cin >> count;
    } while (count <= 0);

    numbersChecker(count);

    printLine(12);

    int inputNumberOfFactorial;
    std::cout << "What number of factorial you want to know ?" << std::endl;

    do {
        std::cin >> inputNumberOfFactorial;
    } while (inputNumberOfFactorial < 0);

    int factorial = 0;

    factorial = factorialLoop(inputNumberOfFactorial);
    std::cout << "Calculation by loop: " << factorial << std::endl;

    factorial = fatorialRecursion(inputNumberOfFactorial);
    std::cout << "Calculation by recursive function: " << factorial;

    printLine(12);

    int inputCountOfNaturalNumbers;
    std::cout << "How many natural numbers you want see ?" << std::endl;

    do {
        std::cin >> inputCountOfNaturalNumbers;
    } while (inputCountOfNaturalNumbers <= 0);

    std::cout << "Printing by loop: " << std::endl;
    printNaturalNumbersLoop(inputCountOfNaturalNumbers);

    std::cout << "Printing by recursion: " << std::endl;
    printDecreaseNaturalNumbersRecursion(inputCountOfNaturalNumbers);
    printIncreaseNaturalNumbersRecursion(inputCountOfNaturalNumbers);

    printLine(12);

    std::cout << "Bye ..." << std::endl;
}