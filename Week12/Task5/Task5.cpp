#include<iostream>
#include<new>

int** getProductOfMatrices(int**, size_t, size_t, int**, size_t, size_t);
int** createDynamicMatrix(size_t n, size_t m);
void freeMatrix(int** matrix, size_t n);
void inputMatrix(int** matrix, size_t rows, size_t cols);
void outputMatrix(int** matrix, size_t rows, size_t cols);

int main()
{
	size_t rows1, cols1;
	std::cin >> rows1 >> cols1;

	int** matrix1 = createDynamicMatrix(rows1, cols1);

	inputMatrix(matrix1, rows1, cols1);

	size_t rows2, cols2;
	std::cin >> rows2 >> cols2;

	int** matrix2 = createDynamicMatrix(rows2, cols2);

	inputMatrix(matrix2, rows2, cols2);

	int** product = getProductOfMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);

	outputMatrix(product, rows1, cols2);

	freeMatrix(matrix1, rows1);
	freeMatrix(matrix2, rows2);
	freeMatrix(product, rows1);

	return 0;
}

int** getProductOfMatrices(int** matrix1, size_t rows1, size_t cols1, int** matrix2, size_t rows2, size_t cols2)
{
	if (!matrix1 || !matrix2 || cols1 != rows2 || 
		rows1 <= 0 || cols1 <= 0 || rows2 <= 0 || cols2 <= 0)
	{
		return nullptr;
	}

	int** product = new(std::nothrow) int* [rows1];

	if (!product)
	{
		return nullptr;
	}

	for (size_t i = 0; i < rows1; i++)
	{
		product[i] = new(std::nothrow) int[cols2];

		if (!product[i] || !matrix1[i])
		{
			return nullptr;
		}

		for (size_t j = 0; j < cols2; j++)
		{
			product[i][j] = 0;

			for (size_t k = 0; k < rows2; k++)
			{
				if (!matrix2[k]) 
				{
					return nullptr;
				}

				product[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	return product;
}

int** createDynamicMatrix(size_t n, size_t m)
{
	int** matrix = new(std::nothrow) int* [n];

	if (!matrix || n <= 0 || m <= 0)
	{
		return nullptr;
	}

	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new(std::nothrow) int[m];
	}

	return matrix;
}

void freeMatrix(int** matrix, size_t n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void inputMatrix(int** matrix, size_t rows, size_t cols)
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
			std::cin >> matrix[i][j];
		}
	}
}

void outputMatrix(int** matrix, size_t rows, size_t cols)
{
	if (!matrix)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return;
	}

	for (size_t i = 0; i < rows; i++)
	{
		if (!matrix[i])
		{
			std::cout << "Null pointer exception!" << std::endl;
			return;
		}

		for (size_t j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}
}
