#include<iostream>

void grabSubstring(char* str, int beg, int end, char* res);
int strlen(char* str);

const int MAX = 1024;

int main()
{
	char str[MAX];
	std::cin >> str;

	int beg, end;
	std::cin >> beg >> end;

	char res[MAX];

	grabSubstring(str, beg, end, res);

	std::cout << res << std::endl;

	return 0;
}

void grabSubstring(char* str, int beg, int end, char* res)
{
	if (str == nullptr)
	{
		std::cout << "Null string error!" << std::endl;
		return;
	}

	int strLen = strlen(str);

	if (end >= strLen)
	{
		end = strLen - 1;
	}

	for (int i = beg; i <= end; i++)
	{
		*res = str[i];
		res++;
	}

	*res = '\0';
}

int strlen(char* str)
{
	if (str == nullptr)
	{
		std::cout << "Null pointer error!" << std::endl;
		return -1;
	}

	int count = 0;

	while (*str)
	{
		count++;
		str++;
	}

	return count;
}