#include<iostream>

int main()
{
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;

	if ((c < a || c > b) && (d < a || d > b))
		std::cout << 0;
	else if ((c < a || c > b) || (d < a || d > b))
		std::cout << 1;
	else
		std::cout << 2;

	return 0;
}