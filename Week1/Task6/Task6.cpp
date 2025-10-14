#include<iostream>

int main()
{
	int seconds;
	std::cin >> seconds;
	int minutes = seconds / 60;
	seconds -= minutes * 60;
	int hours = minutes / 60;
	minutes -= hours * 60;
	int days = hours / 24;
	hours -= days * 24;

	std::cout << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";

	return 0;
}