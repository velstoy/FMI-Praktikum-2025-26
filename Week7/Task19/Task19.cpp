#include<iostream>

constexpr size_t N = 50;

void inputMatrix(int matrix[][N], size_t size);
void printMatrux(int matrix[][N], size_t size);
void transposeMatrix(int matrix[][N], size_t size);

int main()
{
	int matrix[N][N];

	int n;
	std::cin >> n;

	inputMatrix(matrix, n);

	transposeMatrix(matrix, n);

	printMatrux(matrix, n);

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

void printMatrux(int matrix[][N], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void transposeMatrix(int matrix[][N], size_t size)
{
	int transposed[N][N];

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			transposed[j][i] = matrix[i][j];
		}
	}

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			matrix[i][j] = transposed[i][j];
		}
	}
}
