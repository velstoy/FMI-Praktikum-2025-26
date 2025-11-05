#include<iostream>

void truncateSimpleFraction(int& p, int& q);
int NOK(int a, int b);

int main()
{
	int p, q;
	std::cin >> p >> q;

	truncateSimpleFraction(p, q);
	std::cout << p << " " << q;

	return 0;
}

void truncateSimpleFraction(int& p, int& q)
{
	int divisionFactor = NOK(p, q);

	p /= divisionFactor;
	q /= divisionFactor;
}

int NOK(int a, int b)
{
	int nok = 1;
	for (int i = 2; i <= (a > b ? a : b); i++)
	{
		if (a % i == 0 && b % i == 0) 
		{
			nok = i;
		}
	}
	return nok;
}
