#include<iostream>

int findMinMax(const int arr[], int size, int& minValue, int& maxValue);
int findMinValueInArray(const int arr[], int size);
int myMin(int a, int b);
int findMaxValueInArray(const int arr[], int size);
int myMax(int a, int b);
double calculateArrayAverage(const int arr[], int size);
double myAbs(double a);
int getClosestToAverage(const int arr[], int size);
void inputArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

constexpr int N = 5;

int main()
{
	int arr[N];
	inputArray(arr, N);

	int minValue = -1, maxValue = -1;

	int average = findMinMax(arr, N, minValue, maxValue);

	std::cout << "Min: " << minValue << std::endl;
	std::cout << "Max: " << maxValue << std::endl;
	std::cout << "Closest to Average: " << average << std::endl;

	return 0;
}

int findMinMax(const int arr[], int size, int& minValue, int& maxValue)
{
	minValue = findMinValueInArray(arr, size);
	maxValue = findMaxValueInArray(arr, size);

	double arrayAverage = calculateArrayAverage(arr, size);

	int closestToAverage = getClosestToAverage(arr, size);

	return closestToAverage;
}

int findMinValueInArray(const int arr[], int size)
{
	int min = arr[0];

	for (int i = 1; i < size; i++)
	{
		min = myMin(arr[i], min);
	}

	return min;
}

int myMin(int a, int b)
{
	return a < b ? a : b;
}

int findMaxValueInArray(const int arr[], int size)
{
	int max = arr[0];

	for (int i = 1; i < size; i++)
	{
		max = myMax(arr[i], max);
	}

	return max;
}

int myMax(int a, int b)
{
	return a > b ? a : b;
}

double calculateArrayAverage(const int arr[], int size)
{
	double sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum / size;
}

double myAbs(double a)
{
	return a < 0 ? -a : a;
}

int getClosestToAverage(const int arr[], int size)
{
	int closest = arr[0];

	double average = calculateArrayAverage(arr, size);

	for (int i = 1; i < size; i++)
	{
		closest = myAbs(average - arr[i]) < myAbs(average - closest) ? arr[i] : closest;
	}

	return closest;
}
