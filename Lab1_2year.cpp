
#include "pch.h"
#include <iostream>
#include"Base.h"
#include"triangle.h"
#include"tetragon.h"
#include"pentagon.h"
#include"list_realisation.h"

int main() {
	list_realisation my_list;
	//my_list.addElTriangle();
	my_list.addElPentagon();
	my_list.printList();
	return 0;
}