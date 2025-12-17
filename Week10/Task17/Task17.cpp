#include<iostream>

int normalizeStringPerCharIndex(char* original, char* result);
int charToInt(char c);

constexpr size_t MAX_SIZE = 1024;

int main()
{
	char original[MAX_SIZE];

	std::cin.getline(original, MAX_SIZE);

	char result[MAX_SIZE];

	if (normalizeStringPerCharIndex(original, result) == -1)
	{
		return -1;
	}

	std::cout << result << std::endl;

	return 0;
}

int normalizeStringPerCharIndex(char* original, char* result)
{
	if (original == nullptr || result == nullptr)
	{
		std::cout << "Null string exception! Exiting with code -1." << std::endl;
		return -1;
	}

	int histogram = 0;

	while (*original != '\0')
	{
		char currentSymbol = *original;

		original++;
		
		int converted = charToInt(*original);

		if (converted != -1)
		{
			result[converted] = currentSymbol;

			histogram |= (1 << converted);
		}

		original++;
	}

	int i = 0;

	while (histogram & (1 << i))
	{
		i++;
	}

	result[i] = '\0';

	return 0;
}

int charToInt(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}

	return -1;
}
