#include<iostream>

int main()
{
	int n;
	std::cin >> n;

	int binary_length = 0;
	int temp = n;
	while (temp != 0)
	{
		temp /= 2;
		binary_length++;
	}

	while (n != 0)
	{
		if (n % 2 == 1)
		{
			std::cout << "2^" << (binary_length - 1);
		}
		binary_length--;
		n /= 2;
		if (n != 0 && n % 2 != 0)
		{
			std::cout << " + ";
		}
	}


	return 0;
}