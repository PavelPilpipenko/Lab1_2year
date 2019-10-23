#pragma once
#include"list_node.h"
#include"Base.h"


class list_realisation
{
private:
	list_node *head;
	list_node *tail;
public:
	list_realisation();
	~list_realisation();

	void addElTriangle();
	void addElTetragon();
	void addElPentagon();
	void printList();

};

