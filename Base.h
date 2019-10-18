#pragma once
#include"cmath"
class Base
{
protected:
	struct point {
		double x;//���������� �
		double y;// ���������� y
	};
	double perimetr(double distAB, double distAC, double distBC);
	double perimetr(double distAB, double distBC, double distCD, double distAD);
	double area(double distAB, double distAC, double distBC);
	double area(double distAB, double distBC, double distCD, double distAD);
	double distTo(point alfa, point beta);
	void create_point(point &p);
public:
	Base();
	~Base();
};

//Base operator + (Base pointPlus);//���������� +
//{
//	double xValue = this->x + pointPlus.x;
//	double yValue = this->y + pointPlus.y;
//	return Base(xValue, yValue);
//}