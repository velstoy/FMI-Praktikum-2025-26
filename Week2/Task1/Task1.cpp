#include<iostream>

int main()
{
	char c1, c2, c3;
	std::cin >> c1 >> c2 >> c3;


	std::cout << ((c1 + c2 + c3) % 2 == 0);

	return 0;
}