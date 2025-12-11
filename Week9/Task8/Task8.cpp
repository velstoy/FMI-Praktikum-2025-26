#include<iostream>

constexpr size_t N = 1024;

int inputNumArray(char arr[], size_t size);
void outputCharArray(const char arr[], size_t size);
void sumTwoNumsInKBase(char num1[], size_t size1, char num2[], size_t size2, int k, char res[], size_t& resSize);
char numToCharInKBase(int num, int k);
int charToNumInKBase(char c, int k);

int main()
{
	char num1[N], num2[N];

	size_t size1, size2;
	std::cin >> size1 >> size2;

	inputNumArray(num1, size1);
	inputNumArray(num2, size2);

	int k;
	std::cin >> k;

	char res[N];

	size_t resSize = 0;

	sumTwoNumsInKBase(num1, size1, num2, size2, k, res, resSize);

	outputCharArray(res, resSize);

	return 0;
}

int inputNumArray(char arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		char input;
		std::cin >> input;

		if (!((input >= '0' && input <= '9') || (input >= 'A' && input <= 'Z')))
		{
			return -1;
		}

		arr[i] = input;
	}

	return 0;
}

void outputCharArray(const char arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i];
	}

	std::cout << std::endl;
}

void sumTwoNumsInKBase(char num1[], size_t size1, char num2[], size_t size2, int k, char res[], size_t& resSize)
{
	resSize = 0;

	char sum[N];

	int carryover = 0;

	int maxSize = (size1 > size2) ? size1 : size2;

	for (int i = 0; i < maxSize; i++)
	{
		int digit = 0;
		if (size1 > i && size2 > i)
		{
			digit = charToNumInKBase(num1[size1 - i - 1], k) + charToNumInKBase(num2[size2 - i - 1], k) + carryover;
 		}
		else if (size1 <= i)
		{
			digit = charToNumInKBase(num2[size2 - i - 1], k) + carryover;
		}
		else if (size2 <= i)
		{
			digit = charToNumInKBase(num1[size1 - i - 1], k) + carryover;
		}

		carryover = 0;

		while (digit >= k)
		{
			digit -= k;
			carryover++;
		}


		sum[i] = numToCharInKBase(digit, k);
		resSize++;
	}

	if (carryover > 0)
	{
		sum[resSize] = numToCharInKBase(carryover, k);
		resSize++;
	}

	for (size_t i = 0; i < resSize; i++)
	{
		res[i] = sum[resSize - i - 1];
	}
}

char numToCharInKBase(int num, int k)
{
	if (num >= 0 && num <= 9)
	{
		return '0' + num;
	}
	else if (num >= 10 && num < k)
	{
		return 'A' + num - 10;
	}
	
	return 0;
}

int charToNumInKBase(char c, int k)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return c - 'A' + 10;
	}

	return -1;
}




