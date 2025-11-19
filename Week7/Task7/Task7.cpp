#include<iostream>

void inputArray(int arr[], int size);
void printArray(const int arr[], int size);
void getArrayUnification(const int arr1[], const int arr2[], int size1, int size2, int result[], int& resultSize);
void getArrayCrossection(const int arr1[], const int arr2[], int size1, int size2, int result[], int& resultSize);
void getArrayDifference(const int arr1[], const int arr2[], int size1, int size2, int result[], int& resultSize);
bool Contains(const int arr[], int size, int element);

constexpr int N = 50;

int main()
{
	int size1;
	std::cin >> size1;

	int arr1[N];
	inputArray(arr1, size1);

	int size2;
	std::cin >> size2;

	int arr2[N];
	inputArray(arr2, size2);

	int unified[N];
	int unifiedSize = 0;

	getArrayUnification(arr1, arr2, size1, size2, unified, unifiedSize);

	int crosssection[N];
	int crosssectionSize = 0;
	
	getArrayCrossection(arr1, arr2, size1, size2, crosssection, crosssectionSize);

	int difference[N];
	int differenceSize = 0;

	getArrayDifference(arr1, arr2, size1, size2, difference, differenceSize);

	printArray(unified, unifiedSize);
	printArray(crosssection, crosssectionSize);
	printArray(difference, differenceSize);

}

void inputArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void printArray(const int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

void getArrayUnification(const int arr1[], const int arr2[], int size1, int size2, int result[], int& resultSize)
{
	int masterIndex = 0;
	for (int i = 0; i < size1; i++)
	{
		if (!Contains(result, resultSize, arr1[i]))
		{
			result[masterIndex] = arr1[i];
			resultSize++;
			masterIndex++;
		}
	}
	for (int i = 0; i < size2; i++)
	{
		if (!Contains(result, resultSize, arr2[i]))
		{
			result[masterIndex] = arr2[i];
			resultSize++;
			masterIndex++;
		}
	}
}

void getArrayCrossection(const int arr1[], const int arr2[], int size1, int size2, int result[], int& resultSize)
{
	int masterIndex = 0;
	for (int i = 0; i < size1; i++)
	{
		if (Contains(arr2, size2, arr1[i]) && !Contains(result, resultSize, arr1[i]))
		{
			result[masterIndex] = arr1[i];
			masterIndex++;
			resultSize++;
		}
	}
}

void getArrayDifference(const int arr1[], const int arr2[], int size1, int size2, int result[], int& resultSize)
{
	int masterIndex = 0;
	for (int i = 0; i < size1; i++)
	{
		if (!Contains(arr2, size2, arr1[i]) && !Contains(result, resultSize, arr1[i]))
		{
			result[masterIndex] = arr1[i];
			masterIndex++;
			resultSize++;
		}
	}
}

bool Contains(const int arr[], int size, int element)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == element)
		{
			return true;
		}
	}

	return false;
}
