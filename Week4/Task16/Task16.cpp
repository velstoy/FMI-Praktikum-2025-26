#include<iostream>
#include<cmath>

double getPerimeter(int, int, int, int, int, int);
double getArea(int, int, int, int, int, int);
bool isInCircleWithRadius(int, int, int, int, int, int, double);
double getDistanceBetweenPoints(int, int, int, int);

int main()
{
	return 0;
}

double getPerimeter(int x1, int y1, int x2, int y2, int x3, int y3)
{
	double a = getDistanceBetweenPoints(x1, y1, x2, y2);
	double b = getDistanceBetweenPoints(x2, y2, x3, y3);
	double c = getDistanceBetweenPoints(x1, y1, x3, y3);

	return a + b + c;
}

double getArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	double a = getDistanceBetweenPoints(x1, y1, x2, y2);
	double b = getDistanceBetweenPoints(x2, y2, x3, y3);
	double c = getDistanceBetweenPoints(x1, y1, x3, y3);

	double p = getPerimeter(x1, y1, x2, y2, x3, y3);

	return sqrt(p*(p-a)*(p-b)*(p-c));
}

bool isInCircleWithRadius(int x1, int y1, int x2, int y2, int x3, int y3, double r)
{
	double a = getDistanceBetweenPoints(x1, y1, x2, y2);
	double b = getDistanceBetweenPoints(x2, y2, x3, y3);
	double c = getDistanceBetweenPoints(x1, y1, x3, y3);
	
	if (x1 >= -r && x1 <= r && y1 >= -r && y1 <= r 
		&& x2 >= -r && x2 <= r && y2 >= -r && y2 <= r 
		&& x3 >= -r && x3 <= r && y3 >= -r && y3 <= r)
	{
		return true;
	}

	return false;
}

double getDistanceBetweenPoints(int x1, int y1, int x2, int y2)
{
	return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
