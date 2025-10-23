#include<iostream>

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			std::cout << j + 1 << " ";
		}
		if (i != n - 1)
		{
			for (int j = 0; j < (n + 1) * n - n * i - (n - 1); j++)
			{
				std::cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << "-";
			}
			std::cout << " ";
		}
		for (int j = i; j >= 0; j--)
		{
			std::cout << j + 1 << " ";
		}
		std::cout << std::endl;
	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j < i + 1; j++)
		{
			std::cout << j + 1 << " ";
		}
		for (int j = 0; j < (n + 1) * n - n * i - (n - 1); j++)
		{
			std::cout << " ";
		}
		for (int j = i; j >= 0; j--)
		{
			std::cout << j + 1 << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}