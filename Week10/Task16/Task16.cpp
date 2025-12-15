#include<iostream>

int insertSymbolAtPositionI(char* text, char* result, char symbol, int i);

constexpr size_t MAX_SIZE = 1024;

int main()
{
	char original[MAX_SIZE];

	std::cin.getline(original, MAX_SIZE);

	char symbol;
	std::cin >> symbol;

	int i;
	std::cin >> i;

	if (i < 0 || i >= MAX_SIZE)
	{
		std::cout << "Index out of bounds exception! Exiting with code -2." << std::endl;
		return -2;
	}

	char inserted[MAX_SIZE];

	if (insertSymbolAtPositionI(original, inserted, symbol, i) == -1)
	{
		return -1;
	}

	std::cout << inserted << std::endl;

	return 0;
}

int insertSymbolAtPositionI(char* text, char* result, char symbol, int i)
{
	if (text == nullptr || result == nullptr)
	{
		std::cout << "Null string exception! Exiting with code -1." << std::endl;
		return -1;
	}

	int pos = 0;

	while (*text != '\0')
	{
		if (pos == i)
		{
			*result = symbol;
		}
		else
		{
			*result = *text;
		}

		result++;
		text++;
		pos++;
	}

	*result = '\0';

	return 0;
}
