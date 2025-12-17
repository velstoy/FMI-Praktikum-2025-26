#include<iostream>
#include<climits>

int findMostRecurringWord(char* text, char* res);
bool isSpecialChar(char c);
bool strcmp(char* str1, char* str2);
void extractPattern(char* start, char* end, char* res);
int countPatternInclusions(char* text, char* pattern);
void strcpy(char* from, char* to);

constexpr int MAX_SIZE = 1024;

int main()
{
	char str[MAX_SIZE];
	std::cin.getline(str, MAX_SIZE);

	char res[MAX_SIZE];

	if (findMostRecurringWord(str, res) == -1)
	{
		return -1;
	}

	std::cout << res << std::endl;

	return 0;
}

int findMostRecurringWord(char* text, char* res)
{
	if (text == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return -1;
	}

	char* currentWordStart = 0;

	int maxCount = INT_MIN;
	char maxWord[MAX_SIZE] = {};

	while (*text)
	{
		if (!isSpecialChar(*text) && currentWordStart == 0)
		{
			currentWordStart = text;
		}
		else if (isSpecialChar(*text) && currentWordStart != 0)
		{
			char pattern[MAX_SIZE];
			extractPattern(currentWordStart, text, pattern);

			int count = countPatternInclusions(text, pattern);

			if (count > maxCount && strcmp(pattern, maxWord))
			{
				maxCount = count;
				strcpy(pattern, maxWord);
			}

			currentWordStart = 0;
		}
		text++;
	}

	if (currentWordStart != 0)
	{
		char pattern[MAX_SIZE];
		extractPattern(currentWordStart, text - 1, pattern);

		int count = countPatternInclusions(text, pattern);

		if (count > maxCount && strcmp(pattern, maxWord))
		{
			maxCount = count;
			strcpy(pattern, maxWord);
		}
	}

	strcpy(maxWord, res);

	return 0;
}

bool isSpecialChar(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '.' || c == '?' || c == '!';
}

bool strcmp(char* str1, char* str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2) {
			return false;
		}

		str1++;
		str2++;
	}

	return true;
}

void extractPattern(char* start, char* end, char* res)
{
	for (int i = 0; i < (end - start); i++)
	{
		*res = *(start + i);
		res++;
	}

	*res = '\0';
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

void strcpy(char* from, char* to)
{
	while (*from)
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

