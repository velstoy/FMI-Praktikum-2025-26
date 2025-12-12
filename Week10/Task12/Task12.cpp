#include<iostream>

const int N = 1024;

int getRepeatedNumber(int arr[], int size);

int main()
{
	int arr[N];

	int size;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	std::cout << getRepeatedNumber(arr, size);

	return 0;
}

int getRepeatedNumber(int arr[], int size)
{
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		num ^= arr[i];
	}
	return num;
}
