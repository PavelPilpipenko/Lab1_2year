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
	#Overload double perimetr(double distAB, double distBC, double distCD, double distAD);

	@return the perimetr of a tetragon. 
	*/
	double perimetr(double distAB, double distBC, double distCD, double distAD);
	/**
	#Overload double perimetr(double distAB, double distBC, double distCD, double distDE, double distAE);

	@return the perimetr of a pentagon.
	*/
	double perimetr(double distAB, double distBC, double distCD, double distDE, double distAE);
	/**
	Returns the area of triangle.

	@param dist from point A to point B.
	@param dist from point A to point C.
	@param dist from point B to point C.
	@return the area of a triangle. Heron formula.
	*/
	double area(double distAB, double distAC, double distBC);
	/**
	#Overload double area(double distAB, double distBC, double distCD, double distAD);

	@return the area of a tetragon. Heron formula.
	*/
	double area(double distAB, double distBC, double distCD, double distAD);
	/**
	#Overload double area(double distAB, double distBC, double distCD, double distDE, double distAE, double distD);

	@return the area of a pentagon. distD - main diagonal(dist from point A to point C) devides pentagon into triangle and tetragon. Area of pentagon = area of triangle + area of tetragon.
	*/
	double area(double distAB, double distBC, double distCD, double distDE, double distAE, double distD);
	/**
	Cheks the triagngle existence. Returns true or false.

	@param dist from point A to point B.
	@param dist from point A to point C.
	@param dist from point B to point C.
	@return the triangle or not. Every side of triangle must be smaller than sum of other sides.
	*/
	bool FigureOrNot(double distAB, double distAC, double distBC);
	/**
	#Overload bool FigureOrNot(double distAB, double distBC, double distCD, double distAD);

	@return the tetragon or not. Every side of tetragon must be bigger than sum of other sides.
	*/
	bool FigureOrNot(double distAB, double distBC, double distCD, double distAD);
	/**
	#Overload bool FigureOrNot(double distAB, double distBC, double distCD, double distDE, double distAE, double distD);

	@return the pentagon or not. distD - main diagonal(dist from point A to point C). Cheks the existense of triangle ABC and tetragon ACDE. if triangle and tetragon exists - pentagon exists.
	*/
	bool FigureOrNot(double distAB, double distBC, double distCD, double distDE, double distAE, double distD);
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
	virtual void print() = 0;
	virtual bool Get_existence() = 0;
	Base();
	~Base();
};
