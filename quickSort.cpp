#include "pch.h"
#include "quickSort.h"


quickSort::quickSort()
{
}


quickSort::~quickSort()
{
}

list_node * quickSort::_quickSortAreaPartition(list_node * listhead, list_node * listend, list_node ** newListhead, list_node ** newListtail)
{
	list_node *pivot = listend;
	list_node *prev = nullptr, *current = listhead, *tail = pivot;

	// During partition, both the head and end of the list might change 
	// which is updated in the newHead and newEnd variables 
	while (current != pivot)
	{
		if (current->S < pivot->S)
		{
			// First node that has a value less than the pivot - becomes 
			// the new head 
			if ((*newListhead) == nullptr)
				(*newListhead) = current;
			prev = current;
			current = current->next;
			current->prev = prev;
		}
		else // If cur node is greater than pivot 
		{
			current->next->prev = current;
			// Move cur node to next of tail, and change tail 
			if (prev)
			{
				prev->next = current->next;
			}
			list_node *tmp = current->next;
			current->next = nullptr;
			tail->next = current;
			current->prev = tail;
			tail = current;
			current = tmp;
		}
	}

	// If the pivot data is the smallest element in the current list, 
	// pivot becomes the head 
	if ((*newListhead) == nullptr)
		(*newListhead) = pivot;

	// Update newEnd to the current last node 
	(*newListtail) = tail;

	// Return the pivot node 
	return pivot;
}

list_node * quickSort::_quickSortPerimetrPartition(list_node * listhead, list_node * listend, list_node ** newListhead, list_node ** newListtail)
{
	list_node *pivot = listend;
	list_node *prev = nullptr, *current = listhead, *tail = pivot;

	// During partition, both the head and end of the list might change 
	// which is updated in the newHead and newEnd variables 
	while (current != pivot)
	{
		if (current->P < pivot->P)
		{
			// First node that has a value less than the pivot - becomes 
			// the new head 
			if ((*newListhead) == nullptr)
				(*newListhead) = current;
			prev = current;
			current = current->next;
			current->prev = prev;
		}
		else // If cur node is greater than pivot 
		{
			current->next->prev = current;
			// Move cur node to next of tail, and change tail 
			if (prev)
			{
				prev->next = current->next;
			}
			list_node *tmp = current->next;
			current->next = nullptr;
			tail->next = current;
			current->prev = tail;
			tail = current;
			current = tmp;
		}
	}

	// If the pivot data is the smallest element in the current list, 
	// pivot becomes the head 
	if ((*newListhead) == nullptr)
		(*newListhead) = pivot;

	// Update newEnd to the current last node 
	(*newListtail) = tail;

	// Return the pivot node 
	return pivot;
}

list_node * quickSort::_quickSortAreaRecurtion(list_node * listhead, list_node * listend)
{
	// base condition 
	if (!listhead || listhead == listend) {
		return listhead;
	}

	list_node *newListhead = nullptr, *newListend = nullptr;

	// Partition the list, newHead and newEnd will be updated 
	// by the partition function 
	list_node *pivot = _quickSortAreaPartition(listhead, listend, &newListhead, &newListend);

	// If pivot is the smallest element - no need to recur for 
	// the left part. 
	if (newListhead != pivot)
	{
		// Set the node before the pivot node as NULL 
		list_node *tmp = newListhead;
		while (tmp->next != pivot) {
			tmp = tmp->next;
		}
		tmp->next = nullptr;

		// Recur for the list before pivot 
		newListhead = _quickSortAreaRecurtion(newListhead, tmp);

		// Change next of last node of the left half to pivot 
		tmp = Get_tail(newListhead);
		tmp->next = pivot;
	}

	// Recur for the list after the pivot element 
	pivot->next = _quickSortAreaRecurtion(pivot->next, newListend);

	return newListhead;
}

list_node * quickSort::_quickSortPerimetrRecurtion(list_node * listhead, list_node * listend)
{
	// base condition 
	if (!listhead || listhead == listend) {
		return listhead;
	}

	list_node *newListhead = nullptr, *newListend = nullptr;

	// Partition the list, newHead and newEnd will be updated 
	// by the partition function 
	list_node *pivot = _quickSortPerimetrPartition(listhead, listend, &newListhead, &newListend);

	// If pivot is the smallest element - no need to recur for 
	// the left part. 
	if (newListhead != pivot)
	{
		// Set the node before the pivot node as NULL 
		list_node *tmp = newListhead;
		while (tmp->next != pivot) {
			tmp = tmp->next;
		}
		tmp->next = nullptr;

		// Recur for the list before pivot 
		newListhead = _quickSortPerimetrRecurtion(newListhead, tmp);

		// Change next of last node of the left half to pivot 
		tmp = Get_tail(newListhead);
		tmp->next = pivot;
	}

	// Recur for the list after the pivot element 
	pivot->next = _quickSortPerimetrRecurtion(pivot->next, newListend);

	return newListhead;
}

list_node * quickSort::Get_tail(list_node * current)
{
	while (current != nullptr && current->next != nullptr) {
		current = current->next;
	}
	return current;
}

void quickSort::quickSortArea(list_node ** listhead, list_node ** listtail)
{
	(*listhead) = _quickSortAreaRecurtion(*listhead, *listtail);
	(*listtail) = Get_tail(*listhead);
}

void quickSort::quickSortPerimetr(list_node ** listhead, list_node ** listtail)
{
	(*listhead) = _quickSortPerimetrRecurtion(*listhead, *listtail);
	(*listtail) = Get_tail(*listhead);
}
