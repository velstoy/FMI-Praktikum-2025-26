#include<iostream>

constexpr size_t N = 50;

void inputMatrix(int matrix[][N], size_t size);
void printMainDiagonal(const int matrix[][N], size_t size);
void printSecondaryDiagonal(const int matrix[][N], size_t size);

int main()
{
	int matrix[N][N];

	size_t n;
	std::cin >> n;

	if (n <= 0 || n > N)
	{
		std::cout << "Invalid matrix size!";
		return 1;
	}

	inputMatrix(matrix, n);

	printMainDiagonal(matrix, n);
	printSecondaryDiagonal(matrix, n);

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

void printMainDiagonal(const int matrix[][N], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i == j) 
			{
				std::cout << matrix[i][j] << " ";
			}
		}
	}

	std::cout << std::endl;
}

void printSecondaryDiagonal(const int matrix[][N], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i == size - j - 1)
			{
				std::cout << matrix[i][j] << " ";
			}
		}
	}

	std::cout << std::endl;
}
