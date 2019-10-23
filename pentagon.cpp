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

pentagon pentagon::Set_pentagon()
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
	
}


pentagon::~pentagon()
{
}
