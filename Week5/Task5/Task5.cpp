#include<iostream>

void swapKThDigit(int& n, int& m, int k);
int pow10(int power);
int countDigits(int n);
int extractDigitOnPos(int n, int k);
void replaceDigitOnPosWith(int& n, int k, int m);

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;

	swapKThDigit(n, m, k);

	std::cout << n << " " << m;

	return 0;
}

void swapKThDigit(int& n, int& m, int k)
{
	int kThInN = extractDigitOnPos(n, k);
	int kThInM = extractDigitOnPos(m, k);

	replaceDigitOnPosWith(n, k, kThInM);
	replaceDigitOnPosWith(m, k, kThInN);
}

int pow10(int power)
{
	int powered = 1;

	for (int i = 0; i < power; i++)
	{
		powered *= 10;
	}

	return powered;
}

int countDigits(int n)
{
	int count = 0;
	do
	{
		n /= 10;
		count++;
	} while (n != 0);
	return count;
}

int extractDigitOnPos(int n, int k)
{
	int truePosN = countDigits(n);
	int trailPow = pow10(truePosN - k);
	int kThInN = n / trailPow % 10;

	return kThInN;
}

void replaceDigitOnPosWith(int& n, int k, int m)
{
	int truePos = countDigits(n) - k;

	int trailPow = pow10(truePos);

	int trailN = n % trailPow;

	n = ((n / (trailPow * 10)) * 10 + m) * trailPow + trailN;
}
