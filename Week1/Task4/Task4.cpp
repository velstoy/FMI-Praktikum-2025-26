#include<iostream>

int main()
{
	int num1, num2;
	std::cin >> num1 >> num2;

	std::cout << "Sum: " << num1 + num2;
	std::cout << "Difference: " << num1 - num2;
	std::cout << "Product: " << num1 * num2;
	std::cout << "Quotient: " << num1 / num2;
	return 0;
}