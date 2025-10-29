#include<iostream>
using std::cout;
using std::endl;

int lcm(int first, int second);

int main()
{
	cout << lcm(15, 25) << endl;
	return 0;
}

int lcm(int first, int second)
{
	int larger = first > second ? first : second;
	int smaller = first < second ? first : second;

	return (larger % smaller) * smaller;
}