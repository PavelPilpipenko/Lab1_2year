#pragma once
#include"cmath"
#include"Base.h"

class triangle : public Base
{
private:
	point _a, _b, _c;
	double _ab = 0, _ac = 0, _bc = 0, _P = 0, _S = 0;
	bool _TrOrNot;
	//bool TriangleOrNot(double distAB, double distAC, double distBC);
	void check(double distAB, double distAC, double distBC, double area);
public:
	triangle();
	~triangle();
};

//double length(char first, char second) {
//	point p1, p2;
//	if (a.get_name() == first) p1 = a;
//	if (a.get_name() == second) p2 = a;
//	if (b.get_name() == first) p1 = a;
//	if (b.get_name() == second) p2 = a;
//	if (c.get_name() == first) p1 = a;
//	if (c.get_name() == second) p2 = a;
//	return calc_dist(p1, p2);
//}