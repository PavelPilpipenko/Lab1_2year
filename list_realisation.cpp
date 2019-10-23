#include "pch.h"
#include "list_realisation.h"
#include<iostream>

using std::cout;

template<class T> list_realisation<T>::list_realisation()
{
	head = nullptr;
	tail = nullptr;
}


template<class T> list_realisation<T>::~list_realisation()
{
}

template<class T>
void list_realisation<T>::addEl(T * figure)
{
	list_node<T> *temp = new list_node<T>();
	temp->info = figure;//overload
	temp->info();

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

template<class T>
void list_realisation<T>::printList()
{
	list_node<T> *temp = new list_node<T>;
	temp = head;
	if (head != tail) {
		while (temp) {
			temp->info.print();
			cout << "##########################";
			temp = temp->next;
		}
	}
	else if ((head == tail) && (head != nullptr)) {
		temp->info.print();
	}
	else {
		cout << "list is empty";
	}
}
