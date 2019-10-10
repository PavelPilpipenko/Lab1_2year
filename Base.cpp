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


void Base::create_point(point p)
{
	double temp_x, temp_y;
	cout << "\nEnter X for point: ";
	cin >> temp_x;// нужен сеттер а не в область видимости функции
	p.x = temp_x;
	cout << "Enter Y for point: ";
	cin >> temp_y;
	p.y = temp_y;
	cout << "Point created";
}

Base::Base()
{
}

Base::~Base()
{
}



//Base::Base(double x, double y, char name) : x(x), y(y), name(name) {}