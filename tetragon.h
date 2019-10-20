#pragma once
#include"cmath"
#include"Base.h"

class tetragon : public Base
{
private:
	point _a, _b, _c, _d;
	double _ab = 0, _bc = 0, _cd = 0, _ad = 0, _S = 0, _P = 0;
	bool _TetrOrNot;
	//bool TetragonOrNot(double distAB, double distBC, double distCD, double distAD);
	void check(double distAB, double distBC, double distCD, double distAD, double area);
public:
	tetragon();
	~tetragon();
};

