#include<iostream>

int* getDivisibleByK(const int* arr1, size_t size1, const int* arr2, size_t size2, size_t& k);

size_t findDivisibleArraySize(const int* arr1, size_t size1, const int* arr2, size_t size2, size_t k);

int main()
{
	size_t size1;
	std::cin >> size1;

	if (size1 == 0)
	{
		return -1;
	}

	int* arr1 = new (std::nothrow) int[size1];

	if (!arr1)
	{
		return -1;
	}

	for (size_t i = 0; i < size1; i++)
	{
		std::cin >> arr1[i];
	}

	size_t size2;
	std::cin >> size2;

	if (size2 == 0)
	{
		return -1;
	}

	int* arr2 = new (std::nothrow) int[size2];

	if (!arr2)
	{
		return -1;
	}

	for (size_t i = 0; i < size2; i++)
	{
		std::cin >> arr2[i];
	}

	size_t k;
	std::cin >> k;

	int* kDivisible = getDivisibleByK(arr1, size1, arr2, size2, k);

	delete[] arr1;
	arr1 = nullptr;

	delete[] arr2;
	arr2 = nullptr;

	if (!kDivisible)
	{
		return -1;
	}

	for (size_t i = 0; i < k; i++)
	{
		std::cout << kDivisible[i] << " ";
	}
	std::cout << std::endl;

	delete[] kDivisible;
	kDivisible = nullptr;

	return 0;
}

int* getDivisibleByK(const int* arr1, size_t size1, const int* arr2, size_t size2, size_t& k)
{
	if (!arr1 || !arr2)
	{
		return nullptr;
	}

	size_t size = findDivisibleArraySize(arr1, size1, arr2, size2, k);

	if (size == 0)
	{
		return nullptr;
	}

	int* res = new (std::nothrow) int[size];

	if (!res)
	{
		return nullptr;
	}

	int* begin = res;

	for (size_t i = 0; i < size1; i++)
	{
		if (arr1[i] % k == 0)
		{
			*res = arr1[i];
			res++;
		}
	}

	for (size_t i = 0; i < size2; i++)
	{
		if (arr2[i] % k == 0)
		{
			*res = arr2[i];
			res++;
		}
	}

	k = size;

	return begin;
}

size_t findDivisibleArraySize(const int* arr1, size_t size1, const int* arr2, size_t size2, size_t k)
{
	if (!arr1 || !arr2)
	{
		return 0;
	}

	int size = 0;

	for (size_t i = 0; i < size1; i++)
	{
		if (arr1[i] % k == 0)
		{
			size++;
		}
	}

	for (size_t i = 0; i < size2; i++)
	{
		if (arr2[i] % k == 0)
		{
			size++;
		}
	}

	return size;
}
