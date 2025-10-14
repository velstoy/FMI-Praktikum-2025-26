#include<iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	/*double sum_of_roots = (-b) / (double)a;
	double product_of_roots = c / (double)a;*/
	// x1 + x2 = sum_of_roots;
	// x1*x2 = product_of_roots;
	// x1 = sum_of_roots - x2
	// sum_of_roots*x2 - x2^2 = product_of_roots
	// x2 = sqrt(sum_of_roots*x2 - product_of_roots);
	// x1 = sum_of_roots - sqrt(sum_of_roots*x2 - product_of_roots);

	double D = b * b - 4 * a * c;

	double x1 = (-b + sqrt(D)) / (2 * a);
	double x2 = (-b - sqrt(D)) / (2 * a);

	std::cout << "x1: " << x1 << std::endl << "x2: " << x2;
}