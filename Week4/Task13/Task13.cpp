#include<iostream>

long long concat(unsigned int, unsigned int);
int pow10(int);
int countDigits(int);

int main()
{
	std::cout << concat(123, 456) << std::endl;
	return 0;
}

long long concat(unsigned int first, unsigned int second)
{
	return first * pow10(countDigits(second)) + second;
}

int pow10(int pow)
{
	int res = 1;
	for (int i = 0; i < pow; i++)
	{
		res *= 10;
	}

	return res;
}

int countDigits(int number)
{
	int counter = 0;
	do {
		counter++;
		number /= 10;
	} while (number != 0);

	return counter;
}