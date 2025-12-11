#include<iostream>

int findOccurrencesOf1InNumber(int num);

int main()
{
	int num;
	std::cin >> num;

	std::cout << "Occurrences of 1: " << findOccurrencesOf1InNumber(num) << std::endl;

	return 0;
}

int findOccurrencesOf1InNumber(int num)
{
	int count = 0;

	while (num != 0)
	{
		count += num % 2;
		num /= 2;
	}

	return count;
}
