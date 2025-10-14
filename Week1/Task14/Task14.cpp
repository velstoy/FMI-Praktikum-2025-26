#include<iostream>

const double EPSILON = 0.00000001;

int main()
{
	int a1, a2, a3, a4;
	std::cin >> a1 >> a2 >> a3 >> a4;

	double d1 = a2 / (double)a1;
	double d2 = a3 / (double)a2;
	double d3 = a4 / (double)a3;

	std::cout << (((d1 >= d2 && d1 - d2 < EPSILON) || (d2 > d1 && d2 - d1 < EPSILON))
		&& ((d1 >= d3 && d1 - d3 < EPSILON) || (d3 > d1 && d3 - d1 < EPSILON)));

	return 0;
}