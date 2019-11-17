#include "pch.h"
#include "Base.h"
#include <iostream>

using std::cin;
using std::cout;
using std::swap;

/**
Calculates the perimetr of triangle.

@details Perimetr: the sum of all sides.
@return the perimetr of a triangle.
*/
double Base::perimetr(double distAB, double distAC, double distBC)
{
	float perimetr_tr = distAB + distAC + distBC;
	return perimetr_tr;
}
/**
Calculates the perimetr of tetragon.

#Overload double perimetr(double distAB, double distBC, double distCD, double distAD);

@details Perimetr: the sum of all sides.
@return the perimetr of a tetragon.
*/
double Base::perimetr(double distAB, double distBC, double distCD, double distAD)
{
	double perimetr_tetr = distAB + distBC + distCD + distAD;
	return perimetr_tetr;
}
/**
Calculates the perimetr of pentagon.

#Overload double perimetr(double distAB, double distBC, double distCD, double distDE, double distAE);

@details Perimetr: the sum of all sides.
@return the perimetr of a pentagon.
*/
double Base::perimetr(double distAB, double distBC, double distCD, double distDE, double distAE)
{
	double perimetr_pent = distAB + distBC + distCD + distDE + distAE;
	return perimetr_pent;
}
/**
Calculates the area of triangle.

@details Area: Heron formula for triangle.
@return the area of a triangle.
*/
double Base::area(double distAB, double distAC, double distBC)
{
	double half_perimetr_tr = perimetr(distAB, distAC, distBC) / 2;
	double area_tr = sqrt(half_perimetr_tr * (half_perimetr_tr - distAB) * (half_perimetr_tr - distAC) * (half_perimetr_tr - distBC));
	return area_tr;
}
/**
Calculates the area of tetragon.

#Overload double area(double distAB, double distBC, double distCD, double distAD);

@details Area: Heron formula for tetragon.
@return the area of a tetragon.
*/
double Base::area(double distAB, double distBC, double distCD, double distAD)
{
	double half_perimetr_tetr = perimetr(distAB, distBC, distCD, distAD) / 2;
	double area_tetr = sqrt((half_perimetr_tetr - distAB) * (half_perimetr_tetr - distBC) * (half_perimetr_tetr - distCD) * (half_perimetr_tetr - distAD));
	return area_tetr;
}
/**
Calculates the area of pentagon.

#Overload double area(point a, point b, point c, point d, point e);

@details Area: Gauss formula for pentagon. Use coordinates of points.
\S - area of pentagon
\(x1, y1) Coordinates of point a.
\(x2, y2) Coordinates of point b.
\(x3, y3) Coordinates of point c.
\(x4, y4) Coordinates of point d.
\(x5, y5) Coordinates of point e.
\
\Gauss formula: 2S = x1(y2-y5) + x2(y3-y1) + x3(y4-y2) + x4(y5-y3) + x5(y1-y4).
@return the area of a pentagon.
*/
double Base::area(point a, point b, point c, point d, point e)
{
	double area_pent = (a.x * (b.y - e.y) + b.x * (c.y - a.y) + c.x * (d.y - b.y) + d.x * (e.y - c.y) + e.x * (a.y - d.y)) / 2;
	if (area_pent < 0) {
		return area_pent * -1;
	}
	else {
		return area_pent;
	}
}
/**
Checks on Intersections 2 lines. Line A and line B.

@details Interection:
\\ Uses straight line equation. (kx + b) 
\(x1, y1) Coordinates of the first point of line A.
\(x2, y2) Coordinates of the second point of line A.
\(x3, y3) Coordinates of the first point of line B.
\(x4, y4) Coordinates of the second point of line B.
\k1 angular coefficient of line A.
\k2 angular coefficient of line B.
\b1 free member of line A.
\b2 free member of line B.
\(x, y) Coordinates of intersection point.
\
\\Step 1:
\if x1 >= x2 then swap the values of x1 and x2. And swap the values of y1 and y2.
\if x3 >= x4 then swap the values of x3 and x4. And swap the values of y3 and y4.
\\Step 2:
\Checks if y2 = y1 then k1 = 0. 
\Else calculetes k1 on next formula:
\k1 = ( ó2 - ó1 ) / ( x2 - x1 ). 
\Checks if y3 = y4 then k2 = 0.
\Else calculates k2 on next formula:
\k2 = ( ó4 - ó3 ) / ( x4 - x3 ). 
\\Step 3:
\if k1 = k2 then lines is parallel.
\Checking finished.
\Else continue checking:
\Calculates the free members:
\b1 = ó1 - k1 * x1.
\b2 = ó3  - k2 * x3. 
\Calculates the system of equations:
\y = k1 * x + b1.
\y = k2 * x + b2.
\
\if k1 * x + b1 = k2 * x + b2 then lines have an intesection point:
\x = ( b2 - b1 ) / ( k1 -  k2 ).
\y = k1 x + b1.
\BUT if lines have an intersection point it is not mean then segments which belongs to this lines have an intesection point too.
\Segments have an intersection point if:
\x1 <= x4 and x4 <= x2 OR x1 <= x3 and x3 <= x2.
\ 
\if condition above is not fulfilled then segments dont have an intersection point.
\Checking finished.
@return true if lines dont have an intersection point. false if lines have an intersection point.
*/
bool Base::checkOnIntersections(point lineApoint1, point lineApoint2, point lineBpoint1, point lineBpoint2)
{
	double lineAñoefficient, lineBcoefficient, lineAfreeMember, lineBfreeMember, intersectionY1, intersectionY2;
	point intersectionPoint;
		//Step 1
	if (lineApoint1.x >= lineApoint2.x) {
		swap(lineApoint1, lineApoint2);
	}
	if (lineBpoint1.x >= lineBpoint2.x) {
		swap(lineBpoint1, lineBpoint2);
	}
		//Step 2
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
		//Step 3
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
/**
Checks: Is three points on one line?

@details Three points lay on one line if:
\(x1, y1) Coordinates of point a.
\(x2, y2) Coordinates of point b.
\(x3, y3) Coordinates of point c.
\
\The result of formula (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1) = 0.
@return true if points dont lay on one line. false if points lay on one line.
*/
bool Base::pointsOnOneLine(point a, point b, point c)
{
	double result;
	result = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
		//Checks if result = 0 then return false.
		//Else return true.
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
@return the dist(rational meaning) between points.
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

