#include<iostream>

constexpr size_t N = 6;

void inputMatrix(int matrix[][N], size_t size);
void printSaddlePoint(const int matrix[][N], size_t size);
int myMin(int a, int b);
int myMax(int a, int b);

int main()
{
	int matrix[N][N];

	int n;
	std::cin >> n;

	inputMatrix(matrix, n);

	printSaddlePoint(matrix, n);

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

void printSaddlePoint(const int matrix[][N], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		int maxRow = INT_MIN, minCol = INT_MAX;
		for (size_t j = 0; j < size; j++)
		{
			maxRow = myMax(maxRow, matrix[i][j]);
			minCol = myMin(minCol, matrix[j][i]);
		}

		if (maxRow == minCol)
		{
			std::cout << "Saddle point: " << maxRow;
			return;
		}
	}

	std::cout << "Could not find saddle point.";
}

int myMin(int a, int b)
{
	return a < b ? a : b;
}

int myMax(int a, int b)
{
	return a > b ? a : b;
}
