#include<iostream>

void swapPointers(int*& pointerToA, int*& pointerToB);

int main()
{
	int a, b;
	std::cin >> a >> b;

	int* pointerToA = &a;
	int* pointerToB = &b;

	std::cout << "Dereference before: " << std::endl << *pointerToA << " " << *pointerToB << std::endl;

	swapPointers(pointerToA, pointerToB);

	std::cout << "Dereference after: " << std::endl << *pointerToA << " " << *pointerToB;

	return 0;
}

void swapPointers(int*& pointerToA, int*& pointerToB)
{
	int* temp = pointerToA;
	pointerToA = pointerToB;
	pointerToB = temp;
}
