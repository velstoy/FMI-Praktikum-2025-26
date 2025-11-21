#include<iostream>

void inputArray(int arr[], size_t size);
void outputArray(const int arr[], size_t size);
void increseArrayNumByOne(int arr[], size_t size);

constexpr size_t N = 5;

int main()
{
	int arr[N];
	inputArray(arr, N);

	increseArrayNumByOne(arr, N);

	outputArray(arr, N);

	return 0;
}

void inputArray(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void outputArray(const int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void increseArrayNumByOne(int arr[], size_t size)
{
	int carryover = 0;

	for (size_t i = size - 1; i > 0; i--)
	{
		if (i == size - 1)
		{
			arr[i]++;
		}
		else
		{
			arr[i] += carryover;
		}

		if (arr[i] > 9)
		{
			arr[i] = 0;
			carryover = 1;
		}
		else
		{
			carryover = 0;
		}
	}
}
