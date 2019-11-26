#pragma once
#include "list_node.h"
class insertionSort
{
private:
	void areaSort(list_node** listhead, list_node* sortEl);
	void perimetrSort(list_node** listhead, list_node* sortEl);
public:
	void insertionSortArea(list_node** listhead);
	void insertionSortPerimetr(list_node** listhead);

	insertionSort();
	~insertionSort();
};