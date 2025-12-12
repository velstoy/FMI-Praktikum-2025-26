#include<iostream>

bool isKPartOfN(int n, int k);
int countBits(int n);

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::cout << std::boolalpha << isKPartOfN(n, k);

	return 0;
}

bool isKPartOfN(int n, int k)
{
	int bitCount = countBits(k);

	int mask = (1 << bitCount) - 1;

	while (n >= k)
	{
		if ((n & mask) == k)
		{
			return true;
		}

		n >>= 1;
	}

	return false;
}

int countBits(int n)
{
	int count = 0;

	if (n == 0)
	{
		return 1;
	}
	else
	{
		while (n > 0)
		{
			n >>= 1;
			count++;
		}
	}

	return count;
}
