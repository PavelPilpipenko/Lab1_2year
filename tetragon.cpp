#include "pch.h"
#include<iostream>
#include "tetragon.h"


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

tetragon tetragon::operator=(tetragon tetr)
{
	tetragon temp;
	temp._a = tetr._a;
	temp._b = tetr._b;
	temp._c = tetr._c;
	temp._d = tetr._d;
	temp._ab = tetr._ab;
	temp._bc = tetr._bc;
	temp._cd = tetr._cd;
	temp._ad = tetr._ad;
	temp._P = tetr._P;
	temp._S = tetr._S;
	return temp;
}

tetragon tetragon::Set_tetragon()
{
	tetragon tmp;
	create_point(tmp._a);
	create_point(tmp._b);
	create_point(tmp._c);
	create_point(tmp._d);

	tmp._ab = distTo(tmp._a, tmp._b);
	tmp._bc = distTo(tmp._b, tmp._c);
	tmp._cd = distTo(tmp._c, tmp._d);
	tmp._ad = distTo(tmp._a, tmp._d);
	tmp._TetrOrNot = FigureOrNot(tmp._ab, tmp._bc, tmp._cd, tmp._ad);
	if (tmp._TetrOrNot) {
		cout << "\nTetragon created";
		tmp._P = perimetr(tmp._ab, tmp._bc, tmp._cd, tmp._ad);
		cout << "\nP = " << tmp._P;
		tmp._S = area(tmp._ab, tmp._bc, tmp._cd, tmp._ad);
		cout << "\nS = " << tmp._S;
		check(tmp._ab, tmp._bc, tmp._cd, tmp._ad, tmp._S);
	}
	else {
		cout << "\nThis is not Tetragon";
	}
	return tmp;
}

void tetragon::print()
{
	cout << "\nTetragon:" << "\nP = " << _P;
	cout << "\nS = " << _S;
}

tetragon::tetragon()
{
	_a = _b = _c = _d = 0;
	_ab = _bc = _cd = _ad = _S = _P = 0;
}


tetragon::~tetragon()
{
}
