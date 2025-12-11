#include<iostream>

constexpr size_t N = 50;

void inputArray(int arr[], size_t size);
void outputAtIndex(const int arr[], size_t size, int index);

int main()
{
	int arr[N];
	int size;
	std::cin >> size;

	inputArray(arr, size);

	int index;
	std::cin >> index;

	outputAtIndex(arr, size, index);
}

void inputArray(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void outputAtIndex(const int arr[], size_t size, int index)
{
	if (index < 0 || index >= size)
	{
		std::cout << "Incorrect index!";
		return;
	}

	std::cout << "Located at index " << index << ": " << * (arr + index) << std::endl;
}
