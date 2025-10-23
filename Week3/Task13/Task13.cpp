#include<iostream>

int main()
{
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		int sum_digits = 0;
		while (temp != 0)
		{
			sum_digits += temp % 10;
			temp /= 10;
		}

		if (sum_digits % 2 == 0)
		{
			std::cout << i << " ";
		}
	}
	return 0;
}