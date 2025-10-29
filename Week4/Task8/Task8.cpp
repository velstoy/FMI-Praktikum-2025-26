#include<iostream>
using std::cout;
using std::endl;

bool isPrime(unsigned int);

int main()
{
	cout << std::boolalpha << isPrime(21) << endl;
	cout << std::boolalpha << isPrime(7) << endl;
	return 0;
}

bool isPrime(unsigned int number)
{
	if (number % 2 == 0)
	{
		return false;
	}
	for (int i = 3; i < number; i += 2)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}