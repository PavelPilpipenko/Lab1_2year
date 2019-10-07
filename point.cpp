#include "pch.h"
#include "point.h"
#include "cmath"


point::point(double x, double y, char name) : x(x), y(y), name(name) {}

point::~point()
{
}



point point::operator+(point pointPlus)
{
	double xValue = this->x + pointPlus.x;
	double yValue = this->y + pointPlus.y;
	return point(xValue, yValue);
}

