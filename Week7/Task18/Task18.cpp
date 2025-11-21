#include<iostream>

constexpr size_t N = 50;

void inputMatrix(int matrix[][N], size_t size);
bool isMatrixTriangular(const int matrix[][N], size_t size);

int main()
{
	int matrix[N][N];

	int n;
	std::cin >> n;

	inputMatrix(matrix, n);

	std::cout << std::boolalpha << isMatrixTriangular(matrix, n);

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

bool isMatrixTriangular(const int matrix[][N], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i > j && matrix[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}
