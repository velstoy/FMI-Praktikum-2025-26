#include<iostream>
using std::cout;
using std::endl;

int getDivision(int first, int second);

int main()
{
	cout << getDivision(30, 7) << endl;
	return 0;
}

int getDivision(int first, int second)
{
	int result = 0;
	for (int i = second; i <= first; i += second)
	{
		result++;
	}
	return result;
}
