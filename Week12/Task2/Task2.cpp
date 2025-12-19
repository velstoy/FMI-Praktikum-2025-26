#include<iostream>

int** createDynamicMatrix(int n, int m);
void freeMatrix(int** matrix, int n);

int main()
{
	int n, m;
	std::cin >> n >> m;

	int** matrix = createDynamicMatrix(n, m);

	freeMatrix(matrix, n);

	return 0;
}

int** createDynamicMatrix(int n, int m)
{
	int** matrix = new(std::nothrow) int* [n];

	if (!matrix)
	{
		return nullptr;
	}

	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new(std::nothrow) int[m];
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
