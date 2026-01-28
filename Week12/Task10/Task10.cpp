#include<iostream>

int** filter(int** matrix, size_t rows, size_t cols, double minAvg);
double getAvg(int* arr, size_t size);
size_t getNewMatrixRows(int** matrix, size_t rows, size_t cols, double minAvg);

int main()
{
	return 0;
}

int** filter(int** matrix, size_t rows, size_t cols, double minAvg)
{
	if (!matrix)
	{
		return nullptr;
	}

	size_t newMatrixSize = getNewMatrixRows(matrix, rows, cols, minAvg);

	int** newMatrix = new (std::nothrow) int* [newMatrixSize];

	if (!newMatrix)
	{
		return nullptr;
	}

	int newRowIndex = 0;

	for (size_t i = 0; i < rows; i++)
	{
		if (!matrix[i])
		{
			return nullptr;
		}

		if (getAvg(matrix[i], cols) < minAvg)
		{
			continue;
		}

		newMatrix[newRowIndex] = new (std::nothrow) int[cols];

		if (!newMatrix[newRowIndex])
		{
			return nullptr;
		}

		for (size_t j = 0; j < cols; j++)
		{
			newMatrix[newRowIndex][j] = matrix[i][j];
		}

		newRowIndex++;
	}

	return nullptr;
}

double getAvg(int* arr, size_t size)
{
	double sum = 0;

	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum / size;
}

size_t getNewMatrixRows(int** matrix, size_t rows, size_t cols, double minAvg)
{
	if (!matrix)
	{
		return 0;
	}

	size_t size = 0;

	for (size_t i = 0; i < rows; i++)
	{
		if (!matrix[i])
		{
			return 0;
		}

		if (getAvg(matrix[i], cols) >= minAvg)
		{
			size++;
		}
	}

	return size;
}