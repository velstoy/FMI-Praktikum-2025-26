#include<iostream>

bool isNToPow2(int n);

int main()
{
	int n;
	std::cin >> n;

	std::cout << std::boolalpha << isNToPow2(n);

	return 0;
}

bool isNToPow2(int n)
{
	return (n > 0) && (n & (n - 1)) == 0;
}
