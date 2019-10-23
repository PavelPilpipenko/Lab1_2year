#pragma once
#include"Base.h"
#include"triangle.h"
#include"tetragon.h"
#include"pentagon.h"

enum type {not_setted, is_triangle, is_tetragon, is_pentagon};
class list_node
{
private:
	type _type_name;
public:
	list_node *next;
	list_node *prev;
	triangle tr_info;
	tetragon tetr_info;
	pentagon pent_info;

	type Set_type(type name);
	type Get_type();

	list_node();
	~list_node();

};

