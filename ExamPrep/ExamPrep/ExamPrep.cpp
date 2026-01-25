#include<iostream>

int analyzeArr(const char*);
int convertCharToInt(const char);
int findIndex(const int arr[], size_t L);
char* findDiff(const long arr[], size_t N);
void findMinModuleIndices(const long arr[], size_t N, int& index1, int& index2);
int myMin(int a, int b);
int myMax(int a, int b);
int getNumLength(long num);
void insertNumberInString(char* str, long num, size_t numLength);
long pow10(long pow);
char convertLongToChar(long num);

const size_t HIST_SIZE = 10;

int main()
{
	const char* str = "13579";

	std::cout << analyzeArr(str) << std::endl;

	const int arr[] = { 10, 5, 2, 8, 4 };

	std::cout << findIndex(arr, sizeof(arr) / sizeof(int)) << std::endl;

	const long another[] = { 100 };

	char* result = findDiff(another, sizeof(another) / sizeof(long));

	std::cout << (result ? result : "") << std::endl;

	delete[] result;

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

char* findDiff(const long arr[], size_t N)
{
	int index1 = -1;
	int index2 = -1;

	findMinModuleIndices(arr, N, index1, index2);

	if (index1 == -1 || index2 == -1)
	{
		return nullptr;
	}

	int sizeNum1 = getNumLength(arr[index1]);
	int sizeNum2 = getNumLength(arr[index2]);

	size_t strSize = sizeNum1 + sizeNum2;

	if (strSize == 0)
	{
		return nullptr;
	}

	char* result = new char[strSize + 2];

	if (!result)
	{
		return nullptr;
	}

	insertNumberInString(result, arr[index1], sizeNum1);

	result[sizeNum1] = ',';

	insertNumberInString(result + sizeNum1 + 1, arr[index2], sizeNum2);

	result[sizeNum1 + sizeNum2 + 1] = '\0';

	return result;
}

void findMinModuleIndices(const long arr[], size_t N, int& index1, int& index2)
{
	int minModule = INT_MAX;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = i + 1; j < N; j++)
		{
			int module = myMax(arr[i], arr[j]) % myMin(arr[i], arr[j]);

			if (module < minModule)
			{
				minModule = module;
				index1 = arr[i] > arr[j] ? i : j;
				index2 = arr[i] < arr[j] ? i : j;
			}
		}
	}
}

int myMin(int a, int b)
{
	return a < b ? a : b;
}

int myMax(int a, int b)
{
	return a > b ? a : b;
}

int getNumLength(long num)
{
	int length = 0;

	while (num != 0)
	{
		length++;
		num /= 10;
	}

	return length;
}

void insertNumberInString(char* str, long num, size_t numLength)
{
	if (!str)
	{
		return;
	}

	for (size_t i = 0; i < numLength; i++)
	{
		int numPower = pow10(numLength - 1);

		*str = convertLongToChar(num / numPower);

		num %= numPower;

		str++;
	}
}

long pow10(long pow)
{
	long res = 1;

	for (size_t i = 0; i < pow; i++)
	{
		res *= 10;
	}

	return res;
}

char convertLongToChar(long num)
{
	if (num >= 0 && num <= 9)
	{
		return '0' + num;
	}

	return -1;
}
