#include <iostream>

int fatorialRecursion(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n * fatorialRecursion(n - 1);
	}
}

void printIncreaseNaturalNumbersRecursion(int current)
{
	if (current >= 1)
	{
		printIncreaseNaturalNumbersRecursion(current - 1);
		std::cout << current << " ";
	}
}

void printDecreaseNaturalNumbersRecursion(int current)
{
	if (current >= 1)
	{
		std::cout << current << " ";
		printDecreaseNaturalNumbersRecursion(current - 1);
	}
	else
	{
		std::cout << std::endl;
	}
}
