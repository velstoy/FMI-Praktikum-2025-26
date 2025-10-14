#include<iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;

	int new_num = (a % 100) * 100 + b % 100;

	std::cout << new_num;

	return 0;
}