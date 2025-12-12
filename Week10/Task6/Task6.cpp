#include<iostream>

bool areBitsPermutation(int a, int b);
int countRaisedFlags(int n);

int main()
{
	int a, b;
	std::cin >> a >> b;

	std::cout << std::boolalpha << areBitsPermutation(a, b) << std::endl;

	return 0;
}

bool areBitsPermutation(int a, int b)
{
	if (countRaisedFlags(a) == countRaisedFlags(b))
	{
		return true;
	}
	
	return false;
}

int countRaisedFlags(int n)
{
	int count = 0;

	for (size_t i = 0; i < sizeof(n) * 8; i++)
	{
		if ((n & (1 << i)) == 1) {
			count++;
		}
	}

	return count;
}
