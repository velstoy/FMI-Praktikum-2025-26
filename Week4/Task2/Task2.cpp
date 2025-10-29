#include<iostream>
using std::cout;
using std::endl;

bool isDigit(char);
bool isLower(char);
bool isUpper(char);

int main()
{
	cout << std::boolalpha << isDigit('à') << endl;
	cout << std::boolalpha << isDigit('0') << endl;
	cout << std::boolalpha << isLower('-') << endl;
	cout << std::boolalpha << isUpper('Z') << endl;
	return 0;
}

bool isDigit(char symbol)
{
	int charValue = symbol - '0';
	if (charValue >= 0 && charValue <= 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isLower(char symbol)
{
	int charVal = symbol - 'a';
	if (charVal >= 0 && charVal <= 'z' - 'a')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isUpper(char symbol)
{
	int charVal = symbol - 'A';
	if (charVal >= 0 && charVal >= 'Z' - 'A')
	{
		return true;
	}
	else
	{
		return false;
	}
}