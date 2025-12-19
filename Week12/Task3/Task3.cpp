#include<iostream>

int*** createDynamicCube(int n, int m, int p);
void freeCube(int*** cube, int n, int m);

int main()
{
	int n, m, p;
	std::cin >> n >> m >> p;

	int*** cube = createDynamicCube(n, m, p);

	freeCube(cube, n, m);

	return 0;
}

int*** createDynamicCube(int n, int m, int p)
{
	int*** cube = new(std::nothrow) int** [n];

	if (cube != nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			cube[i] = new(std::nothrow) int* [m];

			if (cube[i] != nullptr)
			{
				for (int j = 0; j < m; j++)
				{
					cube[i][j] = new(std::nothrow) int[p];
				}
			}
		}
	}
	
	return cube;
}

void freeCube(int*** cube, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			delete[] cube[i][j];
		}
		delete[] cube[i];
	}

	delete[] cube;
}
