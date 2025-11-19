#include<iostream>

void inputArray(int arr[], int size);
bool checkIfMonotonicallyDecreasing(const int arr[], int size);

constexpr int N = 50;

int main()
{
	int arr[N];
	int n;
	std::cin >> n;
	inputArray(arr, n);

	if (!checkIfMonotonicallyDecreasing(arr, n))
	{
		std::cout << "The series is not monotonically decreasing.";
	}
	else
	{
		std::cout << "The series is monotonically decreasing.";
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

bool checkIfMonotonicallyDecreasing(const int arr[], int size)
{
	int j = 1;
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[j] > arr[i])
		{
			return false;
		}
		j++;
	}

	return true;
}