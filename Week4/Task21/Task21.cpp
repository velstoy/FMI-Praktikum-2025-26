#include<iostream>
using std::cout;
using std::endl;

int squareRootToLower(int number);

int main()
{
	cout << squareRootToLower(24) << endl;
	return 0;
}

int squareRootToLower(int number)
{
	int result = 1;
	while (result * result <= number)
	{
		result++;
	}

	return (result - 1);
}
