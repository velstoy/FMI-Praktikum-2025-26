#include<iostream>

char toUpper(char);
char toLower(char);

int main()
{
	std::cout << toUpper('b');
	return 0;
}

char toUpper(char letter)
{
	letter -= ('a' - 'A');
	return letter;
}

char toLower(char letter)
{
	letter += ('a' - 'A');
	return letter;
}