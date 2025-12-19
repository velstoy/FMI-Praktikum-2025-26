#include<iostream>

int* createDynamicArray(int n);

int main() 
{
	int n;
	std::cin >> n;

	int* arr = createDynamicArray(n);

	delete[] arr;

	arr = nullptr;

	return 0;
}

int* createDynamicArray(int n)
{
	int* arr = nullptr;
	if (n > 0)
	{
		arr = new(std::nothrow) int[n];
	}

	return arr;
}
