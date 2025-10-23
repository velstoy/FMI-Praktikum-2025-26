#include<iostream>

int main()
{
	double num1, num2;
	char op;
	std::cin >> num1 >> op >> num2;

	switch (op)
	{
	case '+':
		std::cout << num1 + num2;
		break;
	case '-':
		std::cout << num1 - num2;
		break;
	case '*':
		std::cout << num1 * num2;
		break;
	case '/':
		if (num2 == 0)
		{
			std::cout << "Error! You can't divide by 0!";
			break;
		}
		std::cout << num1 / num2;
		break;
	}

	return 0;
}