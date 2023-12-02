#include <iostream>

enum class Month {
    January = 1,
    February = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
};

int main()
{
    std::cout << "Welcome to Homework4!" << std::endl;

    int number1;
    int number2;
    int number3;

    std::cout << "Please, enter three numbers: " << std::endl;
    std::cin >> number1;
    std::cin >> number2;
    std::cin >> number3;

    int maxNumber = (number1 > number2) ? number1 : number2;
    maxNumber = (maxNumber > number3) ? maxNumber : number3;

    std::cout << "Max number is: " << maxNumber << std::endl;

    std::cout << "Task #2" << std::endl;

    std::cout << "Please, enter two numbers: " << std::endl;
    std::cin >> number1;
    std::cin >> number2;

    std::cout << "Min number is: " << ((number1 < number2) ? number1 : number2) << std::endl;

    std::cout << "Task #3" << std::endl;

    std::cout << "Please, enter one numbers: " << std::endl;
    std::cin >> number1;

    std::cout << "Is this number divisible by 5 and 11 without a remainder ? " << ((number1 % 5 == 0 && number1 % 11 == 0) ? "YES" : "NO") << std::endl;

    std::cout << "Task #4" << std::endl;

    std::cout << "Please, enter three numbers (the value of the angles of the triangle): " << std::endl;

    std::cin >> number1;
    std::cin >> number2;
    std::cin >> number3;

    bool isOneOfEqualZero = number1 == 0 || number2 == 0 || number3 == 0;

    if ((number1 + number2 + number3) == 180 && !isOneOfEqualZero) {
        std::cout << "The values of the angles form a triangle" << std::endl;
    }
    else {
        std::cout << "The values of the angles do NOT form a triangle" << std::endl;
    }

    std::cout << "Task #5" << std::endl;

    std::cout << "Please, enter number of month: " << std::endl;
    std::cin >> number1;

    Month monthNumber = static_cast<Month>(number1);

    switch (monthNumber)
    {
    case Month::January:
        std::cout << "January" << std::endl;
        break;
    case Month::February:
        std::cout << "February" << std::endl;
        break;
    case Month::March:
        std::cout << "March" << std::endl;
        break;
    case Month::April:
        std::cout << "April" << std::endl;
        break;
    case Month::May:
        std::cout << "May" << std::endl;
        break;
    case Month::June:
        std::cout << "June" << std::endl;
        break;
    case Month::July:
        std::cout << "July" << std::endl;
        break;
    case Month::August:
        std::cout << "August" << std::endl;
        break;
    case Month::September:
        std::cout << "September" << std::endl;
        break;
    case Month::October:
        std::cout << "October" << std::endl;
        break;
    case Month::November:
        std::cout << "November" << std::endl;
        break;
    case Month::December:
        std::cout << "December" << std::endl;
        break;
    default:
        std::cout << "Error, unknown!" << std::endl;
        break;
    }

    std::cout << "Task #6" << std::endl;

    std::cout << "Please, enter number of month: " << std::endl;
    std::cin >> number1;

    monthNumber = static_cast<Month>(number1);

    switch (monthNumber)
    {
    case Month::January:
    case Month::February:
    case Month::December:
        std::cout << "Winter" << std::endl;
        break;
    case Month::March:
    case Month::April:
    case Month::May:
        std::cout << "Spring" << std::endl;
        break;
    case Month::June:
    case Month::July:
    case Month::August:
        std::cout << "Summer" << std::endl;
        break;
    case Month::September:
    case Month::October:
    case Month::November:
        std::cout << "Autumn" << std::endl;
        break;
    default:
        std::cout << "Error, unknown!" << std::endl;
        break;
    }
}