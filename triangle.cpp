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
	_S = tr._S;
	_P = tr._P;
	return *this;
}

triangle triangle::Set_triangle()
{
	triangle tmp;
	create_point(tmp._a);
	create_point(tmp._b);
	create_point(tmp._c);

	tmp._ab = distTo(tmp._a, tmp._b);
	tmp._bc = distTo(tmp._b, tmp._c);
	tmp._ac = distTo(tmp._a, tmp._c);
	tmp._TrOrNot = FigureOrNot(tmp._ab, tmp._ac, tmp._bc);
	if (tmp._TrOrNot) {
		cout << "\nTriangle created";
		tmp._P = perimetr(tmp._ab, tmp._ac, tmp._bc);
		cout << "\nP = " << tmp._P;
		tmp._S = area(tmp._ab, tmp._ac, tmp._bc);
		cout << "\nS = " << tmp._S;
		check(tmp._ab, tmp._ac, tmp._bc, tmp._S);
	}
	else {
		cout << "\nThis is not triangle";
	}
	return tmp;
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