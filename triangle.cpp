#include "pch.h"
#include "triangle.h"
#include "iostream"

using std::cout;
using std::cin;

bool triangle::_TriangleOrNot(double distAB, double distAC, double distBC)
{
	if ((distAB + distBC > distAC) && (distAB + distAC > distBC) && (distBC + distAC > distAB)) {
		cout << "\nTriangle created";
		return true;
	}
	else {
		cout << "\nThis is not triangle";
		return false;
	}
}
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
triangle::triangle()
{
	//char tr_name;
	create_point(_a);
	create_point(_b);
	create_point(_c);

	_ab = distTo(_a, _b);
	_bc = distTo(_b, _c);
	_ac = distTo(_a, _c);
	_TrOrNot = _TriangleOrNot(_ab, _ac, _bc);
	if (_TrOrNot) {
		_P = perimetr(_ab, _ac, _bc);
		cout << "\nP = " << _P;
		_S = area(_ab, _ac, _bc);
		cout << "\nS = " << _S;
		check(_ab, _ac, _bc, _S);
	}
	

	//cout << "Enter name for triangle: ";
	//cin >> tr_name;
}

triangle::~triangle()
{
}