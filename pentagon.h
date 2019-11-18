#pragma once
#include"Base.h"
#include"cmath"

class pentagon : public Base
{
private:
	point _a, _b, _c, _d, _e;//points of pentagon.
	double _ab = 0, _bc = 0, _cd = 0, _de = 0, _ae = 0, _S = 0, _P = 0;//sides, area, perimetr of pentagon.
	bool _PentOrNot;//pentagon existance
	void check(double distAB, double distBC, double distCD, double distDE, double distAE);
public:
	pentagon operator = (pentagon pent);
	pentagon Set_pentagon();
	bool Get_existence() override;
	void print() override;
	pentagon();
	~pentagon();
};

