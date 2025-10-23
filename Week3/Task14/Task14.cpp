#include<iostream>

int main()
{
	int n;
	std::cin >> n;

	int current_num = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << current_num << " ";
			current_num++;
		}
		std::cout << std::endl;
	}

	return 0;
}