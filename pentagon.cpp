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
	_PentOrNot = pent._PentOrNot;
	_P = pent._P;
	_S = pent._S;
	return *this;
}

pentagon pentagon::Set_pentagon()// return tmp A copy of created pentagon that we need to assign to the pentagon, created in the list,  DO same comment for triangle and tetragon 
{
	create_point(_a);
	create_point(_b);
	create_point(_c);
	create_point(_d);
	create_point(_e);
	
	_PentOrNot = pointsOnOneLine(_a, _b, _c);
	if (_PentOrNot) {
		_PentOrNot = pointsOnOneLine(_b, _c, _d);
	}
	if (_PentOrNot) {
		_PentOrNot = pointsOnOneLine(_c, _d, _e);
	}
	if (_PentOrNot) {
		_PentOrNot = pointsOnOneLine(_d, _e, _a);
	}
	if (_PentOrNot) {
		_PentOrNot = pointsOnOneLine(_e, _a, _b);
	}
	if (_PentOrNot) {
		_PentOrNot = checkOnIntersections(_a, _b, _c, _d);
	}
	if (_PentOrNot) {
		_PentOrNot = checkOnIntersections(_a, _b, _d, _e);
	}
	if (_PentOrNot) {
		_PentOrNot = checkOnIntersections(_b, _c, _a, _e);
	}
	if (_PentOrNot) {
		_PentOrNot = checkOnIntersections(_b, _c, _d, _e);
	}
	if (_PentOrNot) {
		_PentOrNot = checkOnIntersections(_c, _d, _a, _e);
	}
	if (_PentOrNot) {
		_ab = distTo(_a, _b);
		_bc = distTo(_b, _c);
		_cd = distTo(_c, _d);
		_de = distTo(_d, _e);
		_ae = distTo(_a, _e);
		cout << "\nPentagon created";
		_P = perimetr(_ab, _bc, _cd, _de, _ae);
		cout << "\nP = " << _P;
		_S = area(_a, _b, _c, _d, _e);
		cout << "\nS = " << _S;
		check(_ab, _bc, _cd, _de, _ae);
	}
	else {
		cout << "\nThis is not pentagon";
	}
	return *this;
}

bool pentagon::Get_existence()
{
	return _PentOrNot;
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
