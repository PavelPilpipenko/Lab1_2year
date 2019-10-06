#pragma once

class point
{
public:
	point(double x,double y);
	~point();

	double distance(point first, point second);

	point operator + (point pointPlus);//перегрузка +
private:
	double x;
	double y;
};

