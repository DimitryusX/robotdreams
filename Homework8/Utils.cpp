#include <iostream>

void numbersChecker(int count) 
{
	std::cout << "Let's start input numbers: " << std::endl;
	int number;

	int positive = 0;
	int negative = 0;
	int zeros = 0;

	for (int i = 0; i < count; i++) {
		std::cin >> number;
	
		if (number < 0)
		{
			negative++;
		}
		else if (number > 0)
		{
			positive++;
		}
		else 
		{
			zeros++;
		}
	}

	std::cout << "Positive: " << positive << ", negative: " << negative << ", zeros: " << zeros;
}

void printLine(int length = 10) 
{
	std::cout << std::endl << std::endl;
	for (int i = 0; i < length; i++) {
		std::cout << "*";
	}
	std::cout << std::endl << std::endl;
}
