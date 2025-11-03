#include<iostream>
using std::cout;
using std::endl;

int closestPowerOfTwo(int);
int pow(int, int);

int main()
{
	cout << closestPowerOfTwo(150) << endl;
	cout << closestPowerOfTwo(1024) << endl;
	return 0;
}

int closestPowerOfTwo(int number)
{
	int power = 0;
	for (int i = 1; i <= number; i *= 2)
	{
		power++;
	}

	int powered = pow(2, power);
	int poweredMinus = pow(2, power - 1);

	return powered < poweredMinus ? powered : poweredMinus;
}

int pow(int number, int power)
{
	int result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= number;
	}

	return result;
}