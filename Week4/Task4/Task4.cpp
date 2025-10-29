#include<iostream>
using std::cout;
using std::endl;

int toNumber(char);
char toCharacter(int);

int main()
{
	cout << toNumber('1') << endl;
	cout << toCharacter(3) << endl;
	return 0;
}

int toNumber(char symbol)
{
	return symbol - '0';
}

char toCharacter(int number)
{
	return number + '0';
}