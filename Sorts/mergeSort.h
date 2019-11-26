#pragma once
#include "list_node.h"
class mergeSort
{
private:
	list_node * areaSort(list_node *a, list_node *b);
	list_node * perimetrSort(list_node *a, list_node *b);
	void FrontBackSplit(list_node* source, list_node** frontRef, list_node** backRef);
public:
	void MergeSortArea(list_node **listhead);
	void MergeSortPerimetr(list_node **listhead);



	mergeSort();
	~mergeSort();
};

