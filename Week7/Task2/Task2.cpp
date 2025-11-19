#include<iostream>

void inputArray(int arr[], int size);
double calculateAverageInArray(const int arr[], int size);

constexpr int N = 50;

int main()
{
	int arr[N];
	int n;
	std::cin >> n;

	inputArray(arr, n);

	std::cout << "Average: " << calculateAverageInArray(arr, n);

	return 0;
}

void inputArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

double calculateAverageInArray(const int arr[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum / size;
}