#include<iostream>
#include<new>

void fillMatrixWithTruth(bool** matrix, size_t rows, size_t cols);
void fillRowAndColumn(bool** matrix, size_t rows, size_t cols, unsigned int r, unsigned int c);

int main()
{
	return 0;
}

void fillMatrixWithTruth(bool** matrix, size_t rows, size_t cols)
{
	if (!matrix)
	{
		return;
	}

	bool* trackRows = new (std::nothrow) bool[rows];

	if (!trackRows)
	{
		return;
	}

	for (size_t i = 0; i < rows; i++)
	{
		trackRows[i] = false;
	}

	bool* trackCols = new (std::nothrow) bool[cols];

	if (!trackCols)
	{
		return;
	}

	for (size_t i = 0; i < cols; i++)
	{
		trackCols[i] = false;
	}

	for (size_t i = 0; i < rows; i++)
	{
		if (!matrix[i])
		{
			return;
		}

		for (size_t j = 0; j < cols; j++)
		{
			if (matrix[i][j] == 1) 
			{
				trackRows[i] = true;
				trackCols[j] = true;
			}
		}
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (trackRows[i] && trackCols[j]) 
			{
				fillRowAndColumn(matrix, rows, cols, i, j);
			}
		}
	}

	delete[] trackRows;
	delete[] trackCols;
}

void fillRowAndColumn(bool** matrix, size_t rows, size_t cols, unsigned int r, unsigned int c)
{
	if (!matrix)
	{
		return;
	}

	for (size_t i = 0; i < rows; i++)
	{
		if (!matrix[i])
		{
			return;
		}

		matrix[i][c] = 1;
	}

	for (size_t i = 0; i < cols; i++)
	{
		matrix[r][i] = 1;
	}
}
