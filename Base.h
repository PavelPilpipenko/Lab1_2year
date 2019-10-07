#pragma once
#include"cmath"
class Base
{
protected:
	struct point {
		char name;
		double x;//координата х
		double y;// координата y
	};

	double distTo(point alfa, point beta);
	char create_point();
public:
	Base(double x, double y, char name);
	~Base();
	

};

//Base operator + (Base pointPlus);//перегрузка +
//{
//	double xValue = this->x + pointPlus.x;
//	double yValue = this->y + pointPlus.y;
//	return Base(xValue, yValue);
//}