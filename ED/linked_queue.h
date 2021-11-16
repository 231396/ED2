#pragma once

#include <cstddef> // NULL.
#include <new> // bad_alloc.
#include <functional>

template<class T>
struct QueueNode
{
	T* item;
	QueueNode* next;
};

template<class T>
class LinkedQueue {

private:
	QueueNode<T>* front;
	QueueNode<T>* back;

public:
	LinkedQueue()
	{
		front = NULL;
		back = NULL;
	}

	~LinkedQueue()
	{
		QueueNode<T>* tempPtr;
		back = NULL;
		while (front != NULL) {
			tempPtr = front;
			front = front->next;
			delete tempPtr;
		}
	}

	int count() const
	{
		int len = 0;
		QueueNode<T>* tempPtr = front;
		while (tempPtr != NULL) {
			len++;
			tempPtr = tempPtr->next;
		}
		return len;
	}

	bool isFull() const
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

	bool isEmpty() const
	{
		return (front == NULL);
	}

	void enqueue(T& newItem)
	{
		if (isFull())
			throw "Queue is already full!";
		QueueNode<T>* newNode = new QueueNode<T>;
		newNode->item = &newItem;
		newNode->next = NULL;
		if (back == NULL)
			front = newNode;
		else
			back->next = newNode;
		back = newNode;
	}

	T* dequeue()
	{
		if (isEmpty())
			return NULL;
		QueueNode<T>* tempPtr = front;
		front = front->next;
		if (front == NULL)
			back = NULL;
		T* item = tempPtr->item;
		delete tempPtr;
		return item;
	}

	void clear() const
	{
		QueueNode<T>* tempPtr = front;
		while (tempPtr != NULL) {
			tempPtr = tempPtr->next;
			dequeue();
		}
	}

	void forEach(std::function<void(T&)> func)
	{
		QueueNode<T>* tempPtr = front;
		while (tempPtr != NULL) {
			func(*tempPtr->item);
			tempPtr = tempPtr->next;
		}
	}

	bool exists(T& item) const
	{
		QueueNode<T>* tempPtr = front;
		while (tempPtr != NULL) {
			if (item == tempPtr->item)
				return true;
			else
				tempPtr = tempPtr->next;
		}
		return false;
	}

	T* find(std::function<bool(T&)> func) const
	{
		QueueNode<T>* tempPtr = front;
		while (tempPtr != NULL) {
			if (!func(*tempPtr->item))
				tempPtr = tempPtr->next;
			else
				return tempPtr->item;
		}
		return NULL;
	}

};