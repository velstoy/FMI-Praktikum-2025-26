#include<iostream>

void inputArr(int arr[], size_t size);
bool areElementsOfSequenceDistinct(const int arr[], size_t size);

constexpr int N = 50;

int main()
{
	int arr[N];

	int n;
	std::cin >> n;

	inputArr(arr, n);
	
	if (areElementsOfSequenceDistinct(arr, n))
	{
		std::cout << "Yes, the sequence consists of distinct elements.";
	}
	else
	{
		std::cout << "No, the sequence does not consist of distinct elements.";
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

bool areElementsOfSequenceDistinct(const int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j]) {
				return false;
			}
		}
	}
	return true;
}
