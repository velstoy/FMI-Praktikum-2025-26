#include<iostream>

long processNum(long);
long reverseNum(long);
long getMaxMonotonicallyDecreasing(long num);
int getNumLength(long);
long pow10(long);
long myMax(long a, long b);

int main()
{
	long num;
	std::cin >> num;

	std::cout << processNum(num) << std::endl;

	return 0;
}

long processNum(long num)
{
	long max = LONG_MIN;

	int numLen = getNumLength(num);

	for (int i = 0; i < numLen; i++)
	{
		max = myMax(max, getMaxMonotonicallyDecreasing(num));
		num %= pow10(numLen - i - 1);
	}

	return max;
}

long reverseNum(long num)
{
	long res = 0;

	while (num != 0)
	{
		res *= 10;
		res += num % 10;
		res /= 10;
	}

	return res;
}

long getMaxMonotonicallyDecreasing(long num)
{
	int numLen = getNumLength(num);

	int res = 0;

	for (int i = 0; i < numLen; i++)
	{
		long currentPower = pow10(numLen - i - 1);

		if (res != 0 && res % 10 < num / currentPower)
		{
			return res;
		}

		res *= 10;
		res += num / currentPower;

		num %= currentPower;
	}

	return res;
}

int getNumLength(long num)
{
	int count = 0;

	while (num != 0)
	{
		count++;
		num /= 10;
	}

	return count;
}

long pow10(long pow)
{
	long res = 1;

	for (int i = 0; i < pow; i++)
	{
		res *= 10;
	}

	return res;
}

long myMax(long a, long b)
{
	return a > b ? a : b;
}
