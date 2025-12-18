#include<iostream>

unsigned convert(const char*, int);
unsigned convertCharToUnsigned(const char, int);
unsigned pow(unsigned, unsigned);
unsigned mystrlen(const char*);

constexpr int K_MAX = 36;
constexpr int K_MIN = 2;

constexpr unsigned MAX_SIZE = 1024;

int main()
{
	char str[MAX_SIZE];
	std::cin.get(str, MAX_SIZE, ' ');


	int base;
	std::cin >> base;

	unsigned res = convert(str, base);

	std::cout << res << std::endl;

	return 0;
}

unsigned convert(const char* str, int k)
{
	if (k < K_MIN || k > K_MAX)
	{
		std::cout << "Invalid number base!" << std::endl;
		return 0;
	}

	if (str == nullptr)
	{
		std::cout << "Invalid string!" << std::endl;
		return 0;
	}

	unsigned res = 0;

	unsigned strLen = mystrlen(str);

	for (unsigned i = 0; i < strLen; i++)
	{
		res += (convertCharToUnsigned(str[strLen - i - 1], k) * pow(k, i));
	}

	return res;
}

unsigned convertCharToUnsigned(const char c, int k)
{
	unsigned converted = 0;

	if (c >= '0' && c <= '9')
	{
		converted = c - '0';
	}
	else if (c >= 'A' && c <= 'Z')
	{
		converted = c - 'A' + 10;
	}

	if (converted < k)
	{
		return converted;
	}

	return 0;
}

unsigned pow(unsigned base, unsigned pow)
{
	unsigned res = 1;

	for (int i = 0; i < pow; i++)
	{
		res *= base;
	}

	return res;
}

unsigned mystrlen(const char* str)
{
	if (str == nullptr)
	{
		std::cout << "Invalid string!" << std::endl;
		return 0;
	}

	unsigned res = 0;

	while (*str)
	{
		res++;
		str++;
	}

	return res;
}