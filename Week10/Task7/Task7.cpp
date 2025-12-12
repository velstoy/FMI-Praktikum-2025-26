#include<iostream>

void turnRightmostOneToZero(int& n);

int main()
{
	int num;
	std::cin >> num;

	turnRightmostOneToZero(num);

	std::cout << num;

	return 0;
}

void turnRightmostOneToZero(int& n)
{
	for (size_t i = 0; i < sizeof(n) * 8; i++)
	{
		if ((n & (1 << i))) {
			n ^= (1 << i);
			break;
		}
	}
}