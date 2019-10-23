#include "pch.h"
#include "tetragon.h"
#include <iostream>

using std::cout;

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

void tetragon::print()
{
	cout << "\nTetragon:" << "\nP = " << _P;
	cout << "\nS = " << _S;
}

tetragon::tetragon()
{
	create_point(_a);
	create_point(_b);
	create_point(_c);
	create_point(_d);

	_ab = distTo(_a, _b);
	_bc = distTo(_b, _c);
	_cd = distTo(_c, _d);
	_ad = distTo(_a, _d);
	_TetrOrNot = FigureOrNot(_ab, _bc, _cd, _ad);
	if (_TetrOrNot) {
		cout << "\nTetragon created";
		_P = perimetr(_ab, _bc, _cd, _ad);
		cout << "\nP = " << _P;
		_S = area(_ab, _bc, _cd, _ad);
		cout << "\nS = " << _S;
		check(_ab, _bc, _cd, _ad, _S);
	}
	else {
		cout << "\nThis is not Tetragon";
		return;
	}
}


tetragon::~tetragon()
{
}
