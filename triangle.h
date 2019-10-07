#pragma once
#include"point.h"
#include"cmath"
#include"Base.h"


class figure {
	virtual double length(char first, char second) = 0;
};

class triangle : public Base
{
private:
	point a;
	point b;
	point c;

	double ab, bc, ac;// !!!
	

	void _TriangleOrNot();
public:
	triangle();
	double length(char first, char second) {
		point p1, p2;
		if (a.get_name() == first) p1 = a;
		if (a.get_name() == second) p2 = a;
		if (b.get_name() == first) p1 = a;
		if (b.get_name() == second) p2 = a;
		if (c.get_name() == first) p1 = a;
		if (c.get_name() == second) p2 = a;
		return calc_dist(p1, p2);
	}
	~triangle();
};

