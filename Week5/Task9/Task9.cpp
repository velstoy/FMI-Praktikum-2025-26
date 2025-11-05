#include<iostream>

void transferKFromAToFrontB(int& a, int& b, int k);
int pow10(int power);
int countDigits(int num);

int main()
{
	int a, b, k;
	std::cin >> a >> b >> k;

	transferKFromAToFrontB(a, b, k);

	std::cout << a << " " << b;

	return 0;
}

void transferKFromAToFrontB(int& a, int& b, int k)
{
	int toTransfer = a % pow10(k);
	a /= pow10(k);

	b = toTransfer * pow10(countDigits(b)) + b;
}

int pow10(int power)
{
	int res = 1;
	for (int i = 0; i < power; i++)
	{
		res *= 10;
	}

	return res;
}

int countDigits(int num)
{
	int count = 0;
	do
	{
		count++;
		num /= 10;
	} while (num != 0);

	return count;
}
