#include "pch.h"
#include "insertionSort.h"


void insertionSort::areaSort(list_node ** listhead, list_node * sortEl)
{
	list_node* current;
	if (*listhead == nullptr)
	{
		sortEl->next = *listhead;
		*listhead = sortEl;
	}
	else if ((*listhead)->S >= sortEl->S)
	{
		sortEl->next = *listhead;
		(*listhead)->prev = sortEl;
		*listhead = sortEl;
	}
	else
	{
		/* Locate the node before the point of insertion */
		current = *listhead;
		double current_next_data;
		double sortEl_data;
		if (current->next != nullptr) {
			current_next_data = current->next->S;
			sortEl_data = sortEl->S;
		}
		while (current->next != nullptr && current_next_data < sortEl_data)
		{
			// changing pointers 
			list_node * temp = current;
			current = current->next;
			current->prev = temp;
			// change data that we will compare next
			if (current->next != nullptr) {
				current_next_data = current->next->S;
				sortEl_data = sortEl->S;
			}
		}
		sortEl->next = current->next;
		if (sortEl->next != nullptr) {
			sortEl->next->prev = sortEl;
		}
		current->next = sortEl;
		sortEl->prev = current;
	}
}

void insertionSort::perimetrSort(list_node ** listhead, list_node * sortEl)
{
	list_node* current;
	if (*listhead == nullptr)
	{
		sortEl->next = *listhead;
		*listhead = sortEl;
	}
	else if ((*listhead)->P >= sortEl->P)
	{
		sortEl->next = *listhead;
		(*listhead)->prev = sortEl;
		*listhead = sortEl;
	}
	else
	{
		/* Locate the node before the point of insertion */
		current = *listhead;
		double current_next_data;
		double sortEl_data;
		if (current->next != nullptr) {
			current_next_data = current->next->P;
			sortEl_data = sortEl->P;
		}
		while (current->next != nullptr && current_next_data < sortEl_data)
		{
			// changing pointers 
			list_node * temp = current;
			current = current->next;
			current->prev = temp;
			// change data that we will compare next
			if (current->next != nullptr) {
				current_next_data = current->next->P;
				sortEl_data = sortEl->P;
			}
		}
		sortEl->next = current->next;
		if (sortEl->next != nullptr) {
			sortEl->next->prev = sortEl;
		}
		current->next = sortEl;
		sortEl->prev = current;
	}
}

void insertionSort::insertionSortArea(list_node ** listhead)
{
	// Initialize sorted linked list 
	list_node *sorted = nullptr;

	// Traverse the given linked list and insert every 
	// node to sorted 
	list_node *current = *listhead;
	while (current != nullptr)
	{
		// Store next for next iteration 
		list_node *next = current->next;

		// insert current in sorted linked list 
		areaSort(&sorted, current);

		// Update current 
		current = next;
	}

	// Update listhead to point to sorted linked list 
	*listhead = sorted;
}

void insertionSort::insertionSortPerimetr(list_node ** listhead)
{
	// Initialize sorted linked list 
	list_node *sorted = nullptr;

	// Traverse the given linked list and insert every 
	// node to sorted 
	list_node *current = *listhead;
	while (current != nullptr)
	{
		// Store next for next iteration 
		list_node *next = current->next;

		// insert current in sorted linked list 
		perimetrSort(&sorted, current);

		// Update current 
		current = next;
	}

	// Update listhead to point to sorted linked list 
	*listhead = sorted;
}

insertionSort::insertionSort()
{
}


insertionSort::~insertionSort()
{
}
