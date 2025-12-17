#include<iostream>

int countPatternInclusions(char* text, char* pattern);

constexpr int MAX_SIZE = 1024;

int main()
{
	char str[MAX_SIZE];
	std::cin.getline(str, MAX_SIZE);

	char pattern[MAX_SIZE];
	std::cin.getline(pattern, MAX_SIZE);

	int patterns = countPatternInclusions(str, pattern);

	if (patterns == -1)
	{
		return -1;
	}

	std::cout << "Patterns: " << patterns << std::endl;

	return 0;
}

int countPatternInclusions(char* text, char* pattern)
{
	if (text == nullptr || pattern == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return -1;
	}

	int count = 0;

	while (*text)
	{
		char* tempPat = pattern;
		char* tempText = text;

		bool found = true;

		while (*tempPat && *tempText)
		{
			if (*tempPat != *tempText)
			{
				found = false;
				break;
			}

			tempPat++;
			tempText++;
		}

		if (found)
		{
			count++;
		}

		text++;
	}

	return count;
}
