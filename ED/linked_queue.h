#pragma once

#include <cstddef> // NULL.
#include <new> // bad_alloc.
#include <functional>
#include <iostream>

template<class T>
class LinkedQueue {

private:
	struct QueueNode
	{
		T* item;
		QueueNode* next;
	};
	QueueNode* front;
	QueueNode* back;

public:
	LinkedQueue()
	{
		front = NULL;
		back = NULL;
	}

	~LinkedQueue()
	{
		QueueNode* tempPtr;
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
		QueueNode* tempPtr = front;
		while (tempPtr != NULL) {
			len++;
			tempPtr = tempPtr->next;
		}
		return len;
	}

	bool isFull() const
	{
		QueueNode* location;
		try {
			location = new QueueNode;
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

	T peek() {
		return *front;
	}

	void enqueue(T& newItem)
	{
		if (isFull())
			throw "Queue is already full!";
		QueueNode* newNode = new QueueNode();
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
		QueueNode* tempPtr = front;
		front = front->next;
		if (front == NULL)
			back = NULL;
		T* item = tempPtr->item;
		delete tempPtr;
		return item;
	}

	void clear() const
	{
		QueueNode* tempPtr = front;
		while (tempPtr != NULL) {
			tempPtr = tempPtr->next;
			dequeue();
		}
	}

	LinkedQueue<T> copy() const
	{
		LinkedQueue<T> newQueue = LinkedQueue<T>();
		QueueNode* tempPtr = front;
		while (tempPtr != NULL) {
			newQueue.enqueue(*tempPtr->item);
			tempPtr = tempPtr->next;
		}
	}

	void forEach(std::function<void(T&)> func)
	{
		QueueNode* tempPtr = front;
		while (tempPtr != NULL) {
			func(*tempPtr->item);
			tempPtr = tempPtr->next;
		}
	}

	void forEach(std::function<void(T&,int)> func)
	{
		int count = 0;
		QueueNode* tempPtr = front;
		while (tempPtr != NULL) {
			func(*tempPtr->item, count++);
			tempPtr = tempPtr->next;
		}
	}

	template<class R>
	R reduce(std::function<R(T&, R, int)> func) 
	{
		int count = 0;
		R accumulator = NULL;
		QueueNode* tempPtr = front;
		while (tempPtr != NULL) {
			accumulator = func(*tempPtr->item, accumulator, count++);
			tempPtr = tempPtr->next;
		}
		return accumulator;
	}

	T* find(T& item) const {
		QueueNode* tempPtr = front;
		while (tempPtr != NULL) {
			if (item == (*tempPtr->item))
				return tempPtr->item;
			tempPtr = tempPtr->next;
		}
		return NULL;
	}

	T* find(std::function<bool(T&)> condition) const {
		QueueNode* tempPtr = front;
		while (tempPtr != NULL) {
			if (condition(*tempPtr->item))
				return tempPtr->item;
			tempPtr = tempPtr->next;
		}
		return NULL;
	}
};