#include "pch.h"
#include<iostream>
#include "tetragon.h"


using std::cout;
using std::swap;
/**
Checks tetragon on type. Parallelogram, rectangle, square, rhombus, trapezoid.

@details Checking:
\AB - distAB.
\BC - distBC.
\CD - distCD.
\AD - distAD.
\S - area.
\d1 - main diagonal.
\d2 - side diagonal.
\
\if AB = CD and BC = AD then tetragon is parallelogram.
\if tetragon is parallelogram and S = AB * BC and d1 = d2 then tetragon is rectangle.
\if tetragon is rectangle and S = AB * AB then tetragon is square.
\if tetragon isnt rectangle and AB = BC and CD = AD and d1 != d2 then tetragon is rhombus.
\if d1 = (CD^2 + AD*BC - ((AD * CD^2 - AB^2)/(AD - BC))^1/2 or d1 = (BC^2 + AB*CD - (AB*BC^2 - AD^2) / (AB - CD))^1/2 then tetragon is trapezoid.
*/
void tetragon::check(double distAB, double distBC, double distCD, double distAD, double area, tetrType &type)
{
	double d_main, d_side;
	d_main = distTo(_a, _c);
	d_side = distTo(_b, _d);
		//parallelogram.
	if ((distAB == distCD) && (distBC == distAD)) {
		type = parallelogram;
			//rectangle.
		if ((area == distAB * distBC) && (d_main == d_side)) {
			type = rectangle;
				//square.
			if (area == distAB * distAB) {
				type = square;
			}
		}
			//rhombus.
		if (type != rectangle) {
			if ((distAB == distBC) && (distCD == distAD) && (d_main != d_side)) {
				type = rhombus;
			}
		}
	}
		//trapezoid.
	else if ((d_main == sqrt(pow(distCD,2) + distAD*distBC - ((distAD*(pow(distCD,2) - pow(distAB,2)))/(distAD - distBC)))) || (d_main == sqrt(pow(distBC, 2) + distAB * distCD - ((distAB*(pow(distBC, 2) - pow(distAD, 2))) / (distAB - distCD))))) {
		type = trapezoid;
	}
		//print type
	if (type == 1) {
		cout << "\nparallelogram";
	}
	else if (type == 2) {
		cout << "\nrectangle";
	}
	else if (type == 3) {
		cout << "\nsquare";
	}
	else if (type == 4) {
		cout << "\nrhombus";
	}
	else if (type == 5) {
		cout << "\ntrapezoid";
	}
}
/**
Overloaded assignment operator.

@details Assignment:
\all values of tetragon tetr assign to this tetragon.
\(points, sides, perimetr, area, existence, type).
@return *this Modified tetragon.
*/
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
	_tetrType = tetr._tetrType;
	_P = tetr._P;
	_S = tetr._S;
	return *this;
}
/**
Creates tetragon after input the coordinates of points.

@details Creating:
\\Step 1:
\Creating points(a, b, c, d)
\\Step 2:
\Checks on existence: 
\Each three neighbour points (a, b, c),(b, c, d),(c, d, a),(d, a, b) must be not on one line.
\Oppisite lines (AB, CD), (AC, BD) must not have an intersection points.
\\Step 3:
\Calculating and returning:
\(sides, perimetr, area and type).
@return *this Created tetragon.
*/
tetragon tetragon::Set_tetragon()
{
	bool swapcoordinates1 = false, swapcoordinates2 = false;
		//Step 1
	create_point(_a);
	create_point(_b);
	create_point(_c);
	create_point(_d);

		//Step 2
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
		//if tetragon exists then continue.
	if (_TetrOrNot) {
			//Step 3
		_ab = distTo(_a, _b);
		_bc = distTo(_b, _c);
		_cd = distTo(_c, _d);
		_ad = distTo(_a, _d);
		cout << "\nTetragon created";
		_P = perimetr(_ab, _bc, _cd, _ad);
		cout << "\nP = " << _P;
		_S = area(_ab, _bc, _cd, _ad);
		cout << "\nS = " << _S;
		check(_ab, _bc, _cd, _ad, _S, _tetrType);
	}
	else {
		cout << "\nThis is not Tetragon";
	}
	return *this;
}
/**
Returns existence of tetragon

@return _TetrOrNot True if tetragon exists. false if tetragon isnt exists.
*/
bool tetragon::Get_existence()
{
	return _TetrOrNot;
}
/**
Prints the information of tetragon.
\area, perimetr and type.
*/
void tetragon::print()
{
	cout << "\nTetragon:" << "\nP = " << _P;
	cout << "\nS = " << _S;
	cout << "\nType: ";
	if (_tetrType == 1) {
		cout << "parallelogram.";
	}
	else if (_tetrType == 2) {
		cout << "rectangle.";
	}
	else if (_tetrType == 3) {
		cout << "square.";
	}
	else if (_tetrType == 4) {
		cout << "rhombus.";
	}
	else if (_tetrType == 5) {
		cout << "trapezoid.";
	}
	else {
		cout << "standard.";
	}
}

double tetragon::Get_area()
{
	return _S;
}

double tetragon::Get_perimetr()
{
	return _P;
}

tetragon::tetragon() //assign to all values of tetragon 0.
{
	_a.x = _a.y = 0;
	_b = _a;
	_c = _a;
	_d = _a;
	_ab = _bc = _cd = _ad = _S = _P = 0;
	_tetrType = not_setted_tetragon;
}


tetragon::~tetragon()
{
}
