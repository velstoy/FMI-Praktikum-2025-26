#include<iostream>

int main()
{
	int n, k;
	std::cin >> n >> k;

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int num = 0;
		for (int j = 0; j < i; j++)
		{
			num *= 10;
			num += k;
		}
		sum += num;
	}

	std::cout << sum;

	return 0;
}