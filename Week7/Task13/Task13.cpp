#include<iostream>

void inputArray(int arr[], size_t size);
void outputArray(const int arr[], size_t size);
void getElementsInInterval(const int arr[], size_t arrSize, int res[], size_t& resSize, int begin, int end);

constexpr size_t N = 50;

int main()
{
	int arr[N];
	size_t n;
	std::cin >> n;

	if (n <= 0)
	{
		std::cout << "Incorrect size for array!" << std::endl;
		return 1;
	}

	inputArray(arr, n);

	int begin, end;

	std::cin >> begin >> end;

	int res[N];

	size_t resSize = 0;

	getElementsInInterval(arr, n, res, resSize, begin, end);

	outputArray(res, resSize);

	return 0;
}

void inputArray(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void outputArray(const int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

void getElementsInInterval(const int arr[], size_t arrSize, int res[], size_t& resSize, int begin, int end)
{
	int masterIndex = 0;
	for (size_t i = 0; i < arrSize; i++)
	{
		if (arr[i] >= begin && arr[i] <= end) {
			res[masterIndex] = arr[i];
			masterIndex++;
			resSize++;
		}
	}
}
