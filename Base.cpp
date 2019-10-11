#include "pch.h"
#include "Base.h"
#include"iostream"

using std::cin;
using std::cout;

double Base::perimetr(double distAB, double distAC, double distBC)
{
	double perimetr_tr = distAB + distAC + distBC;
	return perimetr_tr;
}

double Base::area(double distAB, double distAC, double distBC)
{
	double half_perimetr = (distAB + distAC + distBC) / 2;
	double area_tr = sqrt(half_perimetr * (half_perimetr - distAB) * (half_perimetr - distAC) * (half_perimetr - distBC));
	return area_tr;
}

double Base::distTo(point alfa, point beta)
{
	double dist = sqrt(pow((alfa.x - beta.x), 2) + pow((alfa.y - beta.y), 2));
	return dist;
}


void Base::create_point(point &p)
{
	point temp;
	cout << "\nEnter X for point: ";
	cin >> temp.x;// нужен сеттер а не в область видимости функции
	p.x = temp.x;
	cout << "Enter Y for point: ";
	cin >> temp.y;
	p.y = temp.y;
	cout << "Point created";
}

Base::Base()
{
}

Base::~Base()
{
}



//Base::Base(double x, double y, char name) : x(x), y(y), name(name) {}