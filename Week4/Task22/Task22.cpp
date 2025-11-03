#include<iostream>

void primeFactorization(int);

int main()
{
	primeFactorization(225);
	return 0;
}

void primeFactorization(int number)
{
	for (int i = 2; i <= number; i++)
	{
		if (number % i == 0)
		{
			std::cout << i;
			number /= i;
			i --;
			if (number != 1)
			{
				std::cout << ".";
			}
		}	
	}
}
