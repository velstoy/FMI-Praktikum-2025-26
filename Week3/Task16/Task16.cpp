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
		std::cout << std::endl;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << j + 1 << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}