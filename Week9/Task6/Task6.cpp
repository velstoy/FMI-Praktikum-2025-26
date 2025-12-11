#include<iostream>

constexpr size_t N = 50;

void inputCharArray(char arr[], size_t size);
void printCharArray(char arr[], size_t size);
void increaseByOne(char num[], size_t& size, int base);
char convertNumToChar(int num);

int main()
{
	char num[N];

	size_t size;
	std::cin >> size;

	if (size > N)
	{
		std::cout << "Invalid size!";
		return 1;
	}

	inputCharArray(num, size);

	int base;
	std::cin >> base;

	increaseByOne(num, size, base);

	printCharArray(num, size);

	return 0;
}

void inputCharArray(char arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void printCharArray(char arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i];
	}

	std::cout << std::endl;
}

void increaseByOne(char num[], size_t& size, int base)
{
	char maxDigit = convertNumToChar(base - 1);

	if (maxDigit == 0)
	{
		std::cout << "Invalid base!";
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		char check = num[size - i - 1] + 1;

		if (check > maxDigit)
		{
			num[size - i - 1] = '0';
			
			if (i == size - 1)
			{
				num[0] = '1';

				size++;
				
				num[size - 1] = '0';
			}
		}
		else
		{
			if (num[size - i - 1] == '9')
			{
				num[size - i - 1] = 'A';
			}
			else
			{
				num[size - i - 1]++;
			}
			break;
		}
	}
}

char convertNumToChar(int num)
{
	if (num >= 0 && num <= 9)
	{
		return '0' + num;
	}
	else if ('A' + num <= 'Z')
	{
		return 'A' + num;
	}
	else
	{
		return 0;
	}
}
