#include<iostream>

void swap(int& a, int& b);

int main()
{
	int a;
	std::cout << "Enter a:";
	std::cin >> a;

	int b;
	std::cout << "Enter b:";
	std::cin >> b;

	swap(a, b);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
