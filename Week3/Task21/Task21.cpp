#include<iostream>

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j % 2 == 0)
			{
				std::cout << (i + 1) + j * n << " ";
			}
			else 
			{
				std::cout << n * (j + 1) - i << " ";
			}
		}
		std::cout << std::endl;
	}

	return 0;
}