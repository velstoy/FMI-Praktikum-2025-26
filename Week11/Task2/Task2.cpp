#include<iostream>

bool checkStr(const char*);
bool isPalindrome(const char*);
void removeCharsFromString(const char*, char*, int, int);
int mystrlen(const char*);

constexpr int N = 1024;

int main()
{
	char str[N];
	std::cin.getline(str, N);

	std::cout << checkStr(str) << std::endl;

	return 0;
}

bool checkStr(const char* str)
{
	if (str == nullptr)
	{
		std::cout << "Invalid string!" << std::endl;
		return false;
	}

	int strLen = mystrlen(str);

	for (int i = 0; i < strLen; i++)
	{
		for (int j = i + 1; j < strLen; j++)
		{
			char current[N];

			removeCharsFromString(str, current, i, j);

			if (isPalindrome(current))
			{
				return true;
			}
		}
	}

	return false;
}

bool isPalindrome(const char* str)
{
	if (str == nullptr)
	{
		std::cout << "Invalid string!" << std::endl;
		return false;
	}

	int strLen = mystrlen(str);

	for (int i = 0; i < strLen / 2; i++)
	{
		if (str[i] != str[strLen - i - 1])
		{
			return false;
		}
	}

	return true;
}

void removeCharsFromString(const char* str, char* res, int firstIndex, int secondIndex)
{
	if (str == nullptr || res == nullptr)
	{
		std::cout << "Invalid string!" << std::endl;
		return;
	}

	int strLen = mystrlen(str);

	if (strLen == -1)
	{
		return;
	}

	for (int i = 0; i < strLen; i++)
	{
		if (i == firstIndex || i == secondIndex)
		{
			continue;
		}

		*res = str[i];
		res++;
	}

	*res = '\0';
}

int mystrlen(const char* str)
{
	if (str == nullptr)
	{
		std::cout << "Null string error!" << std::endl;
		return -1;
	}

	int len = 0;

	while (*str)
	{
		len++;
		str++;
	}

	return len;
}
