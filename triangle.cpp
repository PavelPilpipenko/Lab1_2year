#include "pch.h"
#include "triangle.h"
#include "iostream"

using std::cout;
using std::cin;

void triangle::_TriangleOrNot(double AB, double AC, double BC)
{
	if ((AB + BC > AC) && (AB + AC > BC) && (BC + AC > AB)) {
		cout << "\nTriangle created";
	}
	else {
		cout << "\nThis is not triangle";
	}
}
triangle::triangle()
{
	//char tr_name;
	create_point(_a);
	create_point(_b);
	create_point(_c);

	ab = distTo(_a, _b);
	cout << "\nAB = " << ab;
	bc = distTo(_b, _c);
	cout << "\nBC = " << bc;
	ac = distTo(_a, _c);
	cout << "\nAC = " << ac;
	_TriangleOrNot(ab, ac, bc);

	//cout << "Enter name for triangle: ";
	//cin >> tr_name;
}

triangle::~triangle()
{
}