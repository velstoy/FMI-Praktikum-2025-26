#include<iostream>

bool returnBitOnPosM(int m, int n);

int main()
{
	int m, n;

	std::cin >> m >> n;

	std::cout << returnBitOnPosM(m, n);

	return 0;
}

bool returnBitOnPosM(int m, int n)
{
	return (n & (1 << m));
}
