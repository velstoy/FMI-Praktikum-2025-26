#include<iostream>

int excludeSymbolFromText(char* text, char symbol);

constexpr int MAX_SIZE = 1024;

int main()
{
	char str[MAX_SIZE];
	std::cin.getline(str, MAX_SIZE);

	char symbol;
	std::cin >> symbol;

	if (excludeSymbolFromText(str, symbol) == -1)
	{
		return -1;
	}

	std::cout << str;

	return 0;
}

int excludeSymbolFromText(char* text, char symbol)
{
	if (text == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return -1;
	}

	char* edit = text;

	while (*text && *edit)
	{
		if (*text == symbol) {
			edit++;
			*text = *edit;
			continue;
		}

		*text = *edit;
		text++;
		edit++;
	}

	*text = '\0';

	return 0;
}
