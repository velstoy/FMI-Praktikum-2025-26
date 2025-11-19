#include<iostream>

void inputArray(int arr[], int size);
void printArray(const int arr[], int size);

void flipFirstKNumbers(int arr[], int size, int k);

constexpr int N = 50;

int main()
{
	int arr[N];

	int n;
	std::cin >> n;

	inputArray(arr, n);

	int k;
	std::cin >> k;

	flipFirstKNumbers(arr, n, k);

	printArray(arr, n);

	return 0;
}

void inputArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void printArray(const int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

void flipFirstKNumbers(int arr[], int size, int k)
{
	int flipped[N];

	for (int i = 0; i < k; i++)
	{
		flipped[i] = arr[k - i - 1];
	}

	for (int i = 0; i < k; i++)
	{
		arr[i] = flipped[i];
	}
}
