#include<iostream>

void sort3(int& min, int& mid, int& max);
int myMin(int a, int b);
int myMax(int a, int b);

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	sort3(a, b, c);

	std::cout << a << " " << b << " " << c;

	return 0;
}

void sort3(int& min, int& mid, int& max)
{
	int tempMin = myMin(myMin(min, mid), max);
	int tempMax = myMax(myMax(min, mid), max);
	int tempMid = myMin(myMin(myMax(min, mid), myMax(mid, max)), myMax(min, max));

	min = tempMin;
	max = tempMax;
	mid = tempMid;
}

int myMin(int a, int b)
{
	return a < b ? a : b;
}

int myMax(int a, int b)
{
	return a > b ? a : b;
}
