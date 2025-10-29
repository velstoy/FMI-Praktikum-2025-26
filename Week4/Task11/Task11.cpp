#include<iostream>

int getDigitOnPosition(int, unsigned int);
int countDigits(int);
int power10(int);

int main()
{
	std::cout << getDigitOnPosition(6289, 3) << std::endl;
	return 0;
}

int getDigitOnPosition(int number, unsigned int position)
{
	number /= power10(countDigits(number) - position);
	return number % 10;
}

int power10(int power)
{
	int res = 1;
	for (int i = 0; i < power; i++)
	{
		res *= 10;
	}

	return res;
}

int countDigits(int number)
{
	int counter = 0;
	do
	{
		number /= 10;
		counter++;
	} while (number != 0);

	return counter;
}
