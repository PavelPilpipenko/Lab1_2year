#pragma once


struct point
{
	char name;
	double x;
	double y;

	point(double x,double y, char name);
	~point();
	char get_name() {
		return name;
	}
	point operator + (point pointPlus);//перегрузка +
};

