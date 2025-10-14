#include<iostream>

int main()
{
	int num;
	std::cin >> num;

	int dig1 = num % 10, dig2 = num / 10 % 10, dig3 = num / 100 % 10, dig4 = num / 1000;

	int sum = dig1 + dig2 + dig3 + dig4;
	int product = dig1 * dig2 * dig3 * dig4;
	double average = sum / 4.0;

	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Product: " << product << std::endl;
	std::cout << "Average: " << average;

	return 0;
}