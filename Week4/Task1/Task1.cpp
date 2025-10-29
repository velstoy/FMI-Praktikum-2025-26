#include<iostream>
using std::cout;
using std::endl;

int absoluteValue(int);

int main()
{
	cout << absoluteValue(-7) << endl;
	cout << absoluteValue(12) << endl;
}

int absoluteValue(int number)
{
	if (number > 0)
	{
		return number;
	}
	else
	{
		return -number;
	}
}