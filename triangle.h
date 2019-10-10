#pragma once
#include"cmath"
#include"Base.h"

class triangle : public Base
{
private:
	point _a;
	point _b;
	point _c;
	void _TriangleOrNot(double AB, double AC, double BC);
public:
	double ab = 0, ac = 0, bc = 0;

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