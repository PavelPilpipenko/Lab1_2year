#pragma once
#include"list_node.h"
#include"Base.h"
#include "insertionSort.h"
#include "mergeSort.h"

class list_realisation : private insertionSort, mergeSort
{
private:
	list_node *head;
	list_node *tail;
public:
	list_realisation();
	~list_realisation();

	void addElTriangle();
	void addElTetragon();
	void addElPentagon();
	void swapEl(list_node *elToSwap1, list_node *elToSwap2);
	void deleteEl(list_node *delEl);
	void deletelist();
	void printList();
	void searchToDelete();
	void insertionSort(int input);
	void mergeSort(int input);
	list_node* Get_head();
	list_node* Get_tail();
};

