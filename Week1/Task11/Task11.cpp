#include<iostream>

int main()
{
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	
	// no if-statements used
	((c < a || c > b) && (d < a || d > b) && std::cout << 0) ||
	(((c < a || c > b) || (d < a || d > b)) && std::cout << 1) ||
	(c >= a && c <= b && d >= a && d <= b && std::cout << 2);

	return 0;
}