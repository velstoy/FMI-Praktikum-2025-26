#include<iostream>

int replacePatternWithReplacement(char* text, char* pattern, char* replacement);

constexpr int MAX_SIZE = 1024;

int main()
{
	char str[MAX_SIZE];
	std::cin.getline(str, MAX_SIZE);

	char pattern[MAX_SIZE];
	std::cin.getline(pattern, MAX_SIZE);

	char replacement[MAX_SIZE];
	std::cin.getline(replacement, MAX_SIZE);

	int patterns = replacePatternWithReplacement(str, pattern, replacement);

	if (patterns == -1)
	{
		return -1;
	}

	std::cout << str << std::endl;

	return 0;
}

int replacePatternWithReplacement(char* text, char* pattern, char* replacement)
{
	if (text == nullptr || pattern == nullptr || replacement == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return -1;
	}

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
			tempText = text;
			tempPat = pattern;

			char* tempRep = replacement;

			while (*tempPat && *tempText)
			{
				*tempText = *tempRep;

				tempPat++;
				tempText++;
				tempRep++;
			}
		}

		text++;
	}

	return 0;
}
