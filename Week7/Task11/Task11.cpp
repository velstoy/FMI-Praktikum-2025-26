#include<iostream>

void inputArray(int arr[], int size);
int findMissingElementInPermutation(int arr[], int size);

constexpr int N = 20;

int main()
{
	int arr[N];
	inputArray(arr, N);

	int missingElement = findMissingElementInPermutation(arr, N);

	if (missingElement != -1)
	{
		std::cout << missingElement << std::endl;
	}
	else
	{
		std::cout << "Incorrect input for array permutation!" << std::endl;
		return 1;
	}

	return 0;
}

void inputArray(int arr[], int size)
{
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}
}

int findMissingElementInPermutation(int arr[], int size)
{
	for (int i = 0; i <= size; i++)
	{
		bool found = false;
		for (int j = 0; j < size; j++)
		{
			if (i == arr[j])
			{
				found = true;
				break;
			}
		}

		if (!found)
		{
			return i;
			break;
		}
	}
	return -1;
}
