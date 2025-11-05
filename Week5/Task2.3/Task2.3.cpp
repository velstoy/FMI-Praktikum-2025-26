#include<iostream>

void inputArr(int arr[], size_t size);
bool checkIfMonotonicallyDecreasing(const int arr[], size_t size);

constexpr size_t N = 50;

int main()
{
	int arr[N];

	size_t n;
	std::cin >> n;

	inputArr(arr, n);

	if (checkIfMonotonicallyDecreasing(arr, n))
	{
		std::cout << "Тhe series is monotonically decreasing.";
	}
	else
	{
		std::cout << "Тhe series is not monotonically decreasing.";
	}

	return 0;
}

void inputArr(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

bool checkIfMonotonicallyDecreasing(const int arr[], size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		if (arr[i] < arr[i + 1]) {
			return false;
		}
	}
	return true;
}
