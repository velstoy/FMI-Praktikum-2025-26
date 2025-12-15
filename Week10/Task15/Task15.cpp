#include<iostream>

int toLower(char* str);
int toUpper(char* str);

constexpr size_t MAX_SIZE = 1024;

int main()
{
	char str[MAX_SIZE];

	std::cin.getline(str, MAX_SIZE);

	if (toLower(str) == -1)
	{
		return -1;
	}

	std::cout << str << std::endl;

	if (toUpper(str) == -1)
	{
		return -1;
	}

	std::cout << str << std::endl;

	return 0;
}

int toLower(char* str)
{
	if (str == nullptr)
	{
		std::cout << "Null string exception! Exiting with code -1." << std::endl;
		return -1;
	}

	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str = *str + ('a' - 'A');
		}
		str++;
	}

	return 0;
}

int toUpper(char* str)
{
	if (str == nullptr)
	{
		std::cout << "Null string exception! Exiting with code -1." << std::endl;
		return -1;
	}

	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str = *str - ('a' - 'A');
		}
		str++;
	}

	return 0;
}
