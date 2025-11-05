#include<iostream>

void inputArray(int arr[], int size);
int findMinMax(const int arr[], int size, int& minValue, int& maxValue);
int findMaxInArray(const int arr[], int size);
int myMax(int a, int b);
int findMinInArray(const int arr[], int size);
int myMin(int a, int b);
double getAverageOfArrElements(const int arr[], int size);
int myAbs(int a);

int main()
{
	constexpr int N = 5;
	int arr[N];
	inputArray(arr, N);
	int min = 0, max = 0;

	int closestToAvg = findMinMax(arr, N, min, max);

	std::cout << min << std::endl;
	std::cout << max << std::endl;
	std::cout << closestToAvg << std::endl;

	return 0;
}

void inputArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

int findMinMax(const int arr[], int size, int& minValue, int& maxValue)
{
	maxValue = findMaxInArray(arr, size);
	minValue = findMinInArray(arr, size);
	double avg = getAverageOfArrElements(arr, size);

	double closestToAvg = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (myAbs(avg - arr[i]) < myAbs(avg - closestToAvg))
		{
			closestToAvg = arr[i];
		}
	}

	return closestToAvg;
}

int findMaxInArray(const int arr[], int size)
{
	int max = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		max = myMax(max, arr[i]);
	}
	return max;
}

int myMax(int a, int b)
{
	return a > b ? a : b;
}

int findMinInArray(const int arr[], int size)
{
	int min = INT_MAX;
	for (int i = 0; i < size; i++)
	{
		min = myMin(min, arr[i]);
	}
	return min;
}

int myMin(int a, int b)
{
	return a < b ? a : b;
}

double getAverageOfArrElements(const int arr[], int size)
{
	double sum = 0;
	double count = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
		count++;
	}
	return sum / count;
}

int myAbs(int a)
{
	return a < 0 ? -a : a;
}
