#pragma once
#include"cmath"
class Base
{
protected:
	class point {
	public:
		double x;//coordinate x.
		double y;//coordinate y.
		/**
		Overloaded assignment operator
		
		@param op2 Point which we want to assign to this point.
		@details Assign the coordinates of op2 to this point.
		@return *this Modified point.
		*/
		point operator = (point op2) {
			x = op2.x;
			y = op2.y;
			return *this;	
		}
	};
	/**
	Returns the perimetr of triangle. 
	
	@param distAB Dist from point A to point B.
	@param distAC Dist from point A to point C.
	@param distBC Dist from point B to point C.
	@return the perimetr of a triangle.
	*/
	double perimetr(double distAB, double distAC, double distBC);
	/**
	Returns the perimetr of tetragon.

	#Overload double perimetr(double distAB, double distBC, double distCD, double distAD);

	@param distAB.
	@param distBC.
	@param distCD Dist from point C to point D.
	@param distAD Dist from point A to point D.
	@return the perimetr of a tetragon. 
	*/
	double perimetr(double distAB, double distBC, double distCD, double distAD);
	/**
	Returns the perimetr of pentagon.

	#Overload double perimetr(double distAB, double distBC, double distCD, double distDE, double distAE);

	@param distAB.
	@param distBC.
	@param distCD.
	@param distDE Dist from point D to point E.
	@param distAE Dist from point A to point E.
	@return the perimetr of a pentagon.
	*/
	double perimetr(double distAB, double distBC, double distCD, double distDE, double distAE);
	/**
	Returns the area of triangle. Heron formula.

	@param distAB Dist from point A to point B.
	@param distAC Dist from point A to point C.
	@param distBC Dist from point B to point C.
	@return the area of a triangle.
	*/
	double area(double distAB, double distAC, double distBC);
	/**
	Returns the area of tetragon. Heron formula.

	#Overload double area(double distAB, double distBC, double distCD, double distAD);

	@param distAB.
	@param distBC.
	@param distCD Dist from point C to point D.
	@param distAD Dist from point A to point D.
	@return the area of a tetragon. 
	*/
	double area(double distAB, double distBC, double distCD, double distAD);
	/**
	Returns the area of pentagon. Gauss Formula.

	#Overload double area(point a, point b, point c, point d, point e);

	@param a Point A of pentagon.
	@param b Point B of pentagon.
	@param c Point C of pentagon.
	@param d Point D of pentagon.
	@param e Point E of pentagon.
	@return the area of a pentagon.
	*/
	double area(point a, point b, point c, point d, point e);
	/**
	Checks on Intersections 2 lines. Line A and line B.

	@param lineApoint1 The first point of line A.
	@param lineApoint2 The second point of line A.
	@param lineBpoint1 The first point of line B.
	@param lineBpoint2 The second point of line B.
	@return true if lines dont have an intersection point. false if lines have an intersection point.
	*/
	bool checkOnIntersections(point lineApoint1, point lineApoint2, point lineBpoint1, point lineBpoint2);
	/**
	Checks: Is three points on one line?
	
	@param a First point.
	@param b Second point.
	@param c Third point.
	@return true if points dont lay on one line. false if points lay on one line.
	*/
	bool pointsOnOneLine(point a, point b, point c);
	/**
	Return the dist from point alfa to point beta.

	@param point alfa(contains coordinate x and coordinate y)
	@param point beta(contains coordinate x and coordinate y)
	@return the dist(rational meaning) between points.
	*/
	double distTo(point alfa, point beta);
	/**
	User creates the point manually
	
	@param point which user want to create.
	*/
	void create_point(point &p);
public:
	/**
	Uses in classes: triangle, tetragon, pentagon.

	#Virtual function.
	*/
	virtual void print() = 0;
	/**
	Uses in classes: triangle, tetragon, pentagon.

	#Virtual function.
	*/
	virtual bool Get_existence() = 0;
	virtual double Get_area() = 0;
	virtual double Get_perimetr() = 0;
	Base();
	~Base();
};
