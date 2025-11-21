#include<iostream>

constexpr size_t N = 50;

void inputMatrix(int matrix[][N], size_t size);
void printZigZagMatrix(const int matrix[][N], size_t size);

int main()
{
	int matrix[N][N];

	int n;
	std::cin >> n;

	inputMatrix(matrix, n);

	printZigZagMatrix(matrix, n);

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

void printZigZagMatrix(const int matrix[][N], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i % 2 == 0) {
				std::cout << matrix[i][j] << " ";
			}
			else
			{
				std::cout << matrix[i][size - j - 1] << " ";
			}
		}

		std::cout << std::endl;
	}
}
