#include<iostream>

int findSmallestWord(char* text, char* res);
bool isWordDivider(char c);
int extractPattern(char* start, char* end, char* res);
int lexCompare(char* str1, char* str2, char*& res);
void strcpy(char* from, char* to);

constexpr size_t MAX_SIZE = 1024;

int main()
{
	char text[MAX_SIZE];
	std::cin.getline(text, MAX_SIZE);

	char result[MAX_SIZE];
	
	if (findSmallestWord(text, result) == -1)
	{
		return -1;
	}

	std::cout << result << std::endl;

	return 0;
}

int findSmallestWord(char* text, char* res)
{
	if (text == nullptr || res == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return -1;
	}

	char* smallestStart = 0;
	char* smallestEnd = 0;

	char* currentWordStart = 0;

	while (*text)
	{
		if (!isWordDivider(*text) && currentWordStart == 0)
		{
			currentWordStart = text;
		}
		else if (isWordDivider(*text) && currentWordStart != 0)
		{
			char smallest[MAX_SIZE];

			int errorCode = extractPattern(smallestStart, smallestEnd, smallest);

			if (errorCode == -2)
			{
				smallestStart = currentWordStart;
				smallestEnd = text;
			}
			else if (errorCode == -1)
			{
				return -1;
			}
			else
			{
				char current[MAX_SIZE];

				if (extractPattern(currentWordStart, text, current) != 0)
				{
					return -1;
				}

				char* temp = 0;

				lexCompare(smallest, current, temp);

				if (temp == current)
				{
					smallestStart = currentWordStart;
					smallestEnd = text;
				}
			}

			currentWordStart = 0;
		}

		text++;
	}

	if (currentWordStart != 0)
	{
		char smallest[MAX_SIZE];

		int errorCode = extractPattern(smallestStart, smallestEnd, smallest);

		if (errorCode == -2)
		{
			smallestStart = currentWordStart;
			smallestEnd = text;
		}
		else if (errorCode == -1)
		{
			return -1;
		}
		else
		{
			char current[MAX_SIZE];

			if (extractPattern(currentWordStart, text, current) != 0)
			{
				return -1;
			}

			char* temp = 0;

			lexCompare(smallest, current, temp);

			if (temp == current)
			{
				smallestStart = currentWordStart;
				smallestEnd = text;
			}
		}

		currentWordStart = 0;
	}

	char smallest[MAX_SIZE];

	extractPattern(smallestStart, smallestEnd, smallest);

	strcpy(smallest, res);

	return 0;
}

bool isWordDivider(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '.' || c == '?' || 
			c == '!' || c == '\"' || c == ';' || c == '\'' || c == ',';
}

int extractPattern(char* start, char* end, char* res)
{
	if (start == nullptr || end == nullptr)
	{
		return -2;
	}

	if (res == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return -1;
	}

	for (int i = 0; i < end - start; i++)
	{
		*res = start[i];
		res++;
	}

	*res = '\0';
	return 0;
}

int lexCompare(char* str1, char* str2, char*& res)
{
	if (str1 == nullptr || str2 == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return -1;
	}

	char* str1Start = str1;
	char* str2Start = str2;

	bool changed = false;

	while (*str1 && *str2)
	{
		if (*str1 < *str2)
		{
			res = str1Start;
			return 0;
		}
		else if (*str1 > *str2)
		{
			res = str2Start;
			return 0;
		}
		
		str1++;
		str2++;
	}

	if (*str1 != '\0' || (*str1 == '\0' && *str2 == '\0'))
	{
		res = str1Start;
	}
	else
	{
		res = str2Start;
	}

	return 0;
}

void strcpy(char* from, char* to)
{
	if (from == nullptr || to == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return;
	}

	while (*from)
	{
		*to = *from;
		to++;
		from++;
	}

	*to = '\0';
}
