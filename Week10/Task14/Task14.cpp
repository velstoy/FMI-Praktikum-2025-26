#include<iostream>

constexpr int N = 1024;

int mystrlen(char* str);
void mystrcopy(char* from, char* to);
void mystrcat(char* src, char* dest);
bool mystrcmp(char* first, char* second);
int myatoi(char* str);
bool isNumber(char c);

int main()
{
	char str[N];

	std::cin.getline(str, N);

	std::cout << mystrlen(str) << std::endl;

	char another[N];

	mystrcopy(str, another);

	std::cout << another << std::endl;

	mystrcat(str, another);

	std::cout << another << std::endl;

	std::cout << std::boolalpha << mystrcmp(str, another) << std::endl;

	std::cout << "Enter a number: ";

	char n[N];
	
	std::cin.getline(n, N);

	std::cout << "atoi res = " << myatoi(n) << std::endl;


	return 0;
}

int mystrlen(char* str)
{
	if (str == nullptr)
	{
		std::cout << "Null pointer exception!" << std::endl;
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

void mystrcopy(char* from, char* to)
{
	if (from == nullptr)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return;
	}

	while (*from)
	{
		*to = *from;
		from++;
		to++;
	}

	*to = '\0';
}

void mystrcat(char* src, char* dest)
{
	if (src == nullptr || dest == nullptr)
	{
		std::cout << "Null pointer exception!";
		return;
	}

	int srcSize = mystrlen(src);
	int destSize = mystrlen(dest);

	for (int i = 0; i <= srcSize; i++)
	{
		dest[destSize + i] = src[i];
	}
}

bool mystrcmp(char* first, char* second)
{
	if (first == nullptr || second == nullptr)
	{
		std::cout << "Null pointer exception!";
		return 0;
	}

	while (*first && *second)
	{
		if (*first != *second)
		{
			return false;
		}
		first++;
		second++;
	}

	return (*first == '\0' && *second == '\0');
}

int myatoi(char* str)
{
	if (str == nullptr)
	{
		std::cout << "Null pointer exception!" << std::endl;
		return -1;
	}

	int res = 0;

	while (*str)
	{
		if (isNumber(*str))
		{
			res *= 10;
			res += (*str - '0');
		}
		str++;
	}

	return res;
}

bool isNumber(char c)
{
	if (c < '0' || c > '9')
	{
		return false;
	}
	return true;
}
