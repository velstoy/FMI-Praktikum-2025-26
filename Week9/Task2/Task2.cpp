#include<iostream>

void swap(int* pointerA, int* pointerB);

int main()
{
	int a, b;
	std::cin >> a >> b;

	int* pointerA = &a;
	int* pointerB = &b;

	std::cout << "Before swap: " << std::endl << a << " " << b << std::endl;

	swap(pointerA, pointerB);

	std::cout << "After swap: " << std::endl << a << " " << b << std::endl;

	return 0;
}

void swap(int* pointerA, int* pointerB)
{
	int temp = *pointerA;
	*pointerA = *pointerB;
	*pointerB = temp;
}
