#pragma once
#include"cmath"
class Base
{
protected:
	struct point {
		char name;
		double x;//���������� �
		double y;// ���������� y
	};

	double distTo(point alfa, point beta);
	char create_point();
public:
	Base(double x, double y, char name);
	~Base();
	

};

//Base operator + (Base pointPlus);//���������� +
//{
//	double xValue = this->x + pointPlus.x;
//	double yValue = this->y + pointPlus.y;
//	return Base(xValue, yValue);
//}