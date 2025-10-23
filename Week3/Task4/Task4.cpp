#include<iostream>

int main()
{
	int n;
	std::cin >> n;
	int max = INT16_MIN;

	for (int i = 0; i < n; i++)
	{
		int num;
		std::cin >> num;

		if (num > max) {
			max = num;
		}
	}

	std::cout << max;
	
	return 0;
}