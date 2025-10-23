#include<iostream>
#include<cmath>

int main()
{
	int n;
	std::cin >> n;

	int div_count = 0;

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0) {
			div_count++;
		}
	}	

	std::cout << div_count;

	return 0;
}