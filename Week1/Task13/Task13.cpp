#include<iostream>

const double EPSILON = 0.000000001;

int main()
{
	int num1, num2, num3, num4;
	std::cin >> num1 >> num2 >> num3 >> num4;

	std::cout << ((num2 - (num1 + num3) / 2.0) < EPSILON && (num3 - (num2 + num4) / 2.0 < EPSILON));

	return 0;
}