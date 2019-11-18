#pragma once
#include<iostream>
#include"cmath"
#include"Base.h"

enum trType {not_setted_triangle, equilateral, isosceles, right};
class triangle : public Base
{
private:
	point _a, _b, _c;//points of triangle
	double _ab, _ac, _bc, _P, _S;//sides, perimetr and area of triangle.
	bool _TrOrNot;//triangle existence
	trType _trType;//triangle type.
	/**
	Checks triangle on type. Equilateral, isosceles, right triangle.
	
	@param distAB Dist from point A to point B.
	@param distAC Dist from point A to point C.
	@param distBC Dist from point B to point C.
	@param area Area of triangle.
	@param type Type of triangle.
	*/
	void check(double distAB, double distAC, double distBC, double area, trType &type);
public:
	/**
	Overloaded assignment operator.
	
	@param tr Triangle which we want to assign to this triangle.
	@return *this Modified triangle.
	*/
	triangle operator = (triangle tr);
	/**
	Creates triangle after input the coordinates of points.
	
	@return *this Created triangle.
	*/
	triangle Set_triangle();
	/**
	Returns the existence of triangle.
	
	@return true if triangle exist. false if triangle dont exist.
	*/
	bool Get_existence() override;
	/**
	Prints the triangle information.
	\ Area, perimetr and type of triangle.
	*/
	void print() override;

	triangle();
	~triangle();
};