#pragma once
#include"list_node.h"
#include"Base.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"

class list_realisation : private insertionSort, mergeSort, quickSort
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
	void deleteEl(list_node *delEl);
	void deletelist();
	void printList();
	void searchToDelete();
	void insertionSort(int input);
	void mergeSort(int input);
	void quickSort(int input);
};

