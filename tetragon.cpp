#include "pch.h"
#include<iostream>
#include "tetragon.h"


using std::cout;
using std::swap;

void tetragon::check(double distAB, double distBC, double distCD, double distAD, double area)
{
	bool rectangle = false;
	double d_main, d_side;
	d_main = distTo(_a, _c);
	d_side = distTo(_b, _d);
	if ((distAB == distCD) && (distBC == distAD)) {
		cout << "\nThis is parallelogram";
		if ((area == distAB * distBC) && (d_main == d_side)) {
			cout << "\n...\nThis is rectangle";
			rectangle = true;
			if (area == distAB * distAB) {
				cout << "\n...\nThis is square";
			}
		}
		if (!rectangle) {
			if ((distAB == distBC) && (distCD == distAD) && (d_main != d_side)) {
				cout << "\n...\nThis is rhombus";
			}
		}
	}
	else if ((d_main == sqrt(pow(distCD,2) + distAD*distBC - ((distAD*(pow(distCD,2) - pow(distAB,2)))/(distAD - distBC)))) || (d_main == sqrt(pow(distBC, 2) + distAB * distCD - ((distAB*(pow(distBC, 2) - pow(distAD, 2))) / (distAB - distCD))))) {
		cout << "\nThis is trapezoid";
	}
}

tetragon tetragon::operator=(tetragon tetr)
{
	_a = tetr._a;
	_b = tetr._b;
	_c = tetr._c;
	_d = tetr._d;
	_ab = tetr._ab;
	_bc = tetr._bc;
	_cd = tetr._cd;
	_ad = tetr._ad;
	_TetrOrNot = tetr._TetrOrNot;
	_P = tetr._P;
	_S = tetr._S;
	return *this;
}

tetragon tetragon::Set_tetragon()
{
	bool swapcoordinates1 = false, swapcoordinates2 = false;
	create_point(_a);
	create_point(_b);
	create_point(_c);
	create_point(_d);

	_TetrOrNot = pointsOnOneLine(_a, _b, _c);
	if (_TetrOrNot) {
		_TetrOrNot = pointsOnOneLine(_b, _c, _d);
	}
	if (_TetrOrNot) {
		_TetrOrNot = pointsOnOneLine(_c, _d, _a);
	}
	if (_TetrOrNot) {
		_TetrOrNot = pointsOnOneLine(_d, _a, _b);
	}
	if (_TetrOrNot) {
		_TetrOrNot = checkOnIntersections(_a, _b, _c, _d);
	}
	if (_TetrOrNot) {
		_TetrOrNot = checkOnIntersections(_a, _d, _b, _c);
	}
	if (_TetrOrNot) {
		_ab = distTo(_a, _b);
		_bc = distTo(_b, _c);
		_cd = distTo(_c, _d);
		_ad = distTo(_a, _d);
		cout << "\nTetragon created";
		_P = perimetr(_ab, _bc, _cd, _ad);
		cout << "\nP = " << _P;
		_S = area(_ab, _bc, _cd, _ad);
		cout << "\nS = " << _S;
		check(_ab, _bc, _cd, _ad, _S);
	}
	else {
		cout << "\nThis is not Tetragon";
	}
	return *this;
}

bool tetragon::Get_existence()
{
	return _TetrOrNot;
}

void tetragon::print()
{
	cout << "\nTetragon:" << "\nP = " << _P;
	cout << "\nS = " << _S;
}

tetragon::tetragon()
{
	_a.x = _a.y = 0;
	_b = _a;
	_c = _a;
	_d = _a;
	_ab = _bc = _cd = _ad = _S = _P = 0;
}


tetragon::~tetragon()
{
}
