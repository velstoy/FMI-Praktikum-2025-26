#include<iostream>

void inputArray(int arr[], size_t size);
double getAvgOfArrEl(const int arr[], size_t size);

constexpr size_t N = 50;

int main()
{
	int arr[N];
	size_t n;
	
	std::cin >> n;

	inputArray(arr, n);

	std::cout << getAvgOfArrEl(arr, n);

	return 0;
}

void inputArray(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

double getAvgOfArrEl(const int arr[], size_t size)
{
	double sum = 0;

	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum / size;
}
