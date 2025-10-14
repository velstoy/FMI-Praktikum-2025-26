#include<iostream>

int main()
{
	double a;
	std::cout << "A: ";
	std::cin >> a;

	double b;
	std::cout << "B: ";
	std::cin >> b;

	double swap = a;
	a = b;
	b = swap;

	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	return 0;
}