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
	list_node * tmp;
	
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

void list_realisation::addElTetragon()
{
	list_node *temp = new list_node();
	temp->Set_type(is_tetragon);
	temp->tetr_info = temp->tetr_info.Set_tetragon();

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

void list_realisation::addElPentagon()
{
	list_node *temp = new list_node();
	temp->Set_type(is_pentagon);
	temp->pent_info = temp->pent_info.Set_pentagon();

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
	list_node * tmp;

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

list_node * list_realisation::Get_head()
{
	return head;
}


