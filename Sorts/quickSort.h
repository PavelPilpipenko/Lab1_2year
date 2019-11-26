#pragma once
#include"list_node.h"
class quickSort
{
private:
	list_node * _quickSortAreaPartition(list_node* listhead, list_node* listend, list_node** newListhead, list_node** newListtail);
	list_node * _quickSortPerimetrPartition(list_node* listhead, list_node* listend, list_node** newListhead, list_node** newListtail);
	list_node * _quickSortAreaRecurtion(list_node* listhead, list_node* listend);
	list_node * _quickSortPerimetrRecurtion(list_node* listhead, list_node* listend);
	list_node * Get_tail(list_node* current);
public:
	void quickSortArea(list_node **listhead, list_node **listtail);
	void quickSortPerimetr(list_node **listhead, list_node **listtail);

	quickSort();
	~quickSort();
};

