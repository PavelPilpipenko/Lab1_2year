#pragma once
#include<iostream>
#include"cmath"
#include"Base.h"


using std::cout;

class triangle : public Base
{
private:
	point _a, _b, _c;
	double _ab, _ac, _bc, _P, _S;
	bool _TrOrNot;
	void check(double distAB, double distAC, double distBC, double area);
public:
	triangle operator = (triangle tr);
	triangle Set_triangle();
	void print() override;

	triangle();
	~triangle();
};