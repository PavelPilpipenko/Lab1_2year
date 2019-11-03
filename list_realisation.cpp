#include "pch.h"
#include<iostream>
#include "list_realisation.h"


using std::cout;

list_realisation::list_realisation()
{
	head = nullptr;
	tail = nullptr;
}


list_realisation::~list_realisation()
{
	list_node * current = head;
	list_node * tmp = head;
	
	while (current) {
		current = tmp;
		current = current->next;
		delete tmp;
	}
}

void list_realisation::addElTriangle()
{
	list_node *temp = new list_node();
	temp->Set_type(is_triangle);
	temp->tr_info = temp->tr_info.Set_triangle();//не возвращает значение.
	bool trOrNot = temp->tr_info.Get_existence();
	if (trOrNot) {
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}
}

void list_realisation::addElTetragon()
{
	list_node *temp = new list_node();
	temp->Set_type(is_tetragon);
	temp->tetr_info = temp->tetr_info.Set_tetragon();
	bool tetrOrNot = temp->tetr_info.Get_existence();
	if (tetrOrNot) {
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}
}

void list_realisation::addElPentagon()
{
	list_node *temp = new list_node();
	temp->Set_type(is_pentagon);
	temp->pent_info = temp->pent_info.Set_pentagon();
	bool pentOrNot = temp->pent_info.Get_existence();
	if (pentOrNot) {
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}
}

void list_realisation::swapEl(list_node * elToSwap1, list_node * elToSwap2)
{
	list_node temp;
	if ((elToSwap1 == head) && (elToSwap2 == tail)) {
		temp.next = elToSwap1->next;
		elToSwap1->next = nullptr;
		elToSwap1->prev = elToSwap2->prev;
		elToSwap1->prev->next = elToSwap1;
		elToSwap2->prev = nullptr;
		elToSwap2->next = temp.next;
		elToSwap2->next->prev = elToSwap2;
	}
	else if ((elToSwap1 == tail) && (elToSwap2 == head)) {
		temp.next = elToSwap2->next;
		elToSwap2->next = nullptr;
		elToSwap2->prev = elToSwap1->prev;
		elToSwap2->prev->next = elToSwap2;
		elToSwap1->prev = nullptr;
		elToSwap1->next = temp.next;
		elToSwap1->next->prev = elToSwap1;
	}
	else if (elToSwap1 == head) {
		temp.next = elToSwap1->next;
		elToSwap1->next = elToSwap2->next;
		elToSwap1->next->prev = elToSwap1;
		elToSwap1->prev = elToSwap2->prev;
		elToSwap1->prev->next = elToSwap1;
		elToSwap2->next = temp.next;
		elToSwap2->next->prev = elToSwap2;
		elToSwap2->prev = nullptr;
	}
	else if (elToSwap2 == head) {
		temp.next = elToSwap2->next;		
		elToSwap2->next = elToSwap1->next;
		elToSwap2->next->prev = elToSwap2;
		elToSwap2->prev = elToSwap1->prev;
		elToSwap2->prev->next = elToSwap2;
		elToSwap1->next = temp.next;
		elToSwap1->next->prev = elToSwap1;
		elToSwap1->prev = nullptr;
	}
	else if (elToSwap1 == tail) {
		temp.prev = elToSwap1->prev;
		elToSwap1->prev = elToSwap2->prev;
		elToSwap1->prev->next = elToSwap1;
		elToSwap1->next = elToSwap2->next;
		elToSwap1->next->prev = elToSwap1;
		elToSwap2->prev = temp.prev;
		elToSwap2->prev->next = elToSwap2;
		elToSwap2->next = nullptr;
	}
	else if (elToSwap2 == tail) {
		temp.prev = elToSwap2->prev;
		elToSwap2->prev = elToSwap1->prev;
		elToSwap2->prev->next = elToSwap2;
		elToSwap2->next = elToSwap1->next;
		elToSwap2->next->prev = elToSwap2;
		elToSwap1->prev = temp.prev;
		elToSwap1->prev->next = elToSwap1;
		elToSwap1->next = nullptr;
	}
	else {
		temp.next = elToSwap1->next;
		temp.prev = elToSwap1->prev;
		elToSwap1->next = elToSwap2->next;
		elToSwap1->next->prev = elToSwap1;
		elToSwap1->prev = elToSwap2->prev;
		elToSwap1->prev->next = elToSwap1;
		elToSwap2->next = temp.next;
		elToSwap2->next->prev = elToSwap2;
		elToSwap2->prev = temp.prev;
		elToSwap2->prev->next = elToSwap2;
	}
}

void list_realisation::deleteEl(list_node * delEl)
{
	if ((delEl == head) && (delEl == tail)) {
		delete delEl;
		head = nullptr;
		tail = nullptr;
		return;
	}
	else if (delEl == head) {
		delEl->next->prev = nullptr;
		head = delEl->next;
		delete delEl;
	}
	else if (delEl == tail) {
		delEl->prev->next = nullptr;
		tail = delEl->prev;
		delete delEl;
	}
	else {
		delEl->next->prev = delEl->prev;
		delEl->prev->next = delEl->next;
		delete delEl;
	}
}

void list_realisation::deletelist()
{
	list_node * current = head;
	list_node * tmp = head;

	while (current) {
		current = tmp;
		current = current->next;
		delete tmp;
	}
	head = nullptr;
	tail = nullptr;
}


void list_realisation::printList()
{
	list_node *temp = new list_node();
	temp = head;
	if (head != tail) {
		while (temp) {
			if (temp->Get_type() == is_triangle) {
				temp->tr_info.print();
			}
			else if (temp->Get_type() == is_tetragon) {
				temp->tetr_info.print();
			}
			else if (temp->Get_type() == is_pentagon) {
				temp->pent_info.print();
			}
			cout << "\n##########################";
			temp = temp->next;
		}
	}
	else if ((head == tail) && (head != nullptr)) {
		if (temp->Get_type() == is_triangle) {
			temp->tr_info.print();
		}
		else if (temp->Get_type() == is_tetragon) {
			temp->tetr_info.print();
		}
		else if (temp->Get_type() == is_pentagon) {
			temp->pent_info.print();
		}
	}
	else {
		cout << "list is empty";
	}
}

void list_realisation::searchToDelete()
{
	int number;
	list_node * current = head;
	cout << "\n\t Enter the number of figure which you want to delete: ";
	std::cin >> number;
	for (int i = 1; i < number; i++) {
		current = current->next;
	}
	if (current) {
		deleteEl(current);
		cout << "\n\t element has been deleted";
	}
	else {
		cout << "\n\t Invalid number";
	}	
}




