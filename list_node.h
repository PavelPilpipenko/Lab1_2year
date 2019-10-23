#pragma once
#include"Base.h"
#include"triangle.h"
#include"tetragon.h"
#include"pentagon.h"

template <class T>
class list_node
{
public:
	list_node *next;
	list_node *prev;
	T info;

	list_node();
	~list_node();
};

