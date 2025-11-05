#include<iostream>

void inputArr(char arr[], size_t size);
bool isArraySymmetric(const char arr[], size_t size);

constexpr int N = 50;

int main()
{
	char arr[N];

	int n;
	std::cin >> n;

	inputArr(arr, n);

	if (isArraySymmetric(arr, n))
	{
		std::cout << "Yes, the array is symmetric.";
	}
	else
	{
		std::cout << "No, the array is not symmetric.";
	}

	return 0;
}

void inputArr(char arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

bool isArraySymmetric(const char arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] != arr[size - i - 1]) {
			return false;
		}
	}
	return true;
}
