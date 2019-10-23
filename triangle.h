#pragma once
#include"cmath"
#include"Base.h"

class triangle : public Base
{
private:
	point _a, _b, _c;
	double _ab = 0, _ac = 0, _bc = 0, _P = 0, _S = 0;
	bool _TrOrNot;
	void check(double distAB, double distAC, double distBC, double area);
public:
	triangle operator = (triangle tr);
	void print() override;
	triangle();
	~triangle();
};