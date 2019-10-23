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
	temp->tetr_info.Set_tetragon();

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
	temp->pent_info.Set_pentagon();

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
