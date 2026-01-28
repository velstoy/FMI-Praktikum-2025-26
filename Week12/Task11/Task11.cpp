#include<iostream>
#include<limits>

char* concatSmallInFirstAndBigInSecond(const char* str1, const char* str2);
size_t getNewStringSize(const char* str1, const char* str2);

int main()
{
	size_t size1;
	std::cin >> size1;

	char* str1 = new (std::nothrow) char[size1 + 1];

	if (!str1)
	{
		return -1;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cin.getline(str1, size1 + 1);

	size_t size2;
	std::cin >> size2;

	char* str2 = new (std::nothrow) char[size2 + 1];

	if (!str2)
	{
		return -1;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cin.getline(str2, size2 + 1);

	char* str3 = concatSmallInFirstAndBigInSecond(str1, str2);

	delete[] str1;
	delete[] str2;

	if (!str3)
	{
		return -1;
	}

	std::cout << str3 << std::endl;

	delete[] str3;

	return 0;
}

char* concatSmallInFirstAndBigInSecond(const char* str1, const char* str2)
{
	if (!str1 || !str2)
	{
		return nullptr;
	}

	size_t newStrSize = getNewStringSize(str1, str2);

	char* res = new (std::nothrow) char[newStrSize + 1];

	if (!res)
	{
		return nullptr;
	}

	char* iter = res;

	while (*str1)
	{
		if (*str1 >= 'a' && *str1 <= 'z')
		{
			*iter = *str1;
			iter++;
		}
		str1++;
	}

	while (*str2)
	{
		if (*str2 >= 'A' && *str2 <= 'Z')
		{
			*iter = *str2;
			iter++;
		}
		str2++;
	}

	*iter = '\0';

	return res;
}

size_t getNewStringSize(const char* str1, const char* str2)
{
	if (!str1 || !str2)
	{
		return 0;
	}

	size_t size = 0;

	while (*str1)
	{
		if (*str1 >= 'a' && *str1 <= 'z')
		{
			size++;
		}
		str1++;
	}

	while (*str2)
	{
		if (*str2 >= 'A' && *str2 <= 'Z')
		{
			size++;
		}
		str2++;
	}

	return size;
}
