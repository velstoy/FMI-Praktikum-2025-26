#include<iostream>

void inputArray(int arr[], int size);
void outputTimesFound(const int arr[], int size);

constexpr int N = 20;

int main()
{
	int arr[N];
	inputArray(arr, N);

	outputTimesFound(arr, N);

	return 0;
}

void inputArray(int arr[], int size)
{
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}
}

void outputTimesFound(const int arr[], int size)
{
	int histogram[N] = {};

	for (int i = 0; i < size; i++)
	{
		histogram[arr[i]]++;
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << "Found " << i << " " << histogram[i] << " times!" << std::endl;
	}
}
