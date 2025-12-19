#include<iostream>
#include<new>

int* createDynamicArray(int size);
void inputArray(int* arr, int size);
int** findPoweredSets(int* arr, int size);
void outputJaggedArray(int** arr, int size);
void freeMatrix(int** matrix, int size);

int main()
{
	int size;
	std::cin >> size;

	int* arr = createDynamicArray(size);

	inputArray(arr, size);

	int** powerSet = findPoweredSets(arr, size);

	outputJaggedArray(powerSet, size);

	delete[] arr;
	freeMatrix(powerSet, size);

	return 0;
}

int* createDynamicArray(int size)
{
	if (size <= 0)
	{
		return nullptr;
	}

	int* arr = new(std::nothrow) int[size];

	if (arr == 0)
	{
		return nullptr;
	}

	return arr;
}

void inputArray(int* arr, int size)
{
	if (arr == nullptr)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

int** findPoweredSets(int* arr, int size)
{
	if (!arr || size <= 0)
	{
		return nullptr;
	}

	int setCount = (1 << size);

	int** powerSet = new(std::nothrow) int*[setCount];

	if (!powerSet)
	{
		return nullptr;
	}

	int currentMembers = 0;

	for (int i = 0; i < setCount; i++)
	{
		currentMembers ^= 1 << (i % size + 1);

		int currentSize = 0;

		for (int j = 0; j < size; j++)
		{
			if (currentMembers & (1 << j + 1))
			{
				currentSize++;
			}
		}

		powerSet[i] = new(std::nothrow) int[currentSize + 1];

		if (!powerSet[i])
		{
			return nullptr;
		}

		powerSet[i][0] = currentSize;

		int outerIndex = 1;

		for (int j = 0; j < size; j++)
		{
			if (currentMembers & (1 << j + 1))
			{
				powerSet[i][outerIndex] = arr[j];
				outerIndex++;
			}
		}
	}

	return powerSet;
}

void outputJaggedArray(int** arr, int size)
{
	if (!arr)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (!arr[i])
		{
			continue;
		}

		for (int j = 0; j < arr[i][0]; j++)
		{
			std::cout << arr[i][j + 1] << " ";
		}

		std::cout << std::endl;
	}
}

void freeMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}