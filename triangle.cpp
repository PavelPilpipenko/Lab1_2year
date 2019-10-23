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
	triangle temp;
	temp._a = tr._a;
	temp._b = tr._b;
	temp._c = tr._c;
	temp._ab = tr._ab;
	temp._ac = tr._ac;
	temp._bc = tr._bc;
	temp._S = tr._S;
	temp._P = tr._P;
	return temp;
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
	_a = _b = _c = 0;
	_ab = _ac = _bc = _S = _P = 0;
}

triangle::~triangle()
{
}