#include<iostream>

void inputArray(int arr[], int size);
bool areArraysLinearlyDependent(const int arr1[], const int arr2[], int size);

constexpr int N = 50;

int main()
{
	int n;
	std::cin >> n;

	int arr1[N], arr2[50];
	inputArray(arr1, n);
	inputArray(arr2, n);

	if (areArraysLinearlyDependent(arr1, arr2, n))
	{
		std::cout << "Yes, the arrays are linearly dependent.";
	}
	else
	{
		std::cout << "No, the arrays are not linearly dependent.";
	}

	return 0;
}

void inputArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

bool areArraysLinearlyDependent(const int arr1[], const int arr2[], int size)
{
	int divisionFactor = arr2[0] / arr1[0];
	for (int i = 0; i < size; i++)
	{
		if (arr2[i] % arr1[i] != 0 || arr2[i] / arr1[i] != divisionFactor)
		{
			return false;
		}
	}

	return true;
}
