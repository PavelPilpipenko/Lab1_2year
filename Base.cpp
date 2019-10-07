#include "pch.h"
#include "Base.h"
#include"iostream"

using std::cin;
using std::cout;

double Base::distTo(point alfa, point beta)
{
	double dist = sqrt(pow((alfa.x - beta.x), 2) + pow((alfa.y - beta.y), 2));
	return dist;
}


char Base::create_point()
{
	point p;
	cout << "Enter X for point: ";
	cin >> p.x;
	cout << "\nEnter Y for point: ";
	cin >> p.y;
	cout << "\nPoint name: ";
	cin >> p.name;
	return p.name;
}

Base::Base(double x, double y, char name) : x(x), y(y), name(name) {}



Base::~Base()
{
}
