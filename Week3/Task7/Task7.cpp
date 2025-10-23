#include<iostream>

int main()
{
	int negative_csq_count = 0;
	int min = INT16_MAX;

	while (negative_csq_count != 3)
	{
		int num;
		std::cin >> num;

		if (num < 0) {
			negative_csq_count++;
			if (num < min) {
				min = num;
			}
		}
		else {
			negative_csq_count = 0;
			min = INT16_MAX;
		}
	}

	std::cout << min;

	return 0;
}