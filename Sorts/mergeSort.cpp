#include "pch.h"
#include "mergeSort.h"


list_node * mergeSort::areaSort(list_node * a, list_node * b)
{
	list_node* result = nullptr;
	/* Base cases */
	if (a == nullptr) {
		return (b);
	}
	else if (b == nullptr) {
		return (a);
	}
	if (a->S <= b->S) {
		result = a;
		result->next = areaSort(a->next, b);
		result->next->prev = result;
	}
	else {
		result = b;
		result->next = areaSort(a, b->next);
		result->next->prev = result;
	}
	return (result);
	
}

list_node * mergeSort::perimetrSort(list_node * a, list_node * b)
{
	list_node* result = nullptr;
	/* Base cases */
	if (a == nullptr) {
		return (b);
	}
	else if (b == nullptr) {
		return (a);
	}
	if (a->P <= b->P) {
		result = a;
		result->next = perimetrSort(a->next, b);
		result->next->prev = result;
	}
	else {
		result = b;
		result->next = perimetrSort(a, b->next);
		result->next->prev = result;
	}
	return (result);
}

void mergeSort::FrontBackSplit(list_node * source, list_node ** frontRef, list_node ** backRef)
{
	list_node* fast;
	list_node* slow;
	slow = source;
	fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != nullptr) {
		fast = fast->next;
		if (fast != nullptr) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = nullptr;
}

void mergeSort::MergeSortArea(list_node ** listhead)
{
	list_node* cur_head = *listhead;
	list_node* a;
	list_node* b;

	/* Base case -- length 0 or 1 */
	if ((cur_head == nullptr) || (cur_head->next == nullptr)) {
		return;
	}
	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(cur_head, &a, &b);

	/* Recursively sort the sublists */
	MergeSortArea(&a);
	MergeSortArea(&b);

	/* answer = merge the two sorted lists together */
	*listhead = areaSort(a, b);
}

void mergeSort::MergeSortPerimetr(list_node ** listhead)
{
	list_node* cur_head = *listhead;
	list_node* a;
	list_node* b;

	/* Base case -- length 0 or 1 */
	if ((cur_head == nullptr) || (cur_head->next == nullptr)) {
		return;
	}
	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(cur_head, &a, &b);

	/* Recursively sort the sublists */
	MergeSortPerimetr(&a);
	MergeSortPerimetr(&b);

	/* answer = merge the two sorted lists together */
	*listhead = perimetrSort(a, b);
}

mergeSort::mergeSort()
{
}


mergeSort::~mergeSort()
{
}
