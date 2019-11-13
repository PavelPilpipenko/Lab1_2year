#include "pch.h"
#include "Base.h"
#include <iostream>

using std::cin;
using std::cout;
using std::swap;

/**
Calculates the perimetr of triangle.

@details Perimetr: the sum of all sides.
*/
double Base::perimetr(double distAB, double distAC, double distBC)
{
	float perimetr_tr = distAB + distAC + distBC;
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
//2S = x1(y2-y5) + x2(y3-y1) + x3(y4-y2) + x4(y5-y3) + x5(y1-y4)
double Base::area(point a, point b, point c, point d, point e)
{
	double area_pent = (a.x * (b.y - e.y) + b.x * (c.y - a.y) + c.x * (d.y - b.y) + d.x * (e.y - c.y) + e.x * (a.y - d.y)) / 2;
	return area_pent;
}

bool Base::checkOnIntersections(point lineApoint1, point lineApoint2, point lineBpoint1, point lineBpoint2)
{
	double lineAñoefficient, lineBcoefficient, lineAfreeMember, lineBfreeMember, intersectionY1, intersectionY2;
	point intersectionPoint;
	if (lineApoint1.x >= lineApoint2.x) {
		swap(lineApoint1, lineApoint2);
	}
	if (lineBpoint1.x >= lineBpoint2.x) {
		swap(lineBpoint1, lineBpoint2);
	}
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
		return true;
	}
	else {
		lineAfreeMember = lineApoint1.y - (lineAñoefficient * lineApoint1.x);
		lineBfreeMember = lineBpoint1.y - (lineBcoefficient * lineBpoint1.x);
		intersectionPoint.x = (lineBfreeMember - lineAfreeMember) / (lineAñoefficient - lineBcoefficient);
		intersectionY1 = (lineAñoefficient * intersectionPoint.x) + lineAfreeMember;
		intersectionY2 = (lineBcoefficient * intersectionPoint.x) + lineBfreeMember;
		if ((intersectionY1 <= intersectionY2 + 0.0000001) && (intersectionY1 >= intersectionY2 - 0.0000001) && (lineApoint1.x <= intersectionPoint.x) && (intersectionPoint.x <= lineApoint2.x) && (lineBpoint1.x <= intersectionPoint.x) && (intersectionPoint.x <= lineBpoint2.x)) {
			intersectionPoint.y = intersectionY1;
			cout << "\nThis is figure with intersections\nIntersection point: (" << intersectionPoint.x << "," << intersectionPoint.y << ")\n";
			return false;
		}
		else {
			return true;
		}
	}
}
bool Base::pointsOnOneLine(point a, point b, point c)
{
	double result;
	result = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	if (result == 0) {
		return false;
	}
	else {
		return true;
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

