#include "pch.h"
#include "point.h"
#include "cmath"


point::point(double x, double y)
{
	this->x = x;
	this->y = y;
}

point::~point()
{
}

double point::distance(point first, point second)
{
	double dist = sqrt(pow((second.x - first.x), 2) + pow((second.y - first.y), 2));
	return dist;
}



point point::operator+(point pointPlus)
{
	double xValue = this->x + pointPlus.x;
	double yValue = this->y + pointPlus.y;
	return point(xValue, yValue);
}

