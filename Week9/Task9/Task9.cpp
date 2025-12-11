#include<iostream>

void convertFromAnyToAnyBase(const char fromNum[], size_t fromSize, char toNum[], size_t& toSize, unsigned fromBase, unsigned toBase);
int convertToDecimalFromKBase(const char num[], size_t size, int k);
int power(int num, int pow);
int convertFromCharToInt(char c);
void convertToKBaseFromDecimal(int num, char res[], size_t& resSize, int k);
char convertFromIntToChar(int n);
void reverseCharArray(char arr[], size_t size);

int main()
{
	char fromNum[6] = { '2', '3', '5', '4', '7', '6' };
	char toNum[50];
	size_t size = 0;

	convertFromAnyToAnyBase(fromNum, 6, toNum, size, 8, 16);

	for (size_t i = 0; i < size; i++)
	{
		std::cout << toNum[i];
	}

	return 0;
}

void convertFromAnyToAnyBase(const char fromNum[], size_t fromSize, char toNum[], size_t& toSize, unsigned fromBase, unsigned toBase)
{
	int decimalNum = convertToDecimalFromKBase(fromNum, fromSize, fromBase);

	convertToKBaseFromDecimal(decimalNum, toNum, toSize, toBase);
}

int convertToDecimalFromKBase(const char num[], size_t size, int k)
{
	int res = 0;

	for (size_t i = 0; i < size; i++)
	{
		int current = convertFromCharToInt(num[i]);

		if (current == -1)
		{
			std::cout << "Faulty character passed to function!" << std::endl;
			return -1;
		}

		res += current * power(k, size - i - 1);
	}

	return res;
}

int power(int num, int pow)
{
	int res = 1;

	for (int i = 0; i < pow; i++)
	{
		res *= num;
	}

	return res;
}

int convertFromCharToInt(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return c - 'Z' + 10;
	}

	return -1;
}

void convertToKBaseFromDecimal(int num, char res[], size_t& resSize, int k)
{
	while (num != 0)
	{
		char digit = convertFromIntToChar(num % k);

		if (digit == -1)
		{
			std::cout << "Invalid base!" << std::endl;
			return;
		}

		res[resSize++] = digit;
		num /= k;
	}

	reverseCharArray(res, resSize);
}

char convertFromIntToChar(int n)
{
	if (n >= 0 && n <= 9)
	{
		return '0' + n;
	}
	else if (n >= 10 && n <= 10 + ('Z' - 'A'))
	{
		return 'A' + n - 10;
	}

	return -1;
}

void reverseCharArray(char arr[], size_t size)
{
	for (size_t i = 0; i < size / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
}
