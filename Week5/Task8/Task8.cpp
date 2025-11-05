#include<iostream>

void enterPerfAndPrintLastEnd(int n);

int main()
{
	int n;
	std::cin >> n;

	enterPerfAndPrintLastEnd(n);

	return 0;
}

void enterPerfAndPrintLastEnd(int n)
{
	int max = INT16_MIN;

	for (int i = 0; i < n; i++)
	{
		int h, m, d;
		std::cin >> h >> m >> d;
		int minutes = h * 60 + m + d;

		if (minutes > max)
		{
			max = minutes;
		}
	}
	
	std::cout << max / 60 << " " << max % 60;
}
