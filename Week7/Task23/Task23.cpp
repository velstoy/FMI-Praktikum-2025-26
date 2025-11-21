#include<iostream>

constexpr size_t N = 50;

void inputMatrix(int matrix[][N], size_t size);
void spiralPrintMatrix(const int matrix[][N], size_t size);

int main()
{
	int matrix[N][N];

	int n;
	std::cin >> n;

	inputMatrix(matrix, n);

	spiralPrintMatrix(matrix, n);

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

void spiralPrintMatrix(const int matrix[][N], size_t size)
{
	int row = 0, col = 0;
	int direction = 0;

	std::cout << matrix[row][col] << " ";

	int printed = 1;

	int globalIndex = 1, repetitions = size;

	while (printed < size * size)
	{
		switch (direction)
		{
		default:
			direction = 0;
		case 0:
			col++;
			break;
		case 1:
			row++;
			break;
		case 2:
			col--;
			break;
		case 3:
			row--;
		}

		std::cout << matrix[row][col] << " ";

		printed++;

		globalIndex++;

		if (globalIndex >= repetitions)
		{
			globalIndex = 0;
			direction++;
			if (direction % 2 == 1)
			{
				repetitions--;
			}
		}
	}	
}
