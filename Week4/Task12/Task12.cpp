#include<iostream>

int countDigits(long long);
long long sumDigits(long long);
long long calculateToSingleDigit(long long);

int main()
{
	std::cout << calculateToSingleDigit(999999999999) << std::endl;
	return 0;
}

long long calculateToSingleDigit(long long number)
{
	if (countDigits(number) == 1)
	{
		return number;
	}
	calculateToSingleDigit(sumDigits(number));
}

long long sumDigits(long long number)
{
	int sum = 0;
	while (number != 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

int countDigits(long long number)
{
	int counter = 0;
	do
	{
		number /= 10;
		counter++;
	} while (number != 0);

	return counter;
}