#include<iostream>

int findWordCount(char* text);
bool isSpecialChar(char c);

constexpr int MAX_SIZE = 1024;

int main()
{
	char str[MAX_SIZE];
	std::cin.getline(str, MAX_SIZE);

	int count = findWordCount(str);

	if (count == -1)
	{
		return -1;
	}

	std::cout << count << std::endl;

	return 0;
}

int findWordCount(char* text)
{
	if (text == nullptr)
	{
		std::cout << "Null pointer exception! Exiting with code -1." << std::endl;
		return -1;
	}

	int count = 0;

	char* currentWordStart = 0;

	while(*text)
	{
		if (!isSpecialChar(*text) && currentWordStart == 0)
		{
			currentWordStart = text;
		}
		else if (isSpecialChar(*text) && currentWordStart != 0)
		{
			currentWordStart = 0;
			count++;
		}
		text++;
	}

	if (currentWordStart != 0)
	{
		count++;
	}

	return count;
}

bool isSpecialChar(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '.' || c == '?' || c == '!';
}
