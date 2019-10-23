#pragma once
#include"list_node.h"
#include"Base.h"



template<class T>
class list_realisation
{
private:
	list_node<T> *head;
	list_node<T> *tail;
public:
	list_realisation();
	~list_realisation();

	void addEl(T *figure);
	void printList();

};

