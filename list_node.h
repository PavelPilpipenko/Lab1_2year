#pragma once

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

