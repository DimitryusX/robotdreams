#include <iostream>

int factorialLoop(int n)
{
	int result = 1;

	for (int i = 1; i <= n; ++i)
	{
		result *= i;
	}

	return result;
}

void printNaturalNumbersLoop(int count)
{
	std::cout << std::endl;

	for (int i = count; i > 0; i--)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;

	for (int i = 1; i <= count; i++)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;
}