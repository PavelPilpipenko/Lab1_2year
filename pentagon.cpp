#include "pch.h"
#include<iostream>
#include "pentagon.h"


using std::cout;
/**
Checks pentagon on type.

@details Checking:
\AB - distAB.
\BC - distBC.
\CD - distCD.
\DE - distDE.
\AE - distAE.
\if AB = BC and BC = CD and CD = DE and DE = AE then pentagon is regular.
*/
void pentagon::check(double distAB, double distBC, double distCD, double distDE, double distAE, pentType &type)
{
		//regular.
	if ((distAB == distBC) && (distBC == distCD) && (distCD == distDE) && (distDE == distAE)) {
		type = regular;
	}
		//print type.
	if (type == 1) {
		cout << "\nregular pentagon";
	}
}
/**
Overloaded assignment operator.

@details Assignment:
\all values of pentagon pent assign to this pentagon.
\(points, sides, perimetr, area, existence, type).
@return *this Modified pentagon.
*/
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
	_pentType = pent._pentType;
	_P = pent._P;
	_S = pent._S;
	return *this;
}
/**
Creates pentagon after input the coordinates of points.

@details Creating:
\\Step 1:
\Creating points(a, b, c, d, e)
\\Step 2:
\Checks on existence:
\Each three neighbour points (a, b, c),(b, c, d),(c, d, e),(d, e, a),(e, a, b) must be not on one line.
\Oppisite lines (AB, CD), (AB, DE), (BC, AE), (BC, DE), (CD, AE) must not have an intersection points.
\\Step 3:
\Calculating and returning:
\(sides, perimetr, area and type).
@return *this Created pentagon.
*/
pentagon pentagon::Set_pentagon()// return tmp A copy of created pentagon that we need to assign to the pentagon, created in the list,  DO same comment for triangle and tetragon 
{
		//Step 1
	create_point(_a);
	create_point(_b);
	create_point(_c);
	create_point(_d);
	create_point(_e);
	
		//Step 2
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
		//if pentagon exists then continue
	if (_PentOrNot) {
			//Step 3
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
		check(_ab, _bc, _cd, _de, _ae, _pentType);
	}
	else {
		cout << "\nThis is not pentagon";
	}
	return *this;
}
/**
Returns the existence of pentagon.

@return _PentOrNot True if pentagon exists. false if pentagon not exists.
*/
bool pentagon::Get_existence()
{
	return _PentOrNot;
}
/**
Prints info of pentagon.
\area, perimetr and type.
*/
void pentagon::print()
{
	cout << "\nPentagon:" << "\nP = " << _P;
	cout << "\nS = " << _S;
	cout << "\nType: ";
	if (_pentType == 1) {
		cout << "regular.";
	}
	else {
		cout << "standard.";
	}
}

pentagon::pentagon()//assign to all values of pentagon 0.
{
	_a.x = _a.y = 0;
	_b = _a;
	_c = _a;
	_d = _a;
	_e = _a;
	_ab = _bc = _cd = _de = _ae = _P = _S = 0;
	_pentType = not_setted_pentagon;
}


pentagon::~pentagon()
{
}
