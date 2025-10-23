#include<iostream>

int main()
{
	int fib0 = 0;
	int fib1 = 1;

	int n;
	std::cin >> n;
	
	int last_num = 0;

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			last_num = fib0;
		} 
		else if (i == 1)
		{
			last_num = fib1;
		}
		else {
			int fib_num = fib0 + fib1;
			last_num = fib_num;
			fib0 = fib1;
			fib1 = fib_num;
		}
	}

	std::cout << last_num;

	return 0;
}