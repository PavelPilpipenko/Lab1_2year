#include "pch.h"
#include<iostream>
#include "triangle.h"


using std::cout;
/**
Checks the triangle. Equilateral, isosceles, right triangle.

@details Checking:
\AB, AC, BC - sides of triangle.
\S - area of triangle.
\
\if AB = AC and AC = BC then triangle is equilateral.
\if AB = AC or AC = BC or BC = AB then triangle is isosceles.
\if AB * AC * 0.5 = S or AC * BC * 0.5 = S or AB * BC * 0.5 = S then triangle is right.
*/
void triangle::check(double distAB, double distAC, double distBC, double area, trType &type)
{
		//equilateral.
	if ((distAB == distAC) && (distAC == distBC)) {
		type = equilateral;
		return;
	}
		//isosceles.
	else if ((distAB == distAC) || (distAC == distBC) || (distBC == distAB)) {
		type = isosceles;
	}
		//right.
	if ((distAB*distAC * 0.5 == area) || (distAC*distBC*0.5 == area) || (distAB*distBC*0.5 == area)) {
		type = right;
	}
		//print type.
	if (type == 1) {
		cout << "\nequilateral triangle.";
	}
	else if (type == 2) {
		cout << "\nisosceles triangle";
	}
	else if (type == 3) {
		cout << "\nright triangle.";
	}
	
}
/**
Overloaded assignment operator.

@details Assignment:
\all values of triangle tr assign to this triangle
\(points, sides, perimetr, area, existence, type).
@return *this Modified triangle.
*/
triangle triangle::operator=(triangle tr)
{
	_a = tr._a;
	_b = tr._b;
	_c = tr._c;
	_ab = tr._ab;
	_ac = tr._ac;
	_bc = tr._bc;
	_TrOrNot = tr._TrOrNot;
	_trType = tr._trType;
	_S = tr._S;
	_P = tr._P;
	return *this;
}
/**
Creates triangle after input the coordinates of points.

@details Creating:
\\Step 1:
\Creating points(a, b, c)
\\Step 2:
\Checks on existence: points a, b, c must be not on one line.
\\Step 3:
\Calculating and returning:
\(sides, perimetr, area and type).
@return *this Created triangle.
*/
triangle triangle::Set_triangle()
{
		//Step 1
	create_point(_a);
	create_point(_b);
	create_point(_c);
	
		//Step 2
	_TrOrNot = pointsOnOneLine(_a, _b, _c);

		//if triangle exists then continue.
	if (_TrOrNot) {
			//Step 3
		_ab = distTo(_a, _b);
		_bc = distTo(_b, _c);
		_ac = distTo(_a, _c);
		cout << "\nTriangle created";
		_P = perimetr(_ab, _ac, _bc);
		cout << "\nP = " << _P;
		_S = area(_ab, _ac, _bc);
		cout << "\nS = " << _S;
		check(_ab, _ac, _bc, _S, _trType);
	}
	else {
		cout << "\nThis is not triangle";
	}
	return *this;
}
/**
Returns the existence of triangle.

@return _TrOrNot True if triangle exist. false if triangle dont exist.
*/
bool triangle::Get_existence()
{
	return _TrOrNot;
}
/**
Prints the triangle information.
\ Area, perimetr and type of triangle.
*/
void triangle::print()
{
	cout << "\nTriangle:" << "\nP = " << _P;
	cout << "\nS = " << _S;
	cout << "\nType: ";
	if (_trType == 1) {
		cout << "equilateral.";
	}
	else if (_trType == 2) {
		cout << "isosceles.";
	}
	else if (_trType == 3) {
		cout << "right.";
	}
	else {
		cout << "standard.";
	}
}

triangle::triangle() //assign to all values of triangle 0.
{
	_a.x = _a.y = 0;
	_b = _a;
	_c = _a;
	_ab = _ac = _bc = _S = _P = 0;
	_trType = not_setted_triangle;
}

triangle::~triangle()
{
}