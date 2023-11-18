#include <iostream>

int main()
{
    std::cout << "Welcome to Homework3 !" << std::endl;

    std::cout << "First task." << std::endl;
    int timeInSeconds;

    std::cout << "Please, input your time in seconds: ";
    std::cin >> timeInSeconds;

    int seconds = timeInSeconds % 60;
    int hours = timeInSeconds / 60 / 60;
    int minutes = timeInSeconds / 60 % 60;

    std::cout << "Hours: " << hours << ", minutes: " << minutes << ", seconds: " << seconds << std::endl;

    std::cout << "Second task." << std::endl;

    int number1;
    int number2;
    int number3;

    std::cout << "Please, input three numbers: " << std::endl;
    std::cin >> number1;
    std::cin >> number2;
    std::cin >> number3;

    int sumOfNumbers = number1 + number2 + number3;

    std::cout << "Sum of numbers is - " << sumOfNumbers << std::endl;
    std::cout << "Avarage of numbers is - " << static_cast<double>(sumOfNumbers) / 3 << std::endl;
    std::cout << "Product of numbers is - " << number1 * number2 * number3 << std::endl;

    std::cout << "First number is " << (number1 > number2 ? "greater" : "less") << " than second" << std::endl;
    std::cout << "Second number is " << (number2 > number3 ? "greater" : "less") << " than last" << std::endl;

    std::cout << "Third task." << std::endl;
    std::cout << "Please, input two numbers: " << std::endl;
    std::cin >> number1;
    std::cin >> number2;

    bool isLessThan = number1 < number2;
    bool isEqual = number1 == number2;
    bool isMoreThan = number1 > number2;
    bool isLessOrEqual = number1 <= number2;

    std::cout << "Is number1 less than number2 ? " << std::boolalpha << isLessThan << std::endl;
    std::cout << "Is number1 equal number2 ? " << std::boolalpha << isEqual << std::endl;
    std::cout << "Is number1 more than number2 ? " << std::boolalpha << isMoreThan << std::endl;
    std::cout << "Is number1 less or equal number2 ? " << std::boolalpha << isLessOrEqual << std::endl;

    std::cout << "Fourth task." << std::endl;
    std::cout << "Please, input the width and height of the rectangle: " << std::endl;
    std::cin >> number1;
    std::cin >> number2;

    std::cout << "Perimeter of rectangle is - " << (number1 + number2) * 2 << std::endl;
    std::cout << "Square of rectangle is - " << number1 * number2 << std::endl;

    std::cout << "Fifth task." << std::endl;
    int radius;
    std::cout << "Please, input the radius of the circle: " << std::endl;
    std::cin >> radius;

    double pi = 2 * acos(0.0);
    std::cout << "Length of the circle is - " << pi * radius * 2 << std::endl;
    std::cout << "Square of the circle is - " << pi * radius * radius << std::endl;
}
