#include<iostream>

int analyzeArr(const char*);
int convertCharToInt(const char);
int findIndex(const int arr[], size_t L);

const size_t HIST_SIZE = 10;

int main()
{
	const char* str = "13579";

	std::cout << analyzeArr(str) << std::endl;

	const int arr[] = { 10, 5, 2, 8, 4 };

	std::cout << findIndex(arr, sizeof(arr) / sizeof(int)) << std::endl;

	return 0;
}

int analyzeArr(const char* str)
{
	bool histogram[HIST_SIZE] = {};

	while (*str)
	{
		int currentChar = convertCharToInt(*str);

		if (currentChar != -1)
		{
			histogram[currentChar] = true;
		}

		str++;
	}

	for (int i = HIST_SIZE - 1; i >= 0; i--)
	{
		if (!histogram[i]) 
		{
			return i;
		}
	}

	return -1;
}

// returns the corresponding integer to a given character that is a number\
// returns -1 otherwise
int convertCharToInt(const char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}

	return -1;
}

int findIndex(const int arr[], size_t L)
{
	int diff = 0;

	while (L - diff != 0)
	{
		int smallerCount = 0;

		for (size_t i = 0; i < L; i++)
		{
			if (arr[i] < L - diff)
			{
				smallerCount++;
			}

			if (smallerCount > diff)
			{
				break;
			}
		}

		if (smallerCount <= diff)
		{
			return L - diff;
		}

		diff++;
	}

	return 0;
}
