#pragma once
#include"point.h"
#include"cmath"

class triangle
{
private:
	void _TriangleOrNot();
public:
	triangle();
	~triangle();
protected:
	point a;
	point b;
	point c;
};

