#include<iostream>

int numEncodedInLastKSymbols(int n, int k);

int main()
{
	int num, k;
	std::cin >> num >> k;

	std::cout << numEncodedInLastKSymbols(num, k);

	return 0;
}

int numEncodedInLastKSymbols(int n, int k)
{
	return (n & ((1 << k) - 1));
}
