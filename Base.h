#pragma once
#include"cmath"
class Base
{
protected:
	struct point {
		double x;//координата х
		double y;// координата y
	};

	double distTo(point &alfa, point &beta);
	void create_point(point p);
public:
	Base();
	~Base();
};

//Base operator + (Base pointPlus);//перегрузка +
//{
//	double xValue = this->x + pointPlus.x;
//	double yValue = this->y + pointPlus.y;
//	return Base(xValue, yValue);
//}