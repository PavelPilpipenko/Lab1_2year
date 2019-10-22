#include "pch.h"
#include "Base.h"
#include <iostream>

using std::cin;
using std::cout;

double Base::perimetr(double distAB, double distAC, double distBC)
{
	double perimetr_tr = distAB + distAC + distBC;
	return perimetr_tr;
}

double Base::perimetr(double distAB, double distBC, double distCD, double distAD)
{
	double perimetr_tetr = distAB + distBC + distCD + distAD;
	return perimetr_tetr;
}

double Base::perimetr(double distAB, double distBC, double distCD, double distDE, double distAE)
{
	double perimetr_pent = distAB + distBC + distCD + distDE + distAE;
	return perimetr_pent;
}

double Base::area(double distAB, double distAC, double distBC)
{
	double half_perimetr_tr = perimetr(distAB, distAC, distBC) / 2;
	double area_tr = sqrt(half_perimetr_tr * (half_perimetr_tr - distAB) * (half_perimetr_tr - distAC) * (half_perimetr_tr - distBC));
	return area_tr;
}

double Base::area(double distAB, double distBC, double distCD, double distAD)
{
	double half_perimetr_tetr = perimetr(distAB, distBC, distCD, distAD) / 2;
	double area_tetr = sqrt((half_perimetr_tetr - distAB) * (half_perimetr_tetr - distBC) * (half_perimetr_tetr - distCD) * (half_perimetr_tetr - distAD));
	return area_tetr;
}

double Base::area(double distAB, double distBC, double distCD, double distDE, double distAE, double distD)
{
	double area_pent, area_tr, area_tetr;
	area_tr = area(distAB, distBC, distD);
	area_tetr = area(distCD, distDE, distAE, distD);
	return area_pent = area_tr + area_tetr;
}

bool Base::FigureOrNot(double distAB, double distAC, double distBC)
{
	if ((distAB + distBC > distAC) && (distAB + distAC > distBC) && (distBC + distAC > distAB)) { //Cheks the existence of triangle. Every side must be smaller then sum of other sides.
		return true;
	}
	else {
		return false;
	}
}

bool Base::FigureOrNot(double distAB, double distBC, double distCD, double distAD)
{
	if ((distAB < distBC + distCD + distAD) && (distBC < distAB + distCD + distAD) && (distCD < distAB + distBC + distAD) && (distAD < distAB + distBC + distCD)) { //Cheks the existence of tetragon. Every side must be bigger than sum of other sides.
		return true;
	}
	else {
		return false;
	}
}

bool Base::FigureOrNot(double distAB, double distBC, double distCD, double distDE, double distAE, double distD)
{
	bool TrOrNot = false;
	bool TetrOrNot = false;
	TrOrNot = FigureOrNot(distAB, distBC, distD); //Check the triangle existence.
	TetrOrNot = FigureOrNot(distCD, distDE, distAE, distD); //Check the tetragon existence.
	if ((TrOrNot) && (TetrOrNot)) { //if triangle and pentagon exists - return true.
		return true;
	}
	else {
		return false;
	}
}

double Base::distTo(point alfa, point beta)
{
	double dist = sqrt(pow((alfa.x - beta.x), 2) + pow((alfa.y - beta.y), 2)); //Formula of dist between points.
	return dist;
}


void Base::create_point(point &p)
{
	point temp;
	cout << "\nEnter X for point: ";
	cin >> temp.x; //User's input the coordinate x.
	p.x = temp.x;
	cout << "Enter Y for point: ";
	cin >> temp.y; //User's input the coordinate y.
	p.y = temp.y;
	cout << "Point created";
}

Base::Base()
{
}

Base::~Base()
{
}