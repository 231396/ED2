#include "heap.h" 
#include <cstddef>
#include <new>

using std::swap;

Heap::Heap(int MAX_ITEMS) {
	this->MAX_ITEMS = MAX_ITEMS;
	cadastro = new Account * [MAX_ITEMS];
	for (int i = 0; i < MAX_ITEMS; i++)
		cadastro[i] = NULL;
	length = 0;
}

Heap::Heap(int MAX_ITEMS, Account* input, int size)
{
	this->MAX_ITEMS = MAX_ITEMS;
	cadastro = new Account * [MAX_ITEMS];
	this->length = size;

	if (MAX_ITEMS > size) {
		for (int i = 0; i < size; i++)
			cadastro[i] = new Account(input[i]);

		for (int i = length / 2 - 1; i >= 0; i--)
			descida(i, length - 1);
	}
}

Heap::~Heap()
{
	for (int i = 0; i < length; i++)
		delete cadastro[i];
	delete[] cadastro;
}

Account Heap::dequeue()
{
	if (length == 0)
		return NULL;
	else {
		Account item = *cadastro[0];
		cadastro[0] = cadastro[length - 1];
		length--;
		descida(0, length - 1);
		return item;
	}
}

void Heap::enqueue(Account newItem)
{
	if (length == MAX_ITEMS)
		return;
	else {
		length++;
		cadastro[length - 1] = new Account(newItem); // Construtor de cópia
		subida(length - 1, 0);
	}
}

bool Heap::isFull() const
{
	return length == MAX_ITEMS;
}

bool Heap::isEmpty() const
{
	return length == 0;
}

void Heap::descida(int index, int bottom)
{
	auto arr = cadastro;

	int largest = index; // Initialize largest as root
	int l = 2 * index + 1; // left = 2*i + 1
	int r = 2 * index + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < bottom && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < bottom && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != index) {
		swap(arr[index], arr[largest]);

		// Recursively heapify the affected sub-tree
		descida(bottom, largest);
	}
}

void Heap::subida(int index, int root)
{
	int parent = (index - 1) / 2;
	if (index && cadastro[parent] < cadastro[index])
	{
		swap(cadastro[index], cadastro[parent]);
		subida(parent, root);
	}
}

void Heap::print() const {
	std::cout << "INI" << std::endl;
	for (int i = 0; i < length; i++) {
		Account* acc = cadastro[i];
		if (acc != NULL)
			std::cout << i << ":" << acc->getAccountNumber() << ", " << acc->getBalance() << std::endl;
	}
	std::cout << "FIM" << std::endl;
}
