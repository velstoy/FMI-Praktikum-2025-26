#include<iostream>

int twoToPowN(int n);

int main()
{
	int n;
	std::cin >> n;

	std::cout << twoToPowN(n);

	return 0;
}

int twoToPowN(int n)
{
	return (1 << n);
}
