#include<iostream>
using std::cout;
using std::endl;

bool isSquareRoot(int);

int main()
{
	cout << std::boolalpha << isSquareRoot(24) << endl;
	cout << std::boolalpha << isSquareRoot(25) << endl;
	return 0;
}

bool isSquareRoot(int number)
{
	int i = 1;
	while (i * i <= number)
	{
		if (i * i == number)
		{
			return true;
		}
		i++;
	}

	return false;
}