#include "pch.h"
#include "triangle.h"
#include "iostream"

using std::cout;
using std::cin;

void triangle::_TriangleOrNot(double AB, double AC, double BC)
{
	if ((AB + BC < AC) && (AB + AC < BC) && (BC + AC < AB)) {
		cout << "Triangle created";
	}
	else {
		cout << "This is not triangle";
	}
}

triangle::triangle()
{
	double ab = 0, ac = 0, bc = 0;
	char tr_name;
	create_point(_a);
	create_point(_b);
	create_point(_c);

	ab = distTo(_a, _b);
	cout << "AB = " << ab;
	bc = distTo(_b, _c);
	cout << "BC = " << bc;
	ac = distTo(_a, _c);
	cout << "AC = " << ac;
	_TriangleOrNot(ab, ac, bc);

	cout << "Enter name for triangle: ";
	cin >> tr_name;
}

triangle::~triangle()
{
}