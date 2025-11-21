#include<iostream>

constexpr size_t N = 50;

void inputMatrix(int matrix[][N], size_t size);
void printMatrix(const int matrix[][N], size_t size);
void rotateMatrixRight(int matrix[][N], size_t size);
//void copyMatrix(int from[][N], int to[][N], size_t size);

int main()
{
	int matrix[N][N];

	int n;
	std::cin >> n;

	inputMatrix(matrix, n);

	rotateMatrixRight(matrix, n);

	printMatrix(matrix, n);

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


void printMatrix(const int matrix[][N], size_t size)
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


void rotateMatrixRight(int matrix[][N], size_t size)
{
	int rotated[N][N];
	for (size_t i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			rotated[i][size - j - 1] = matrix[i][j];
		}
	}

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			matrix[size - j - 1][size - i - 1] = rotated[i][j];
		}
	}
}

//void copyMatrix(int from[][N], int to[][N], size_t size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		for (size_t j = 0; j < size; j++)
//		{
//			to[i][j] = from[i][j];
//		}
//	}
//}
