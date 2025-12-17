#include<iostream>

int makeCapitalizeAllWords(char* text);
char capitalize(char c);

constexpr int MAX_SIZE = 1024;

int main()
{
	char str[MAX_SIZE];
	std::cin.getline(str, MAX_SIZE);

	if (makeCapitalizeAllWords(str) == -1)
	{
		return -1;
	}

	std::cout << str << std::endl;

	return 0;
}

int makeCapitalizeAllWords(char* text)
{
	if (text == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return -1;
	}

	for (int i = 0; text[i]; i++)
	{
		if (i == 0 || text[i - 1] == ' ')
		{
			text[i] = capitalize(text[i]);
		}
	}

	return 0;
}

char capitalize(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return c - ('a' - 'A');
	}

	return c;
}
