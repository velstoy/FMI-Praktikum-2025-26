#include<iostream>

constexpr int KEY = 51926;

int encode(int num);
int decode(int num, int key);

int main()
{
	int num;
	std::cin >> num;

	std::cout << encode(num) << std::endl;

	std::cout << decode(encode(num), KEY);

	return 0;
}

int encode(int num)
{
	return num ^ KEY;
}

int decode(int num, int key)
{
	return num ^ key;
}
