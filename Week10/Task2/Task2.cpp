#include<iostream>

int grabNBitsFromMPosFromX(int x, int m, int n);

int main()
{
	int x, m, n;
	std::cin >> x >> m >> n;

	std::cout << grabNBitsFromMPosFromX(x, m, n);

	return 0;
}

int grabNBitsFromMPosFromX(int x, int m, int n)
{
	return ((x >> m) & ((1 << n) - 1));
}
