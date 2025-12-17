#include<iostream>

int stringifyTimesFound(char* number, char* result);
int discoverTimesFound(char* number, int histogram[]);
int convertCharToNum(char c);
void copyArray(int from[], size_t size, int to[]);
int concat(char* src, char* dest);
int strlen(char* str);
char convertNumToChar(int num);
void convertNumToString(int num, char* result);
void reverseCharArray(char arr[], int size);
void swap(char& a, char& b);

constexpr size_t MAX_HIST_SIZE = 10;
constexpr size_t MAX_SIZE = 1024;

int main()
{
	char num[MAX_SIZE];

	std::cin.getline(num, MAX_SIZE);

	char res[MAX_SIZE];

	if (stringifyTimesFound(num, res) == -1)
	{
		return -1;
	}

	std::cout << res << std::endl;

	return 0;
}

int stringifyTimesFound(char* number, char* result)
{
	if (number == nullptr || result == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return -1;
	}

	int histogram[MAX_HIST_SIZE] = {};

	if (discoverTimesFound(number, histogram) == -1)
	{
		return -1;
	}

	result[0] = '\0';

	for (size_t i = 0; i < MAX_HIST_SIZE; i++)
	{
		if (histogram[i] > 0)
		{
			if (result[0] != '\0')
			{
				char src[2] = {',', '\0'};

				concat(src, result);
			}

			char src[MAX_SIZE] = {};

			char num[MAX_SIZE] = {};

			convertNumToString(histogram[i], num);

			concat(num, src);
			
			char addition[3] = { 'x', convertNumToChar(i), '\0' };

			concat(addition, src);

			concat(src, result);
		}
	}

	return 0;
}

int discoverTimesFound(char* number, int histogram[])
{
	if(number == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return -1;
	}

	int local[MAX_HIST_SIZE] = {};

	while (*number != '\0')
	{
		int currentIndex = convertCharToNum(*number);

		if (currentIndex != -1)
		{
			local[currentIndex]++;
		}

		number++;
	}

	copyArray(local, MAX_HIST_SIZE, histogram);

	return 0;
}

int convertCharToNum(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}

	return -1;
}

void copyArray(int from[], size_t size, int to[])
{
	for (size_t i = 0; i < size; i++)
	{
		to[i] = from[i];
	}
}

int concat(char* src, char* dest)
{
	if (src == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return -1;
	} 

	int srcLen = strlen(src);

	if (srcLen == -1)
	{
		return -1;
	}

	int destLen = strlen(dest);

	if (destLen == -1)
	{
		return -1;
	}

	for (int i = 0; i < srcLen; i++)
	{
		dest[destLen + i] = src[i];
	}

	dest[destLen + srcLen] = '\0';

	return 0;
}

int strlen(char* str)
{
	if (str == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return -1;
	}

	int counter = 0;

	while (*str)
	{
		counter++;
		str++;
	}

	return counter;
}

char convertNumToChar(int num)
{
	if (num >= 0 && num <= 9)
	{
		return '0' + num;
	}

	return -1;
}

void convertNumToString(int num, char* result)
{
	result[0] = '\0';

	while (num != 0)
	{
		char src[2] = { convertNumToChar(num % 10), '\0' };

		concat(src, result);

		num /= 10;
	}

	int resLen = strlen(result);

	if (resLen == -1)
	{
		return;
	}

	reverseCharArray(result, resLen);
}

void reverseCharArray(char arr[], int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		swap(arr[i], arr[size - i - 1]);
	}
}

void swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}
