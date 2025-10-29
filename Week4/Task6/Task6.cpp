#include<iostream>

int gcd(int, int);

int main()
{
	std::cout << gcd(15, 25) << std::endl;
	return 0;
}

int gcd(int first, int second)
{
	int larger = first > second ? first : second;
	int smaller = first < second ? first : second;

	while (smaller != 0)
	{
		int temp = larger % smaller;
		larger = smaller;
		smaller = temp;
	}

	return larger;
}