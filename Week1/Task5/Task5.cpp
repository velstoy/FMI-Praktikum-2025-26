#include<iostream>

const double PI = 3.14;

int main()
{
	double diameter;
	std::cin >> diameter;

	double radius = diameter / 2;

	double area = PI * radius * radius;
	double circumference = 2 * PI * radius;

	std::cout << "Area: " << area << std::endl;
	std::cout << "Circumference: " << circumference;

	return 0;
}