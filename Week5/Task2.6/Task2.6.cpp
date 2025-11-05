#include<iostream>

void inputArr(int arr[], rsize_t size);
bool areLinearlyDependant(const int arr1[], const int arr2[], size_t size);

constexpr size_t N = 50;

int main()
{
	int arr1[N], arr2[N];

	size_t n;
	std::cin >> n;

	inputArr(arr1, n);
	inputArr(arr2, n);

	if (areLinearlyDependant(arr1, arr2, n))
	{
		std::cout << "Yes, the arrays are linearly dependent.";
	}
	else
	{
		std::cout << "No, the arrays are not linearly dependent.";
	}

	return 0;
}

void inputArr(int arr[], rsize_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

bool areLinearlyDependant(const int arr1[], const int arr2[], size_t size)
{
	int factor = arr2[0] / arr1[0];
	int remainder = arr2[0] % arr1[0];

	for (size_t i = 1; i < size; i++)
	{
		if (factor != arr2[i] / arr1[i] || remainder != arr2[i] % arr1[i])
		{
			return false;
		}
	}
	return true;
}
