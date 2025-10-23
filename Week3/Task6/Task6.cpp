#include<iostream>

int main()
{
	int positive_count = 0;
	int sum = 0;

	while (positive_count != 5) {
		int num;
		std::cin >> num;
		if (num > 0)
		{
			positive_count++;
			sum += num;
		}
	}

	std::cout << sum;

	return 0;
}