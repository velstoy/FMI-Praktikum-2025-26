#include<iostream>

constexpr size_t N = 50;

void inputMatrix(int matrix[][N], size_t size);
bool isMagicalSquare(const int matrix[][N], size_t size);

int main()
{
	int matrix[N][N];
	int n;
	std::cin >> n;

	inputMatrix(matrix, n);

	std::cout << isMagicalSquare(matrix, n);

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

bool isMagicalSquare(const int matrix[][N], size_t size)
{
	int sumPrimary = 0, sumSecondary = 0, sumRow = 0, sumCol = 0;
	for (size_t i = 0; i < size; i++)
	{
		int currentSumRow = 0, currentSumCol = 0;

		for (size_t j = 0; j < size; j++)
		{
			currentSumRow += matrix[i][j];
			currentSumCol += matrix[j][i];
			if (i == j)
			{
				sumPrimary += matrix[i][j];
			}
			if (i == size - j - 1)
			{
				sumSecondary += matrix[i][j];
			}
		}

		if (currentSumCol != currentSumRow)
		{
			return false;
		}

		if (i == 0)
		{
			sumRow = currentSumRow;
			sumCol = currentSumCol;
		}
		else if (currentSumRow != sumRow || currentSumCol != sumCol)
		{
			return false;
		}
	}

	if (sumPrimary != sumSecondary || sumPrimary != sumRow)
	{
		return false;
	}

	return true;
}
