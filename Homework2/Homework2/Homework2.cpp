#include <iostream>
#include <iomanip>

enum class WeekDay {
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7
};

int main()
{
    std::cout << "Welcome to second homework!" << std::endl;

    int number1;
    int number2;

    std::cout << "Input first number: " << std::endl;
    std::cin >> number1;

    std::cout << "Input second number: " << std::endl;
    std::cin >> number2;

    number1 = number1 ^ number2;
    number2 = number1 ^ number2;
    number1 ^= number2;

    std::cout << "Now we changed variables values!" << std::endl;
    std::cout << "Number one is: " << number1 << ", and number two is: " << number2 << std::endl;

    std::cout << "Ok, next step ..." << std::endl;

    double number3 = 123.456789123456789;

    std::cout << "Number in double type: " << number3 << std::endl;
    std::cout << "Number in int type: " << static_cast<int>(number3) << std::endl;
    std::cout << "Number align to right and fill string length:" << std::endl;
    std::cout << std::setw(20) << std::right << std::setfill('$') << number3 << std::endl;

    std::cout << "Ok, next step ..." << std::endl;

    std::cout << std::setprecision(2) << number3 << std::endl;
    std::cout << std::setprecision(5) << number3 << std::endl;
    std::cout << std::setprecision(10) << number3 << std::endl;

    std::cout << "Ok, next step ..." << std::endl;

    std::cout << static_cast<int>(WeekDay::Monday) << std::endl;
    std::cout << static_cast<int>(WeekDay::Tuesday) << std::endl;
    std::cout << static_cast<int>(WeekDay::Wednesday) << std::endl;
    std::cout << static_cast<int>(WeekDay::Thursday) << std::endl;
    std::cout << static_cast<int>(WeekDay::Friday) << std::endl;
    std::cout << static_cast<int>(WeekDay::Saturday) << std::endl;
    std::cout << static_cast<int>(WeekDay::Sunday) << std::endl;

    int number4;

    std::cout << "Ok, next step ..." << std::endl;
    std::cout << "Please, input any number:" << std::endl;
    std::cin >> number4;

    std::cout << "Your number in bool type is: " << std::boolalpha << static_cast<bool>(number4) << std::endl;
}