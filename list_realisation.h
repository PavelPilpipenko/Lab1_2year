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
	void swapEl(list_node *elToSwap1, list_node *elToSwap2);
	void deleteEl(list_node *delEl);
	void deletelist();
	void printList();
	void searchToDelete();
};

