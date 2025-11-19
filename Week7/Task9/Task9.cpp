#include<iostream>

void inputArray(int arr[], int size);
void printFirstRepeatingInArray(const int arr[], int size);

constexpr int N = 50;

int main()
{
	int arr[N];

	int n;
	std::cin >> n;

	inputArray(arr, n);

	printFirstRepeatingInArray(arr, n);

	return 0;
}

void inputArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void printFirstRepeatingInArray(const int arr[], int size)
{
	int histogram[N] = {};
	for (int i = 0; i < size; i++)
	{
		if (histogram[arr[i]] > 0)
		{
			std::cout << arr[i];
			break;
		}

		histogram[arr[i]]++;
	}
}
