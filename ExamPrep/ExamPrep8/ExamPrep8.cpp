#include<iostream>

double sqrt_a(double a, double eps);
double myAbs(double num);
void Revert(char[]);
bool CheckDate(char[]);
size_t myStrlen(char str[]);
int convertCharToInt(char c);
int DigitPos(long num, int k);
long pow(int num, int pow);
size_t getNumLen(long num);

const size_t MAX_SIZE = 1024;
const size_t DATE_SIZE = 5;

int main()
{
	return 0;
}

double sqrt_a(double a, double eps)
{
	double xK = a;
	double xKPlusOne = 0.5 * (xK + (a / xK));

	while (myAbs(xKPlusOne - xK) >= eps)
	{
		double temp = xK;
		xK = xKPlusOne;
		xKPlusOne = 0.5 * (xK + (a / xK));
	}

	return xKPlusOne;
}

double myAbs(double num)
{
	return num < 0 ? -num : num;
}

void Revert(char str[])
{
	if (!str)
	{
		return;
	}

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str -= ('a' - 'A');
		}
		else if (*str >= 'A' && *str <= 'Z')
		{
			*str += ('a' - 'A');
		}
		str++;
	}
}

bool CheckDate(char date[])
{
	if (!date)
	{
		return false;
	}

	size_t dateLen = myStrlen(date);

	if (dateLen != DATE_SIZE)
	{
		return false;
	}

	int converted[DATE_SIZE - 1];

	int convertedIndex = 0;

	for (size_t i = 0; i < DATE_SIZE; i++)
	{
		if (i == 2)
		{
			if (date[i] != '.')
			{
				return false;
			}
			continue;
		}

		converted[convertedIndex] = convertCharToInt(date[i]);

		if (converted[convertedIndex] == -1)
		{
			return false;
		}

		convertedIndex++;
	}

	int day = converted[0] * 10 + converted[1];
	int month = converted[2] * 10 + converted[3];

	if (month > 12 || month <= 0 || day > 31 || day <= 0)
	{
		return false;
	}
	else if (day == 31)
	{
		switch (month)
		{
			case 2:
			case 4:
			case 6:
			case 9:
			case 11:
				return false;
		}
	}
	else if (day >= 29 && month == 2)
	{
		return false;
	}

	return true;
}

size_t myStrlen(char str[])
{
	if (!str)
	{
		return 0;
	}

	size_t res = 0;

	while (*str)
	{
		res++;
		str++;
	}

	return res;
}

int convertCharToInt(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}

	return -1;
}

int DigitPos(long num, int k)
{
	size_t numLen = getNumLen(num);

	if (k > numLen || k <= 0)
	{
		return -1;
	}

	return (num / (long)pow(10, numLen - k)) % 10;
}

long pow(int num, int pow)
{
	long res = 1;

	for (size_t i = 0; i < pow; i++)
	{
		res *= num;
	}

	return res;
}

size_t getNumLen(long num)
{
	size_t res = 0;

	while (num != 0)
	{
		res++;
		num /= 10;
	}

	return res;
}
