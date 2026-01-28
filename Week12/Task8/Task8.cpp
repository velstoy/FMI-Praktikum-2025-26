#include<iostream>

void removeRowAndCol(int**& matrix, size_t& rows, size_t& cols, unsigned int r, unsigned int c);

void freeMatrix(int** matrix, size_t rows);

void printMatrix(int** matrix, size_t rows, size_t cols);

int main()
{
	size_t rows, cols;
	std::cin >> rows >> cols;

	int** matrix = new (std::nothrow) int*[rows];

	if (!matrix)
	{
		return -1;
	}

	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new (std::nothrow) int[cols];

		if (!matrix[i])
		{
			freeMatrix(matrix, i - 1);
			return -1;
		}
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	unsigned int r, c;
	std::cin >> r >> c;

	removeRowAndCol(matrix, rows, cols, r, c);

	printMatrix(matrix, rows, cols);

	freeMatrix(matrix, rows);

	return 0;
}

void removeRowAndCol(int**& matrix, size_t& rows, size_t& cols, unsigned int r, unsigned int c)
{
	if (!matrix)
	{
		return;
	}

	int** newMatrix = new (std::nothrow) int* [rows - 1];

	if (!newMatrix)
	{
		return;
	}

	int** iter = newMatrix;

	int newRowIndex = 0;

	for (size_t i = 0; i < rows; i++)
	{
		if (!matrix[i])
		{
			freeMatrix(newMatrix, i - 1);

			return;
		}

		if (i == r)
		{
			continue;
		}

		newMatrix[newRowIndex] = new int[cols - 1];

		if (!newMatrix[newRowIndex])
		{
			freeMatrix(newMatrix, newRowIndex - 1);

			return;
		}

		int newColIndex = 0;

		for (size_t j = 0; j < cols; j++)
		{
			if (j == c)
			{
				continue;
			}

			newMatrix[newRowIndex][newColIndex++] = matrix[i][j];
		}

		newRowIndex++;
	}

	freeMatrix(matrix, rows);

	matrix = newMatrix;

	rows -= 1;
	cols -= 1;
}

void freeMatrix(int** matrix, size_t rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void printMatrix(int** matrix, size_t rows, size_t cols)
{
	if (!matrix)
	{
		return;
	}

	for (size_t i = 0; i < rows; i++)
	{
		if (!matrix[i]) 
		{
			return;
		}

		for (size_t j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
