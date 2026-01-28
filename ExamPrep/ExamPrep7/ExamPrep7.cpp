#include<iostream>
#include<limits>

// Solution to task 1.
unsigned int getGCD(const unsigned int*, size_t);

// Solution to task 2.
bool doExist(const char* symbols, const char* word);
size_t myStrlen(const char* str);

// Solution to task 3.
unsigned short int reverseBitwise(unsigned short int);
unsigned short int myPow(unsigned short int num, int pow);

int main()
{
	return 0;
}

// Returns -1 if the function fails in some way.
unsigned int getGCD(const unsigned int* arr, size_t size)
{
	if (!arr)
	{
		return -1;
	}

	unsigned int gcd = arr[0];

	for (size_t i = 1; i < size; i++)
	{
		unsigned int remainder = arr[i] % gcd;

		if (remainder == 0)
		{
			continue;
		}

		while (gcd % remainder != 0)
		{
			unsigned int temp = gcd;
			gcd = remainder;
			remainder = temp % remainder;
		}

		gcd = remainder;
	}

	return gcd;
}

bool doExist(const char* symbols, const char* word)
{
	if (!symbols || !word)
	{
		return false;
	}

	size_t symbolsLen = myStrlen(symbols);
	size_t wordLen = myStrlen(word);

	if (symbolsLen == 0 || wordLen > symbolsLen)
	{
		return false;
	}

	if (wordLen == 0)
	{
		return true;
	}

	for (int i = symbolsLen - 1; i >= wordLen; i--)
	{
		bool exists = true;

		for (size_t j = 0; j < wordLen; j++)
		{
			if (symbols[i - j] != word[j])
			{
				exists = false;
				break;
			}
		}

		if (exists)
		{
			return true;
		}
	}

	return false;
}

size_t myStrlen(const char* str)
{
	if (!str)
	{
		return 0;
	}

	size_t len = 0;

	while (*str)
	{
		len++; 
		str++;
	}

	return len;
}

unsigned short int reverseBitwise(unsigned short int num)
{
	unsigned short int res = 0;

	int i = 15;

	while (num != 0)
	{
		res += (num % 2) * myPow(2, i);
		num /= 2;
		i--;
	}

	return res;
}

unsigned short int myPow(unsigned short int num, int pow)
{
	unsigned short int res = 1;

	for (int i = 0; i < pow; i++)
	{
		res *= num;
	}

	return res;
}