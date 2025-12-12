#include<iostream>

void switchBitAtPPos(int& n, int p, bool b);

int main()
{
	int n;
	std::cin >> n;

	int p;
	std::cin >> p;

	bool b;
	std::cin >> b;

	switchBitAtPPos(n, p, b);

	std::cout << n << std::endl;

	return 0;
}

void switchBitAtPPos(int& n, int p, bool b)
{
	int mask = (b << p);

	if (b == 0)
	{
		n &= ~mask;
	}
	else
	{
		n ^= mask;
	}
}
