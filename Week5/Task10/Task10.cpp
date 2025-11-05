#include<iostream>

void fetchMaxAndMinNumWithKPrimeDivisors(int& a, int& b, int k);
int getPrimeDivisorNumber(int num);
bool isPrime(int num);

int main()
{
	int a, b, k;
	std::cin >> a >> b >> k;

	fetchMaxAndMinNumWithKPrimeDivisors(a, b, k);

	std::cout << a << " " << b;

	return 0;
}

void fetchMaxAndMinNumWithKPrimeDivisors(int& a, int& b, int k)
{
	int min = INT16_MAX;
	int max = INT16_MIN;
	for (int i = a; i <= b; i++)
	{
		if (getPrimeDivisorNumber(i) == k)
		{
			if (min > i)
			{
				min = i;
			}
			if (max < i)
			{
				max = i;
			}
		}
	}

	if (min != INT16_MAX && max != INT16_MIN)
	{
		a = min;
		b = max;
	}
}

int getPrimeDivisorNumber(int num)
{
	int count = 0;
	for (int i = 2; i <= num; i++)
	{
		if (isPrime(i) && num % i == 0)
		{
			count++;
		}
	}

	return count;
}

bool isPrime(int num)
{
	if (num % 2 == 0 && num != 2)
	{
		return false;
	}

	for (int i = 3; i * i < num; i += 2)
	{
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}
