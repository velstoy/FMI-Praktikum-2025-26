#include<iostream>

int main()
{
	int year;
	std::cin >> year;

	std::cout << ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

	return 0;
}