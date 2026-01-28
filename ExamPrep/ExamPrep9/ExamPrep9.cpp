#include<iostream>
#include<limits>

struct Point
{
	int x, y;
};

struct Segment
{
	Point start, end;
};

const size_t CONSOLE_HEIGHT = 25;
const size_t CONSOLE_WIDTH = 80;

int* getCombinedSortedArray(const int* arr1, size_t size1, const int* arr2, size_t size2);
int getCrossSectionSize(const Segment& seg1, const Segment& seg2);
int myMax(int a, int b);
int myMin(int a, int b);
void printRectangle(int n, int m, char c);
int sumDigitsAboveMainDiagonal(int** matrix, int n);
int** getTransposed(int** matrix, int n);

int main()
{
	return 0;
}

int* getCombinedSortedArray(const int* arr1, size_t size1, const int* arr2, size_t size2)
{
	if (!arr1 || !arr2)
	{
		return nullptr;
	}

	int* result = new (std::nothrow) int[size1 + size2];

	if (!result)
	{
		return nullptr;
	}

	int arr1Index = 0, arr2Index = 0, resultArrIndex = 0;

	while (arr1Index < size1 && arr2Index < size2 && resultArrIndex < size1 + size2)
	{
		if (arr1[arr1Index] <= arr2[arr2Index])
		{
			result[resultArrIndex] = arr1[arr1Index];
			arr1Index++;
		}
		else
		{
			result[resultArrIndex] = arr2[arr2Index];
			arr2Index++;
		}

		resultArrIndex++;
	}

	if (arr1Index == size1)
	{
		for (int i = arr2Index; i < size2; i++)
		{
			result[resultArrIndex] = arr2[i];
			resultArrIndex++;
		}
	}
	else if (arr2Index == size2)
	{
		for (int i = arr1Index; i < size1; i++)
		{
			result[resultArrIndex] = arr1[i];
			resultArrIndex++;
		}
	}

	return result;
}

int getCrossSectionSize(const Segment& seg1, const Segment& seg2)
{
	int size = 0;

	if (seg1.start.x == seg1.end.x && seg2.start.x == seg2.start.x && seg1.start.x == seg2.start.x)
	{
		int firstStart = seg1.start.y >= seg1.end.y ? seg1.start.y : seg1.end.y;
		int firstEnd = seg1.start.y == firstStart ? seg1.end.y : seg1.start.y;

		int secondStart = seg2.start.y >= seg2.end.y ? seg2.start.y : seg2.end.y;
		int secondEnd = seg2.start.y == secondStart ? seg2.end.y : seg2.start.y;

		return myMax(firstStart, secondStart) - myMin(firstEnd, secondEnd);
	}
	else if (seg1.start.y == seg1.end.y && seg2.start.y == seg2.start.y && seg1.start.y == seg2.start.y)
	{
		int firstStart = seg1.start.x >= seg1.end.x ? seg1.start.x : seg1.end.x;
		int firstEnd = seg1.start.x == firstStart ? seg1.end.x : seg1.start.x;

		int secondStart = seg2.start.x >= seg2.end.x ? seg2.start.x : seg2.end.x;
		int secondEnd = seg2.start.x == secondStart ? seg2.end.x : seg2.start.x;

		return myMax(firstStart, secondStart) - myMin(firstEnd, secondEnd);
	}

	return -1;
}

int myMax(int a, int b)
{
	return a > b ? a : b;
}

int myMin(int a, int b)
{
	return a < b ? a : b;
}

void printRectangle(int n, int m, char c)
{
	for (int i = 0; i < CONSOLE_HEIGHT / 2 - n / 2; i++)
	{
		std::cout << std::endl;
	}

	for (int i = 0; i < n; i++)
	{
		for (size_t i = 0; i < CONSOLE_WIDTH / 2 - m / 2; i++)
		{
			std::cout << ' ';
		}

		for (int j = 0; j < m; j++)
		{
			std::cout << c;
		}
		std::cout << std::endl;
	}
}

int sumDigitsAboveMainDiagonal(int** matrix, int n)
{
	if (!matrix)
	{
		return -1;
	}

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (!matrix[i])
		{
			return -1;
		}

		for (int j = 0; j < n; j++)
		{
			if (j > i)
			{
				sum += matrix[i][j];
			}
		}
	}

	return sum;
}

int** getTransposed(int** matrix, int n)
{
	if (!matrix)
	{
		return nullptr;
	}

	int** transposed = new (std::nothrow) int*[n];

	if (!transposed)
	{
		return nullptr;
	}

	for (int i = 0; i < n; i++)
	{
		if (!matrix[i])
		{
			return nullptr;
		}

		transposed[i] = new (std::nothrow) int[n];

		if (!transposed[i])
		{
			return nullptr;
		}

		for (int j = 0; j < n; j++)
		{
			transposed[i][j] = matrix[j][i];
		}
	}

	return transposed;
}