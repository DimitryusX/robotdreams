#include <iostream>
#include <ctype.h>

unsigned long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    std::cout << "Welcome to Homework 5!" << std::endl;

    std::cout << "Task #1" << std::endl;

    int startNumber, stepNumber, finishNumber, currentNumber;

    bool isInputCorrect = false;

    do {
        std::cout << "Please, enter start number: ";
        std::cin >> startNumber;
        std::cout << "Please, input step number: ";
        std::cin >> stepNumber;
        std::cout << "Please, enter the number of elements: ";
        std::cin >> finishNumber;

        isInputCorrect = stepNumber > 0;

        if (!isInputCorrect) {
            std::cout << "Incorrect input ! Please, try again ..." << std::endl;
        }
    } while (!isInputCorrect);

    currentNumber = startNumber;
    finishNumber += startNumber;

    for (int i = startNumber; i < finishNumber; i++) 
    {
        currentNumber += stepNumber;
        std::cout << currentNumber << " ";
    }

    std::cout << std::endl;

    std::cout << "Task #2" << std::endl;

    int number1;

    std::cout << "Please, input index of fibonacci number: ";
    std::cin >> number1;

    std::cout << "Fibonacci number " << fibonacci(number1 + 1) << " has index " << number1 << std::endl;

    std::cout << "Task #3" << std::endl;

    std::cout << "Please, input number: ";

    do {
        std::cin >> number1;
    } while (number1 < 0);

    unsigned long factorial = 1;

    for (int i = 1; i <= number1; i++)
    {
        factorial *= i;
    }

    std::cout << factorial << std::endl;

    std::cout << "Task #4" << std::endl;

    int width, height;

    std::cout << "Please, input width: ";
    std::cin >> width;
    std::cout << "Please, input height: ";
    std::cin >> height;

    std::cout << std::endl;

    const double step = static_cast<double>(width) / height;
    double widthThreshold = width;

    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j < widthThreshold; j++)
        {
            std::cout << "*";
        }

        widthThreshold -= step;

        std::cout << std::endl;
    }

    std::cout << std::endl;

    // Reset
    widthThreshold = 0;

    for (int i = 0; i <= height; i++) {
        
        for (int j = 0; j < widthThreshold; j++)
        {
            std::cout << "*";
        }

        widthThreshold += step;

        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
        {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        for (int k = 0; k < i; k++) {
            std::cout << " ";
        }

        for (int j = 0; j < width; j++)
        {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    bool startSymbol = false;

    // Reset
    widthThreshold = 0;

    for (int i = 0; i <= height; i++) {

        bool symbol = startSymbol = !startSymbol;

        for (int j = 0; j < widthThreshold; j++)
        {
            std::cout << symbol;
            symbol = !symbol;
        }

        widthThreshold += step;
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Task #5" << std::endl;

    char symbol;
    int sum = 0;

    do {
        std::cout << "Please, input any symbol or dot for exit: ";
        std::cin >> symbol;

        if (isalpha(symbol)) {
            if (symbol >= 'a' && symbol <= 'z') {
                std::cout << static_cast<char>(std::toupper(symbol)) << std::endl;
            }
        }
        else if (isdigit(symbol)) {
            sum += symbol - '0';
            std::cout << sum << std::endl;
        }
        else if (symbol == '.') {
            std::cout << "Bye ..." << std::endl;
            break;
        } 
        else {
            std::cout << "Uncorrect symbol" << std::endl;
        }
    } while (true);
}
