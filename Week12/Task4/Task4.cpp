#include<iostream>

int** getTransposedMatrix(int** matrix, int rows, int cols);
int** createDynamicMatrix(int n, int m);
void freeMatrix(int** matrix, int n);

int main()
{
	int n, m;
	std::cin >> n >> m;

	int** matrix = createDynamicMatrix(n, m);

	int** transposed = getTransposedMatrix(matrix, n, m);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << transposed[i][j] << " ";
		}
		std::cout << std::endl;
	}

	freeMatrix(matrix, n);
	freeMatrix(transposed, m);

	return 0;
}

int** getTransposedMatrix(int** matrix, int rows, int cols)
{
	if (matrix == nullptr)
	{
		return nullptr;
	}

	int** transposed = new(std::nothrow) int* [cols];

	if (transposed != nullptr)
	{
		for (int i = 0; i < cols; i++)
		{
			transposed[i] = new(std::nothrow) int[rows];

			if (transposed[i] == nullptr)
			{
				return nullptr;
			}

			for (int j = 0; j < rows; j++)
			{
				if (matrix[j] == nullptr)
				{
					return nullptr;
				}

				transposed[i][j] = matrix[j][i];
			}
		}
	}

	return transposed;
}

int** createDynamicMatrix(int n, int m)
{
	int** matrix = new(std::nothrow) int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new(std::nothrow) int[m];
		for (int j = 0; j < m; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	return matrix;
}

void freeMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}
