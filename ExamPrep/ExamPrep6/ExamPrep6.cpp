#include<iostream>

const size_t ARABIC_COUNT = 3;

bool checkNum(long);
size_t getNumLength(long);
long getNumWithoutI(long, int);
long pow10(long);
bool isMonotonous(long);
int findNumber(const char*);
void extractArabicDigits(const char*, int[]);
void sortArray(int[], size_t); 
int* spiralRead(int**, size_t, size_t);

int main()
{
	/*long num;
	std::cin >> num;

	std::cout << std::boolalpha << checkNum(num) << std::endl;

	*/

	/*size_t size;
	std::cin >> size;

	char* str = new char[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		std::cin >> str[i];
	}

	std::cout << findNumber(str) << std::endl;

	delete[] str;*/

	int n;
	std::cin >> n;

	int** matrix = new int* [n];

	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (size_t j = 0; j < n; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	int* result = spiralRead(matrix, n, n);

	for (size_t i = 0; i < n * n; i++)
	{
		std::cout << result[i] << " ";
	}

	std::cout << std::endl;

	delete[] result;

	for (size_t i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;

	return 0;
}

bool checkNum(long num)
{
	size_t numLen = getNumLength(num);

	for (size_t i = 0; i < numLen; i++)
	{
		int current = getNumWithoutI(num, i);

		if (isMonotonous(current))
		{
			return true;
		}
	}

	return false;
}

size_t getNumLength(long num)
{
	size_t res = 0;

	while(num != 0)
	{
		res++;
		num /= 10;
	}

	return res;
}

long getNumWithoutI(long num, int i)
{
	size_t numLen = getNumLength(num);

	long res = 0;

	int globalIndex = numLen - 1;

	for (size_t j = 0; j < numLen; j++)
	{
		long power = pow10(numLen - j - 1);

		if (i == j)
		{
			num %= power;
			continue;
		}

		res += (num / power) * pow10(globalIndex - 1);

		num %= power;

		globalIndex--;
	}

	return res;
}

long pow10(long pow)
{
	long res = 1;

	for (long i = 0; i < pow; i++)
	{
		res *= 10;
	}
	
	return res;
}

bool isMonotonous(long num)
{
	size_t numLen = getNumLength(num);

	if (numLen < 3)
	{
		return true;
	}

	int firstDigit = -1;
	int secondDigit = -1;
	int thirdDigit = -1;

	for (size_t i = 0; i < numLen; i++)
	{
		long power = pow10(numLen - i - 1);

		if (i == 0)
		{
			firstDigit = num / power;
		}
		else if (i == 1)
		{
			secondDigit = num / power;
		}
		else if (i == 2)
		{
			thirdDigit = num / power;
		}
		else
		{
			if ((firstDigit >= secondDigit && secondDigit < thirdDigit) ||
				(firstDigit <= secondDigit && secondDigit > thirdDigit))
			{
				return false;
			}

			firstDigit = secondDigit;
			secondDigit = thirdDigit;
			thirdDigit = num / power;
		}

		num %= power;
	}

	if ((firstDigit >= secondDigit && secondDigit < thirdDigit) ||
		(firstDigit <= secondDigit && secondDigit > thirdDigit))
	{
		return false;
	}

	return true;
}

int findNumber(const char* str)
{
	if (!str)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return -1;
	}

	int digits[ARABIC_COUNT];

	extractArabicDigits(str, digits);

	for (size_t i = 0; i < ARABIC_COUNT; i++)
	{
		for (size_t j = i + 1; j < ARABIC_COUNT; j++)
		{
			if (digits[i] == digits[j])
			{
				int palindrome = digits[i] * 100 + digits[j];

				digits[i] = 0;
				digits[j] = 0;

				for (size_t k = 0; k < ARABIC_COUNT; k++)
				{
					palindrome += 10 * digits[k];
				}

				return palindrome;
			}
		}
	}

	sortArray(digits, ARABIC_COUNT);

	int palindrome = 0;

	for (size_t i = 0; i < ARABIC_COUNT; i++)
	{
		palindrome *= 10;
		palindrome += digits[i];
	}

	for (size_t i = 0; i < ARABIC_COUNT; i++)
	{
		palindrome *= 10;
		palindrome += digits[ARABIC_COUNT - i - 1];
	}

	while (palindrome % 10 == 0)
	{
		palindrome /= 10;
	}

	return palindrome;
}

void extractArabicDigits(const char* str, int digits[])
{
	int i = 0;

	while (*str && i < ARABIC_COUNT)
	{
		if (*str >= '0' && *str <= '9')
		{
			digits[i] = *str - '0';
			i++;
		}

		str++;
	}
}

void sortArray(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		int min = arr[i];
		int minIndex = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j]) 
			{
				min = arr[j];
				minIndex = j;
			}
		}

		int temp = arr[i];
		arr[i] = min;
		arr[minIndex] = temp;
	}
}

int* spiralRead(int** matrix, size_t rows, size_t cols)
{
	if (!matrix)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return nullptr;
	}

	int* result = new (std::nothrow) int[rows * cols];

	if (!result)
	{
		std::cout << "Could not allocate memory for result array!" << std::endl;
		return nullptr;
	}

	int globalIndex = 0;
	int direction = 0;
	int top = 0;
	int bottom = rows - 1;
	int left = 0;
	int right = cols - 1;

	while (globalIndex < rows * cols)
	{
		switch (direction)
		{
		case 0:
			for (int i = top; i <= bottom && globalIndex < rows * cols; i++)
			{
				result[globalIndex++] = matrix[i][left];
			}

			left++;

			break;
		case 1:
			for (int i = left; i <= right && globalIndex < rows * cols; i++)
			{
				result[globalIndex++] = matrix[bottom][i];
			}

			bottom--;

			break;
		case 2:
			for (int i = bottom; i >= top && globalIndex < rows * cols; i--)
			{
				result[globalIndex++] = matrix[i][right];
			}

			right--;
			break;
		case 3:
			for (int i = right; i >= left && globalIndex < rows * cols; i--)
			{
				result[globalIndex++] = matrix[top][i];
			}

			top++;
			break;
		}

		direction++;
		if (direction > 3)
		{
			direction = 0;
		}
	}
	
	return result;
}
