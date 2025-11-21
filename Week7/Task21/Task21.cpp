#include<iostream>

constexpr size_t N = 50;

void inputMatrix(int matrix[][N], size_t size);
void printMatrix(int matrix[][N], size_t size);
void addMatrices(const int matrix1[][N], const int matrix2[][N], size_t size, int result[][N]);
void multiplyMatrixWithNumber(const int matrix[][N], size_t size, int number, int result[][N]);
void multiplyMatrices(const int matrix1[][N], const int matrix2[][N], size_t size, int result[][N]);

int main()
{
	int matrix1[N][N], matrix2[N][N];

	int n;
	std::cin >> n;

	inputMatrix(matrix1, n);
	inputMatrix(matrix2, n);

	int addition[N][N];
	addMatrices(matrix1, matrix2, n, addition);

	std::cout << "Addition: " << std::endl;
	printMatrix(addition, n);

	int numberMultiplication[N][N];

	multiplyMatrixWithNumber(matrix1, n, 5, numberMultiplication);

	std::cout << "Multiplication with number: " << std::endl;
	printMatrix(numberMultiplication, n);

	int multiplication[N][N];

	multiplyMatrices(matrix1, matrix2, n, multiplication);

	std::cout << "Matrix multiplication: " << std::endl;
	printMatrix(multiplication, n);

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

void printMatrix(int matrix[][N], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void addMatrices(const int matrix1[][N], const int matrix2[][N], size_t size, int result[][N])
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}

void multiplyMatrixWithNumber(const int matrix[][N], size_t size, int number, int result[][N])
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			result[i][j] = matrix[i][j] * number;
		}
	}
}

void multiplyMatrices(const int matrix1[][N], const int matrix2[][N], size_t size, int result[][N])
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			int sum = 0;
			for (size_t k = 0; k < size; k++)
			{
				sum += matrix1[i][k] * matrix2[k][j];
			}

			result[i][j] = sum;
		}
	}
}
