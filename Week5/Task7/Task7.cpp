#include<iostream>

void leaveOnlyIToJ(int& num, int i, int j);
int pow10(int power);
int countDigits(int num);

int main()
{
	int num, i, j;
	std::cin >> num >> i >> j;

	leaveOnlyIToJ(num, i, j);

	std::cout << num;

	return 0;
}

void leaveOnlyIToJ(int& num, int i, int j)
{
	int trueJ = countDigits(num) - j;

	num /= pow10(trueJ);

	int trueI = countDigits(num) - i + 1;

	num = num % pow10(trueI);
}

int pow10(int power)
{
	int res = 1;
	for (int i = 0; i < power; i++)
	{
		res *= 10;
	}
	return res;
}

int countDigits(int num)
{
	int res = 0;
	do
	{
		res++;
		num /= 10;
	} while (num != 0);

	return res;
}