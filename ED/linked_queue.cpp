#pragma	once

#include <iostream>
#include <cstddef>         // Para NULL.
#include <new>             // Para bad_alloc.

#include "linked_queue.h"

template<class T>
LinkedQueue<T>::LinkedQueue()
{
	front = NULL;
	rear = NULL;
}

template<class T>
LinkedQueue<T>::~LinkedQueue()
{
	QueueNode<T>* tempPtr;
	rear = NULL;
	while (front != NULL) {
		tempPtr = front;
		front = front->next;
		delete tempPtr;
	}
}

template<class T>
bool LinkedQueue<T>::isFull() const
{
	QueueNode<T>* location;
	try {
		location = new QueueNode<T>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception) {
		return true;
	}
}

template<class T>
bool LinkedQueue<T>::isEmpty() const
{
	return (front == NULL);
}

template<class T>
void LinkedQueue<T>::enqueue(T* newItem)
{
	if (!isFull()) {
		QueueNode<T>* newNode = new QueueNode<T>;
		newNode->item = newItem;
		newNode->next = NULL;
		if (rear == NULL)
			front = newNode;
		else
			rear->next = newNode;
		rear = newNode;
	}
	else {
		throw "Queue is already full!";
	}
}

template<class T>
T* LinkedQueue<T>::dequeue()
{
	if (!isEmpty()) {
		QueueNode<T>* tempPtr = front;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		T* item = tempPtr->item;
		delete tempPtr;
		return item;
	}
	else {
		throw "Queue is empty!";
	}
}

template<class T>
void LinkedQueue<T>::forEach(void (*f)(T*))
{
	QueueNode<T>* tempPtr = front;
	while (tempPtr != NULL) {
		(*f)(tempPtr->item);
		tempPtr = tempPtr->next;
	}
}
