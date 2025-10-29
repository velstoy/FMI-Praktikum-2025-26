#include<iostream>

long power(int, unsigned int);

int main()
{
	std::cout << power(5, 2) << std::endl;
	return 0;
}

long power(int base, unsigned int exponent)
{
	long number = 1;
	for (int i = 0; i < exponent; i++)
	{
		number *= base;
	}
	return number;
}