#include<iostream>

int getLength(int);

int main()
{
	std::cout << getLength(123) << std::endl;
	std::cout << getLength(0) << std::endl;
	return 0;
}

int getLength(int number)
{
	int length = 0;
	do 
	{
		length++;
		number /= 10;
	}
	while (number != 0);

	return length;
}