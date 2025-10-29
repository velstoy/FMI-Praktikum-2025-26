#include<iostream>

int log(int, int);

int main()
{
	std::cout << log(90, 3) << std::endl;
	return 0;
}

int log(int k, int n)
{
	int res = 0;
	int powered = n;
	while (powered < k)
	{
		powered *= n;
		res++;
	}

	return res;
}