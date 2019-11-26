#pragma once
#include"Base.h"
#include"cmath"

enum pentType {not_setted_pentagon, regular};
class pentagon : public Base
{
private:
	point _a, _b, _c, _d, _e;//points of pentagon.
	double _ab = 0, _bc = 0, _cd = 0, _de = 0, _ae = 0, _S = 0, _P = 0;//sides, area, perimetr of pentagon.
	bool _PentOrNot;//pentagon existance.
	pentType _pentType;//type of pentagon.
	/**
	Checks pentagon on type.
	
	@param distAB Dist from point A to point B.
	@param distBC Dist from point B to point C.
	@param distCD Dist from point C to point D.
	@param distDE Dist from poibt D to point E.
	@param distAE Dist from point A to point E.
	@param type Type of pentagon.
	*/
	void check(double distAB, double distBC, double distCD, double distDE, double distAE, pentType &type);
public:
	/**
	Overloaded assignment operator.
	
	@param pent pentagon which we wand to assign to this pentagon.
	@return *this Modified pentagon.
	*/
	pentagon operator = (pentagon pent);
	/**
	Creates the pentagon after input the coordinates.
	
	@return *this Created pentagon.
	*/
	pentagon Set_pentagon();
	/**
	Returns the existence of pentagon.
	
	@return true if pentagon exists. false if pentagon isnt exists.
	*/
	bool Get_existence() override;
	/**
	Prints info of pentagon.
	\area, perimetr and type.
	*/
	void print() override;
	double Get_area() override;
	double Get_perimetr() override;
	pentagon();
	~pentagon();
};

