#include "pch.h"
#include<iostream>
#include "list_node.h"


using std::cout;
using std::cin;


type list_node::Set_type(type name)
{
	return _type_name = name;
}

type list_node::Get_type()
{
	return _type_name;
}

list_node::list_node()
{ 
	next = nullptr;
	prev = nullptr;
	_type_name = not_setted;
	P = S = 0;
}

list_node::~list_node()
{
}

