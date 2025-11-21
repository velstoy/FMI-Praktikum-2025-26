#include<iostream>

constexpr size_t N = 50;

void inputMatrix(int matrix[][N], size_t size);
void printMatrixSequence(const int matrix[][N], size_t size);

int main()
{
	int matrix[N][N];

	int n;
	std::cin >> n;

	inputMatrix(matrix, n);

	printMatrixSequence(matrix, n);

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

void printMatrixSequence(const int matrix[][N], size_t size)
{
	bool flipEven = false, flipOdd = true;
	int offset = 0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i % 2 == 0)
			{
				if (flipEven)
				{
					std::cout << matrix[i - offset][size - j - 1] << " ";
				}
				else
				{
					std::cout << matrix[i - offset][j] << " ";
				}
			}
			else
			{
				if (flipOdd)
				{
					std::cout << matrix[size - i + offset][size - j - 1] << " ";
				}
				else
				{
					std::cout << matrix[size - i + offset][j] << " ";
				}
			}
		}
		if (i % 2 == 0)
		{
			flipEven ? flipEven = false : flipEven = true;
		}
		else
		{
			flipOdd ? flipOdd = false : flipOdd = true;
			offset++;
		}
	}
}
