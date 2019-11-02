#pragma once
#include<iostream>
#include"cmath"
#include"Base.h"


using std::cout;

class triangle : public Base
{
private:
	point _a, _b, _c;//points of triangle
	double _ab, _ac, _bc, _P, _S;//sides, perimetr and area of triangle.
	bool _TrOrNot;//triangle existence
	/**
	Checks the triangle. Equilateral, isosceles, right triangles.
	
	@param distAB Dist from point A to point B.
	@param distAC Dist from point A to point C.
	@param distBC Dist from point B to point C.
	@param area Area of triangle.
	*/
	void check(double distAB, double distAC, double distBC, double area);
public:
	/**
	Overloaded assignment operator.
	
	@param tr Triangle which we want to assign to this triangle.
	@return *this Modified triangle.
	*/
	triangle operator = (triangle tr);
	/**
	Creates triangle after input the coordinates of points.
	
	@return tmp Created triangle.
	*/
	triangle Set_triangle();
	bool Get_existence() override;
	void print() override;

	triangle();
	~triangle();
};