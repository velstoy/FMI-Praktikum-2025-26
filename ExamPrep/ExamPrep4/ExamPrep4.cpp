#include<iostream>

struct Point
{
	int x, y;
};

long processNum(long);
size_t getNumLength(long);
long pow10(long);
bool isSeqDecreasing(long);
int* mergeArrays(int[], int[], int m);
int CheckQ(Point);

int main()
{
	/*long num;
	std::cin >> num;

	long processed = processNum(num);

	if (processed == -1)
	{
		return -1;
	}

	std::cout << processed << std::endl;*/

	/*size_t m;
	std::cin >> m;

	int* first = new int[m];

	for (size_t i = 0; i < m; i++)
	{
		std::cin >> first[i];
	}

	int* second = new int[m];
	for (size_t i = 0; i < m; i++)
	{
		std::cin >> second[i];
	}

	int* merged = mergeArrays(first, second, m);

	if (!merged)
	{
		return -1;
	}

	for (size_t i = 0; i < m; i++)
	{
		std::cout << merged[i] << " ";
	}
	std::cout << std::endl;

	delete[] first;
	delete[] second;
	delete[] merged;*/



	return 0;
}

long processNum(long num)
{
	size_t numLen = getNumLength(num);

	if (numLen < 5)
	{
		std::cout << "Number length must be at least 5!" << std::endl;
		return -1;
	}

	for (int i = 0; i < numLen; i++)
	{
		long power = pow10(numLen - i);

		for (int j = i; j >= 0; j--)
		{
			long sequence = (num / pow10(j)) % power;

			if (isSeqDecreasing(sequence))
			{
				return sequence;
			}
		}
	}

	return 0;
}


size_t getNumLength(long num)
{
	size_t len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}

	return len;
}

long pow10(long pow)
{
	long res = 1;

	for (size_t i = 0; i < pow; i++)
	{
		res *= 10;
	}

	return res;
}

bool isSeqDecreasing(long seq)
{
	long numLen = getNumLength(seq);

	int firstDigit = -1;
	int secondDigit = -1;

	for (int i = 1; i <= numLen; i++)
	{
		long power = pow10(numLen - i);

		if (i == 1)
		{
			firstDigit = seq / power;
		}
		else if (i == 2)
		{
			secondDigit = seq / power;
		}
		else
		{
			if (firstDigit <= secondDigit)
			{
				return false;
			}

			int temp = firstDigit;
			firstDigit = secondDigit;
			secondDigit = seq / power;
		}
		
		seq %= power;
	}

	if (firstDigit <= secondDigit)
	{
		return false;
	}

	return true;
}

int* mergeArrays(int arr1[], int arr2[], int m)
{
	if (!arr1 || !arr2)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return nullptr;
	}

	int* merged = new (std::nothrow) int[m];

	if (!merged)
	{
		std::cout << "Couldn't allocate memory!" << std::endl;
		return nullptr;
	}

	for (size_t i = 0; i < m; i++)
	{
		merged[i] = arr1[i] + arr2[m - i - 1];
	}

	return merged;
}

int CheckQ(Point p)
{
	if (p.x > 0 && p.y > 0)
	{
		return 1;
	}
	else if (p.x < 0 && p.y > 0)
	{
		return 2;
	}
	else if (p.x < 0 && p.y < 0)
	{
		return 3;
	}
	else if (p.x > 0 && p.y < 0)
	{
		return 4;
	}
	else
	{
		return 0;
	}
}
