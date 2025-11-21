#include<iostream>

constexpr size_t N = 50;

void inputMatrix(int matrix[][N], size_t size);
int findMatrixMinimum(const int matrix[][N], size_t size);
int myMin(int a, int b);

int main()
{
	int matrix[N][N];

	int n;
	std::cin >> n;

	inputMatrix(matrix, n);

	std::cout << findMatrixMinimum(matrix, n);

	return 0;
}

void inputMatrix(int matrix[][N], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

int findMatrixMinimum(const int matrix[][N], size_t size)
{
	int min = INT_MAX;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			min = myMin(min, matrix[i][j]);
		}
	}

	return min;
}

int myMin(int a, int b)
{
	return a < b ? a : b;
}
