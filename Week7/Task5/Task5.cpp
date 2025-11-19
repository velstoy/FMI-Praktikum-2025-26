#include<iostream>

void inputArray(char arr[], int size);
bool isArraySymmetric(char arr[], int size);

constexpr int N = 50;

int main()
{
	char arr[N];

	int n;
	std::cin >> n;

	inputArray(arr, n);

	if (isArraySymmetric(arr, n))
	{
		std::cout << "Yes, the array is symmetric.";
	}
	else
	{
		std::cout << "No, the array is not symmetric.";
	}

	return 0;
}

void inputArray(char arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

bool isArraySymmetric(char arr[], int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		if (!(arr[i] == arr[size - 1 - i]))
		{
			return false;
		}
	}

	return true;
}
