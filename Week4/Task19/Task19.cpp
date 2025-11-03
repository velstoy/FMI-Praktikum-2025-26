#include<iostream>
using std::cout;
using std::endl;

bool isDivisableByValue(int number, int divisor);

int main()
{
	cout << std::boolalpha << isDivisableByValue(6, 3) << endl;
	cout << std::boolalpha << isDivisableByValue(14, 5) << endl;
	return 0;
}

bool isDivisableByValue(int number, int divisor)
{
	/*for (int i = divisor; i <= number; i += divisor)
	{
		if (number == i)
		{
			return true;
		}
	}*/
	return (number / divisor) * divisor == number;
}
