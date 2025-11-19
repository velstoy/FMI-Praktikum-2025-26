#include<iostream>

void inputArray(int arr[], int size);
bool checkIfElementsAreDistinct(const int arr[], int size);

constexpr int N = 50;

int main()
{
	int arr[N];

	int n;
	std::cin >> n;

	inputArray(arr, n);

	if (checkIfElementsAreDistinct(arr, n))
	{
		std::cout << "Yes, the sequence consists of distinct elements.";
	}
	else
	{
		std::cout << "No, the sequence does not consist of distinct elements.";
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

bool checkIfElementsAreDistinct(const int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				return false;
			}
		}
	}

	return true;
}
