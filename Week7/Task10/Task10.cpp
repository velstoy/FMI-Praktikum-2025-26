#include<iostream>

void inputArray(int arr[], int size);
bool isPermutation(const int arr1[], const int arr2[], int size);

constexpr int N = 50;

int main()
{
	int n;
	std::cin >> n;

	int arr1[N], arr2[N];
	inputArray(arr1, n);
	inputArray(arr2, n);

	std::cout << std::boolalpha << isPermutation(arr1, arr2, n);

	return 0;
}

void inputArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

bool isPermutation(const int arr1[], const int arr2[], int size)
{
	const int histN = 10;
	int hist1[histN] = {};
	int hist2[histN] = {};
	
	for (int i = 0; i < size; i++)
	{
		hist1[arr1[i]]++;
		hist2[arr2[i]]++;
	}

	for (int i = 0; i < size; i++)
	{
		if (hist1[i] != hist2[i]) {
			return false;
		}
	}

	return true;
}