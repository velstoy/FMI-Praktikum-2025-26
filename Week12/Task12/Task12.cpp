#include<iostream>
#include<limits>

char* replaceNumsWithStars(const char* str);
size_t myStrlen(const char* str);

int main()
{
	size_t size;
	std::cin >> size;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	char* str = new (std::nothrow) char[size + 1];

	if (!str)
	{
		return -1;
	}

	std::cin.getline(str, size + 1);

	char* newStr = replaceNumsWithStars(str);

	delete[] str;
	str = nullptr;

	std::cout << newStr;

	delete[] newStr;
	newStr = nullptr;

	return 0;
}

char* replaceNumsWithStars(const char* str)
{
	if (!str)
	{
		return nullptr;
	}

	size_t len = myStrlen(str);

	char* newStr = new (std::nothrow) char[len + 1];

	if (!newStr)
	{
		return nullptr;
	}

	for (size_t i = 0; i < len; i++)
	{
		if (str[i] >= '0' && str[i] <= '9') 
		{
			newStr[i] = '*';
		}
		else
		{
			newStr[i] = str[i];
		}
	}

	newStr[len] = '\0';

	return newStr;
}

size_t myStrlen(const char* str)
{
	size_t len = 0;

	while (*str)
	{
		len++;
		str++;
	}

	return len;
}
