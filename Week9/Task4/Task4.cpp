#include<iostream>

constexpr size_t N = 50;

void inputMatrix(int matrix[][N], size_t rows, size_t cols);
void printAtIndexInMatrix(const int matrix[][N], size_t rows, size_t cols, int indexRow, int indexCol);

int main()
{
	int matrix[N][N];

	size_t rows, cols;
	std::cin >> rows >> cols;

	if (rows > N || cols > N)
	{
		std::cout << "Incorrect matrix size param!";
		return 1;
	}

	inputMatrix(matrix, rows, cols);

	int indexRow, indexCol;
	std::cin >> indexRow >> indexCol;

	printAtIndexInMatrix(matrix, rows, cols, indexRow, indexCol);

	return 0;
}

void inputMatrix(int matrix[][N], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

void printAtIndexInMatrix(const int matrix[][N], size_t rows, size_t cols, int indexRow, int indexCol)
{
	if (indexRow < 0 || indexCol < 0 || indexRow >= rows || indexCol >= cols)
	{
		std::cout << "Incorrect index!" << std::endl;
		return;
	}

	std::cout << "Result at row " << indexRow << " and col " << indexCol << " is: " << *(*(matrix + indexRow) + indexCol) << std::endl;
}
