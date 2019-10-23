#include "pch.h"
#include "pentagon.h"
#include <iostream>

using std::cout;

void pentagon::check(double distAB, double distBC, double distCD, double distDE, double distAE)
{
	if ((distAB == distBC) && (distBC == distCD) && (distCD == distDE) && (distDE == distAE)) {
		cout << "\nThis is regular pentagon";
	}
}

void pentagon::print()
{
	cout << "\nPentagon:" << "\nP = " << _P;
	cout << "\nS = " << _S;
}

pentagon::pentagon()
{
	create_point(_a);
	create_point(_b);
	create_point(_c);
	create_point(_d);
	create_point(_e);

	_ab = distTo(_a, _b);
	_bc = distTo(_b, _c);
	_cd = distTo(_c, _d);
	_de = distTo(_d, _e);
	_ae = distTo(_a, _e);
	_acDiagonal = distTo(_a, _c);
	_PentOrNot = FigureOrNot(_ab, _bc, _cd, _de, _ae, _acDiagonal);
	if (_PentOrNot) {
		cout << "\nPentagon created";
		_P = perimetr(_ab, _bc, _cd, _de, _ae);
		cout << "\nP = " << _P;
		_S = area(_ab, _bc, _cd, _de, _ae, _acDiagonal);
		cout << "\nS = " << _S;
		check(_ab, _bc, _cd, _de, _ae);
	}
}


pentagon::~pentagon()
{
}
