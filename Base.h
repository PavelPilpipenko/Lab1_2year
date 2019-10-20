#pragma once
#include"cmath"
class Base
{
protected:
	struct point {
		double x;//координата х
		double y;// координата y
	};
	double perimetr(double distAB, double distAC, double distBC);
	double perimetr(double distAB, double distBC, double distCD, double distAD);
	double perimetr(double distAB, double distBC, double distCD, double distDE, double distAE);
	double area(double distAB, double distAC, double distBC);
	double area(double distAB, double distBC, double distCD, double distAD);
	double area(double distAB, double distBC, double distCD, double distDE, double distAE, double distD);
	bool FigureOrNot(double distAB, double distAC, double distBC);
	bool FigureOrNot(double distAB, double distBC, double distCD, double distAD);
	bool FigureOrNot(double distAB, double distBC, double distCD, double distDE, double distAE, double distD);
	double distTo(point alfa, point beta);
	void create_point(point &p);
public:
	Base();
	~Base();
};
