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

double Base::perimetr(double distAB, double distBC, double distCD, double distAD)
{
	double perimetr_tetr = distAB + distBC + distCD + distAD;
	return perimetr_tetr;
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