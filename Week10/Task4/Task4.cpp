#include<iostream>

void mySwap(int& a, int& b);

int main()
{
	int a, b;
	std::cin >> a >> b;

	mySwap(a, b);

	std::cout << a << " " << b;

	return 0;
}

void mySwap(int& a, int& b)
{
	a = a | b;
	b = b ^ a;
	a = a ^ b;
}
