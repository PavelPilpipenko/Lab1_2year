#include "pch.h"
#include<iostream>
#include "pentagon.h"


using std::cout;

void pentagon::check(double distAB, double distBC, double distCD, double distDE, double distAE)
{
	if ((distAB == distBC) && (distBC == distCD) && (distCD == distDE) && (distDE == distAE)) {
		cout << "\nThis is regular pentagon";
	}
}

pentagon pentagon::operator=(pentagon pent)
{
	_a = pent._a;
	_b = pent._b;
	_c = pent._c;
	_d = pent._d;
	_e = pent._e;
	_ab = pent._ab;
	_bc = pent._bc;
	_cd = pent._cd;
	_de = pent._de;
	_ae = pent._ae;
	_P = pent._P;
	_S = pent._S;
	return *this;
}

pentagon pentagon::Set_pentagon()// return tmp A copy of created pentagon that we need to assign to the pentagon, created in the list,  DO same comment for triangle and tetragon 
{
	pentagon tmp;
	create_point(tmp._a);
	create_point(tmp._b);
	create_point(tmp._c);
	create_point(tmp._d);
	create_point(tmp._e);

	tmp._ab = distTo(tmp._a, tmp._b);
	tmp._bc = distTo(tmp._b, tmp._c);
	tmp._cd = distTo(tmp._c, tmp._d);
	tmp._de = distTo(tmp._d, tmp._e);
	tmp._ae = distTo(tmp._a, tmp._e);
	tmp._acDiagonal = distTo(tmp._a, tmp._c);
	tmp._PentOrNot = FigureOrNot(tmp._ab, tmp._bc, tmp._cd, tmp._de, tmp._ae, tmp._acDiagonal);
	if (tmp._PentOrNot) {
		cout << "\nPentagon created";
		tmp._P = perimetr(tmp._ab, tmp._bc, tmp._cd, tmp._de, tmp._ae);
		cout << "\nP = " << tmp._P;
		tmp._S = area(tmp._ab, tmp._bc, tmp._cd, tmp._de, tmp._ae, tmp._acDiagonal);
		cout << "\nS = " << tmp._S;
		check(tmp._ab, tmp._bc, tmp._cd, tmp._de, tmp._ae);
	}
	return tmp;
}

void pentagon::print()
{
	cout << "\nPentagon:" << "\nP = " << _P;
	cout << "\nS = " << _S;
}

pentagon::pentagon()
{
	_a.x = _a.y = 0;
	_b = _a;
	_c = _a;
	_d = _a;
	_e = _a;
	_ab = _bc = _cd = _de = _ae = _P = _S = 0;
}


pentagon::~pentagon()
{
}
