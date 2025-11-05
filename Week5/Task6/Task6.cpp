#include<iostream>

void splitIntoEvenAndOdd(int num, int& even, int& odd);
int reverseNumber(int num);

int main()
{
	int even = 0, odd = 0;

	int num;
	std::cin >> num;

	splitIntoEvenAndOdd(num, even, odd);

	std::cout << even << " " << odd;

	return 0;
}

void splitIntoEvenAndOdd(int num, int& even, int& odd)
{
	if (even != 0 || odd != 0) return;

	num = reverseNumber(num);

	do
	{
		if ((num % 10) % 2 == 0)
		{
			even = even * 10 + num % 10;
		}
		else
		{
			odd = odd * 10 + num % 10;
		}
		num /= 10;
	} while (num != 0);
}

int reverseNumber(int num)
{
	int res = 0;

	do
	{
		res = res * 10 + num % 10;
		num /= 10;
	} while (num != 0);

	return res;
}
