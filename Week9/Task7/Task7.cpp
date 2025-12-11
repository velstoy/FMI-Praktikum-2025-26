#include<iostream>

constexpr size_t N = 1024;

int inputNumArray(char arr[], size_t size);
void outputCharArray(const char arr[], size_t size);
void decreaseNumberInKBaseByOne(char num[], size_t size, int k);
char numToCharInKBase(int num, int k);

int main()
{
	char num[N];

	int n;
	std::cin >> n;

	if (inputNumArray(num, n) == -1)
	{
		std::cout << "Incorrect input error." << std::endl;
		return -1;
	}

	int k;
	std::cin >> k;

	decreaseNumberInKBaseByOne(num, n, k);

	outputCharArray(num, n);

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

void decreaseNumberInKBaseByOne(char num[], size_t size, int k)
{
	char maxPossibleDigit = numToCharInKBase(k - 1, k);

	if (maxPossibleDigit == 0)
	{
		std::cout << "Incorrect number base!" << std::endl;
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (num[size - i - 1] == '0')
		{
			num[size - i - 1] = maxPossibleDigit;
		}
		else
		{
			if (num[size - i - 1] == 'A')
			{
				num[size - i - 1] = '9';
			}
			else
			{
				num[size - i - 1]--;
			}
			break;
		}
	}
}

char numToCharInKBase(int num, int k)
{
	if (num >= 0 || num <= 9)
	{
		return '0' + num;
	}
	else if (num >= 10 || num <= k)
	{
		return 'A' + num;
	}
	else
	{
		return 0;
	}
}
