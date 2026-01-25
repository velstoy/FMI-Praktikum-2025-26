#include<iostream>

bool analyzeArr(const char*);
bool validateDate(const char*);
int convertCharToInt(const char);
size_t myStrlen(const char*);
int pow10(int);
int Find(long N, int n);
int myMax(int a, int b);

const size_t ALPHABET_SIZE = 26;
const size_t FORMAT_SIZE = 10;

int main()
{
	/*const char* test1 = "aBCc";

	std::cout << std::boolalpha << analyzeArr(test1) << std::endl;

	const char* test2 = "29-02-1900";

	std::cout << std::boolalpha << validateDate(test2) << std::endl;*/

	long test3;
	int n;

	std::cin >> test3;
	std::cin >> n;

	std::cout << Find(test3, n) << std::endl;

	return 0;
}

bool analyzeArr(const char* str)
{
	if (str == nullptr)
	{
		std::cout << "String cannot point to null value!" << std::endl;
		return false;
	}

	bool smallLetterHist[ALPHABET_SIZE] = {};
	bool bigLetterHist[ALPHABET_SIZE] = {};

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			smallLetterHist[*str - 'a'] = true;
		}
		else if (*str >= 'A' && *str <= 'Z')
		{
			bigLetterHist[*str - 'A'] = true;
		}

		str++;
	}

	for (size_t i = 0; i < ALPHABET_SIZE; i++)
	{
		if (bigLetterHist[i] && !smallLetterHist[i])
		{
			return false;
		}
	}

	return true;
}

bool validateDate(const char* str)
{
	if (!str)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return false;
	}

	size_t strLen = myStrlen(str);

	if (strLen != FORMAT_SIZE)
	{
		return false;
	}

	int charValues[FORMAT_SIZE - 2];
	int diff = 0;

	for (size_t i = 0; i < strLen; i++)
	{
		if (str[i] == '-' && (i == 2 || i == 5))
		{
			diff++;
			continue;
		}

		charValues[i - diff] = convertCharToInt(str[i]);

		if (charValues[i - diff] == -1)
		{
			return false;
		}
	}

	int day = charValues[0] * 10 + charValues[1];
	int month = charValues[2] * 10 + charValues[3];
	int year = charValues[4] * 1000 + charValues[5] * 100 + charValues[6] * 10 + charValues[7];

	if (day > 31 || day == 0 || month > 12 || month == 0)
	{
		return false;
	}
	else if (((day > 28 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) 
		|| (day > 29 && year % 4 == 0)) && month == 2)
	{
		return false;
	}
	else if (day > 30 && ((month <= 7 && month % 2 == 0) || (month > 7 && month % 2 == 1)))
	{
		return false;
	}

	return true;
}

int convertCharToInt(const char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}

	return -1;
}

size_t myStrlen(const char* str)
{
	if (!str)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return 0;
	}

	size_t length = 0;

	while (*str)
	{
		length++;
		str++;
	}

	return length;
}

int pow10(int pow)
{
	int res = 1;

	for (size_t i = 0; i < pow; i++)
	{
		res *= 10;
	}

	return res;
}

int Find(long N, int n)
{
	int max = INT_MIN;

	int power = pow10(n);

	if (N < power / 10 || N <= 0 || n <= 0)
	{
		std::cout << "Not found!" << std::endl;
		return 0;
	}

	while (N >= power / 10)
	{
		max = myMax(max, N % power);
		N /= 10;
	}

	return max;
}

int myMax(int a, int b)
{
	return a > b ? a : b;
}