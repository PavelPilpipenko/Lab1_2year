#include "pch.h"
#include<iostream>
#include "triangle.h"


using std::cout;

void triangle::check(double distAB, double distAC, double distBC, double area)
{
	if ((distAB == distAC) && (distAC == distBC)) {
		cout << "\nequilateral triangle"; //равносторонний треугольник
		return;
	}
	else if ((distAB == distAC) || (distAC == distBC) || (distBC == distAB)) {
		cout << "\nisosceles triangle"; // равнобедренный треугольник
	}
	if ((distAB*distAC * 0.5 == area) || (distAC*distBC*0.5 == area) || (distAB*distBC*0.5 == area)) {
		cout << "\nright triangle"; //прямоугольный треугольник
	}
}

triangle triangle::operator=(triangle tr)
{
	_a = tr._a;
	_b = tr._b;
	_c = tr._c;
	_ab = tr._ab;
	_ac = tr._ac;
	_bc = tr._bc;
	_TrOrNot = tr._TrOrNot;
	_S = tr._S;
	_P = tr._P;
	return *this;
}

triangle triangle::Set_triangle()
{
	create_point(_a);
	create_point(_b);
	create_point(_c);

	_TrOrNot = pointsOnOneLine(_a, _b, _c);

	if (_TrOrNot) {
		_ab = distTo(_a, _b);
		_bc = distTo(_b, _c);
		_ac = distTo(_a, _c);
		cout << "\nTriangle created";
		_P = perimetr(_ab, _ac, _bc);
		cout << "\nP = " << _P;
		_S = area(_ab, _ac, _bc);
		cout << "\nS = " << _S;
		check(_ab, _ac, _bc, _S);
	}
	else {
		cout << "\nThis is not triangle";
	}
	return *this;
}

bool triangle::Get_existence()
{
	return _TrOrNot;
}

void triangle::print()
{
	cout << "\nTriangle:" << "\nP = " << _P;
	cout << "\nS = " << _S;
}


triangle::triangle()
{
	_a.x = _a.y = 0;
	_b = _a;
	_c = _a;
	_ab = _ac = _bc = _S = _P = 0;
}

triangle::~triangle()
{
}