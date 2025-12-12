#include<iostream>

int mystrlen(const char* str);

int main()
{
	const char* str = "Hello World!";

	std::cout << mystrlen(str);

	return 0;
}

int mystrlen(const char* str)
{
	int count = 0;

	while (*str)
	{
		count++;
		str++;
	}

	return count;
}
