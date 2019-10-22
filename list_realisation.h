#pragma once
#include"list_node.h"


template<class T>
class list_realisation
{
private:
	list_node *head;
	list_node *tail;
public:
	list_realisation();
	~list_realisation();

	void addEl(T *figure);

};

