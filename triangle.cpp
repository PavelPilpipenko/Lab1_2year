#include "pch.h"
#include "triangle.h"
#include <iostream>

using std::cout;

void triangle::check(double distAB, double distAC, double distBC, double area)
{
	if ((distAB == distAC) && (distAC == distBC)) {
		cout << "\nequilateral triangle"; //�������������� �����������
		return;
	}
	else if ((distAB == distAC) || (distAC == distBC) || (distBC == distAB)) {
		cout << "\nisosceles triangle"; // �������������� �����������
	}
	if ((distAB*distAC * 0.5 == area) || (distAC*distBC*0.5 == area) || (distAB*distBC*0.5 == area)) {
		cout << "\nright triangle"; //������������� �����������
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

void triangle::print()
{
	cout << "\nTriangle:" << "\nP = " << _P;
	cout << "\nS = " << _S;
}

triangle::triangle()
{
	create_point(_a);
	create_point(_b);
	create_point(_c);

	_ab = distTo(_a, _b);
	_bc = distTo(_b, _c);
	_ac = distTo(_a, _c);
	_TrOrNot = FigureOrNot(_ab, _ac, _bc);
	if (_TrOrNot) {
		cout << "\nTriangle created";
		_P = perimetr(_ab, _ac, _bc);
		cout << "\nP = " << _P;
		_S = area(_ab, _ac, _bc);
		cout << "\nS = " << _S;
		check(_ab, _ac, _bc, _S);
	}
	else {
		cout << "\nThis is not triangle";
		return;
	}
}

triangle::~triangle()
{
}