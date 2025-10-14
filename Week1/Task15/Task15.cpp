#include<iostream>

int main()
{
	int card_number;
	std::cin >> card_number;
	std::cout << "XXXXXXXXXXXX" << card_number % 10000;
	return 0;
}