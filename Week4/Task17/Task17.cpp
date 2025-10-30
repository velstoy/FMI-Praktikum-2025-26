#include<iostream>
using std::cout;
using std::endl;

unsigned int sortDigits(unsigned int number);
unsigned int getLength(unsigned int number);
unsigned int extractDigit(unsigned int number, int position);
unsigned int swapDigits(unsigned int number, int pos1, int pos2);
int pow10(int pow);


int main()
{
	cout << sortDigits(2347026934) << endl;
	cout << sortDigits(1000) << endl;
	return 0;
}

unsigned int sortDigits(unsigned int number)
{
	int length = getLength(number);
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			int iThNumber = extractDigit(number, i);
			int jThNumber = extractDigit(number, j);

			if (iThNumber > jThNumber)
			{
				number = swapDigits(number, i, j);
			}
		}
	}
	return number;
}

unsigned int getLength(unsigned int number)
{
	unsigned int length = 0;

	do {
		length++;
		number /= 10;
	} while (number != 0);
	return length;
}

unsigned int extractDigit(unsigned int number, int position)
{
	return number / pow10(getLength(number) - position - 1) % 10;
}

unsigned int swapDigits(unsigned int number, int pos1, int pos2)
{
	int digit1 = extractDigit(number, pos1);
	int digit2 = extractDigit(number, pos2);

	int trail1 = number % pow10(getLength(number) - pos1 - 1);

	int swap = (number / pow10(getLength(number) - pos1) * 10 + digit2) * pow10(getLength(trail1)) + trail1;

	number = swap;

	int trail2 = number % pow10(getLength(number) - pos2 - 1);

	swap = (number / pow10(getLength(number) - pos2) * 10 + digit1) * (trail2 == 0 ? 1 : pow10(getLength(trail2))) + trail2;

	number = swap;

	return number;
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
