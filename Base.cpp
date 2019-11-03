#include "pch.h"
#include "Base.h"
#include <iostream>

using std::cin;
using std::cout;

/**
Calculates the perimetr of triangle.

@details Perimetr: the sum of all sides.
*/
double Base::perimetr(double distAB, double distAC, double distBC)
{
	double perimetr_tr = distAB + distAC + distBC;
	return perimetr_tr;
}
/**
Calculates the perimetr of tetragon.

@details Perimetr: the sum of all sides.
*/
double Base::perimetr(double distAB, double distBC, double distCD, double distAD)
{
	double perimetr_tetr = distAB + distBC + distCD + distAD;
	return perimetr_tetr;
}
/**
Calculates the perimetr of pentagon.

@details Perimetr: the sum of all sides.
*/
double Base::perimetr(double distAB, double distBC, double distCD, double distDE, double distAE)
{
	double perimetr_pent = distAB + distBC + distCD + distDE + distAE;
	return perimetr_pent;
}
/**
Calculates the area of triangle.

@details Area: Heron formula for triangle.
*/
double Base::area(double distAB, double distAC, double distBC)
{
	double half_perimetr_tr = perimetr(distAB, distAC, distBC) / 2;
	double area_tr = sqrt(half_perimetr_tr * (half_perimetr_tr - distAB) * (half_perimetr_tr - distAC) * (half_perimetr_tr - distBC));
	return area_tr;
}
/**
Calculates the area of tetragon.

@details Area: Heron formula for tetragon.
*/
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
/**
Checks the triangle existence.

@details Triangle existence: Every side must be smaller then sum of other sides.
*/
bool Base::FigureOrNot(double distAB, double distAC, double distBC)
{
	if ((distAB + distBC > distAC) && (distAB + distAC > distBC) && (distBC + distAC > distAB)) { 
		return true;
	}
	else {
		return false;
	}
}
/**
Checks the tetragon existence.

@details Tetragon existence: Every side must be bigger than sum of other sides.
*/
bool Base::FigureOrNot(double distAB, double distBC, double distCD, double distAD)
{
	if ((distAB < distBC + distCD + distAD) && (distBC < distAB + distCD + distAD) && (distCD < distAB + distBC + distAD) && (distAD < distAB + distBC + distCD)) { 
		return true;
	}
	else {
		return false;
	}
}

bool Base::FigureOrNot(double distAB, double distBC, double distCD, double distDE, double distAE, double distD)
{
	bool TetrOrNot, TrOrNot = false;
	TrOrNot = FigureOrNot(distAB, distBC, distD); //Check the triangle existence.
	TetrOrNot = FigureOrNot(distCD, distDE, distAE, distD); //Check the tetragon existence.
	if ((TrOrNot) && (TetrOrNot)) { //if triangle and pentagon exists - return true.
		return true;
	}
	else {
		return false;
	}
}
bool Base::checkOnIntersections(point & lineApoint1, point & lineApoint2, point & lineBpoint1, point & lineBpoint2)
{
	double lineAñoefficient, lineBcoefficient, lineAfreeMember, lineBfreeMember, intersectionY1, intersectionY2;
	point intersectionPoint;
	if (lineApoint2.y == lineApoint1.y) {
		lineAñoefficient = 0;
	}
	else {
		lineAñoefficient = ((lineApoint2.y - lineApoint1.y) / (lineApoint2.x - lineApoint1.x));
	}
	if (lineBpoint2.y == lineBpoint1.y) {
		lineBcoefficient = 0;
	}
	else {
		lineBcoefficient = ((lineBpoint2.y - lineBpoint1.y) / (lineBpoint2.x - lineBpoint1.x));
	}
	if (lineAñoefficient == lineBcoefficient) {
		return false;
	}
	else {
		lineAfreeMember = lineApoint1.y - (lineAñoefficient * lineApoint1.x);
		lineBfreeMember = lineBpoint1.y - (lineBcoefficient * lineBpoint1.x);
		intersectionPoint.x = (lineBfreeMember - lineAfreeMember) / (lineAñoefficient - lineBcoefficient);
		intersectionY1 = (lineAñoefficient * intersectionPoint.x) + lineAfreeMember;
		intersectionY2 = (lineBcoefficient * intersectionPoint.x) + lineBfreeMember;
		if (((intersectionY1 == intersectionY2) && (lineApoint1.x <= lineBpoint2.x) && (lineBpoint2.x <= lineApoint2.x)) || (intersectionY1 == intersectionY2) && (lineApoint1.x <= lineBpoint1.x) && (lineBpoint1.x <= lineApoint2.x)) {
			intersectionPoint.y = intersectionY1;
			cout << "\nThis is figure with intersections\nIntersection point: (" << intersectionPoint.x << "," << intersectionPoint.y << ")\n";
			return true;
		}
		else {
			return false;
		}
	}
}
/**
Calculates the dist from point to point.

@details Dist: formula of dist between points.
*/
double Base::distTo(point alfa, point beta)
{
	double dist = sqrt(pow((alfa.x - beta.x), 2) + pow((alfa.y - beta.y), 2));
	return dist;
}
/**
Create the point.

@details Creating the point: user input coordinate x and coordinate y from keyboard.
*/
void Base::create_point(point &p)
{
	point temp;
	cout << "\nEnter X for point: ";
	cin >> temp.x; //User inputs the coordinate x.
	p.x = temp.x;
	cout << "Enter Y for point: ";
	cin >> temp.y; //User inputs the coordinate y.
	p.y = temp.y;
	cout << "Point created";
}

Base::Base()
{
}

Base::~Base()
{
}

