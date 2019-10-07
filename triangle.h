#pragma once
#include"point.h"
#include"cmath"


class figure {
	double calc_dist(point a, point b) {
		double dist = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
		return dist;
	}
	virtual double length(char first, char second) = 0;
};

class triangle : public figure
{
private:
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
protected:
	point a;
	point b;
	point c;
};

