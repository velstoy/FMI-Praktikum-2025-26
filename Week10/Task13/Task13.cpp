#include<iostream>

constexpr int N = 1024;

void inputArray(int arr[], int size);
void outputAllSubarrays(int arr[], int size);

int main()
{
	int arr[N];

	int n;
	std::cin >> n;

	if (n <= 0 || n > N)
	{
		std::cout << "Size out of bounds!" << std::endl;
		return -1;
	}

	inputArray(arr, n);

	outputAllSubarrays(arr, n);

	return 0;
}

void inputArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void outputAllSubarrays(int arr[], int size)
{
	uint32_t hist = 0;

	for (int i = 0; i < (1 << size); i++)
	{
		std::cout << "[ ";
		for (int j = 0; j < size; j++)
		{
			if ((i >> j) & 1) {
				std::cout << arr[j] << " ";
			}
		}
		std::cout << "]";
	}
}
