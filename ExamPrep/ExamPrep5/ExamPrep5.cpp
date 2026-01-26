#include<iostream>

int findMaxMin(const int*, size_t size, int& minVal, int& maxVal);
int getMin(const int* arr, size_t size);
int myMin(int a, int b);
int getMax(const int* arr, size_t size);
int myMax(int a, int b);
double getAvg(const int* arr, size_t size);
double mod(double num);
bool checkStr(const char*);
bool isPalindrome(const char*);
char* getStringWithoutIAndJ(const char* str, int i, int j);
size_t getStrigLength(const char* str);
int convert(const char*, int k);
int myPow(int num, int pow);
int convertCharToInt(char c);

int main()
{
	/*int minVal = -1;
	int maxVal = -1;

	size_t size;
	std::cin >> size;

	int* arr = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	int closestToAvg = findMaxMin(arr, size, minVal, maxVal);

	if (closestToAvg == -1)
	{
		return -1;
	}

	std::cout << minVal << " " << maxVal << " " << closestToAvg << " " << std::endl;

	delete[] arr;*/


	/*size_t size;
	std::cin >> size;

	char* str = new char[size + 1];
	
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> str[i];
	}

	str[size] = '\0';

	if (checkStr(str))
	{
		std::cout << "String can be palindrome!" << std::endl;
	}
	else
	{
		std::cout << "String cannot be palindrome!" << std::endl;
	}
	
	delete[] str;*/

	size_t size;
	std::cin >> size;

	char* num = new char[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		std::cin >> num[i];
	}

	num[size] = '\0';

	int k;
	std::cin >> k;

	int result = convert(num, k);

	if (result == -1)
	{
		return -1;
	}

	std::cout << result << std::endl;

	delete[] num;

	return 0;
}

int findMaxMin(const int* arr, size_t size, int& minVal, int& maxVal)
{
	if (!arr)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return -1;
	}

	minVal = getMin(arr, size);
	maxVal = getMax(arr, size);
	double avg = getAvg(arr, size);

	int closestToAvg = arr[0];

	for (size_t i = 1; i < size; i++)
	{
		if (mod(avg - arr[i]) < mod(avg - closestToAvg))
		{
			closestToAvg = arr[i];
		}
	}

	return closestToAvg;
}

int getMin(const int* arr, size_t size)
{
	int min = INT_MAX;

	for (size_t i = 0; i < size; i++)
	{
		min = myMin(min, arr[i]);
	}

	return min;
}

int myMin(int a, int b)
{
	return a < b ? a : b;
}

int getMax(const int* arr, size_t size)
{
	int max = INT_MIN;

	for (size_t i = 0; i < size; i++)
	{
		max = myMax(max, arr[i]);
	}

	return max;
}

int myMax(int a, int b)
{
	return a > b ? a : b;
}

double getAvg(const int* arr, size_t size)
{
	double sum = 0;

	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum / size;
}

double mod(double num)
{
	return num < 0 ? -num : num;
}

bool checkStr(const char* str)
{
	if (!str)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return false;
	}

	for (size_t i = 0; str[i] != '\0'; i++)
	{
		for (size_t j = i + 1; str[j] != '\0'; j++)
		{
			char* stringWithoutIAndJ = getStringWithoutIAndJ(str, i, j);

			if (!stringWithoutIAndJ)
			{
				return false;
			}

			if (isPalindrome(stringWithoutIAndJ))
			{
				return true;
			}

			delete[] stringWithoutIAndJ;
		}
	}

	return false;
}

bool isPalindrome(const char* str)
{
	if (!str)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return false;
	}

	size_t length = getStrigLength(str);

	for (size_t i = 0; i < length; i++)
	{
		if (str[i] != str[length - i - 1]) 
		{
			return false;
		}
	}

	return true;
}

char* getStringWithoutIAndJ(const char* str, int i, int j)
{
	if (!str)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return nullptr;
	}

	size_t length = getStrigLength(str);

	if (length == 0)
	{
		std::cout << "Invalid string length!" << std::endl;
		return nullptr;
	}

	if (i < 0 || i >= length || j < 0 || j > length)
	{
		std::cout << "Invalid index!" << std::endl;
		return nullptr;
	}

	char* res = new (std::nothrow) char[length - 2 + 1];

	if (!res)
	{
		std::cout << "Couldn't allocate memory for the result string!" << std::endl;
		return nullptr;
	}

	char* beginning = res;

	for (size_t k = 0; k < length; k++)
	{
		if (k == i || k == j)
		{
			continue;
		}

		*res = str[k];
		res++;
	}

	*res = '\0';

	return beginning;
}

size_t getStrigLength(const char* str)
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

int convert(const char* num, int k)
{
	if (!num)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return -1;
	}

	int res = 0;

	int numLen = getStrigLength(num);

	for (int i = numLen - 1; i >= 0; i--)
	{
		int current = convertCharToInt(num[i]);

		if (current == -1)
		{
			std::cout << "Invalid number!" << std::endl;
			return -1;
		}

		res += myPow(k, numLen - 1 - i) * current;
	}

	return res;
}

int myPow(int num, int pow)
{
	int res = 1;

	for (int i = 0; i < pow; i++)
	{
		res *= num;
	}

	return res;
}

int convertCharToInt(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return c - 'A' + 10;
	}
	else
	{
		return -1;
	}
}