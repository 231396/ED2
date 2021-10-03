#include "hash.h" 
#include <iostream>
using namespace std;

Hash::Hash(int max) {
	length = 0;
	max_items = max;
	structure = new Aluno[max_items];
}

Hash::~Hash() {
	delete[] structure;
}

bool Hash::isFull() const {
	return (length == max_items);
}

int Hash::getLength() const {
	return length;
}

int Hash::getHash(Aluno aluno) {
	return aluno.getRa() % max_items;
}

int Hash::getHash2(Aluno aluno) {
	int seven = max_items - 4;
	return seven - aluno.getRa() % seven;
}

int Hash::searchAlunoIndex(Aluno aluno) {
	int startIndex = getHash(aluno);
	int subIndex = getHash2(aluno);

	int index = startIndex;

	int item = structure[index].getRa();
	if (item < 0 || item == aluno.getRa())
		return index;

	int i = 1;
	do {
		item = structure[index].getRa();
		if (item < 0 || item == aluno.getRa())
			break;
		else
			index = (startIndex + i++ * subIndex) % max_items;
	} while (startIndex != index);

	return index;
}


bool Hash::retrieveItem(Aluno& aluno) {
	int index = searchAlunoIndex(aluno);
	if (structure[index].getRa() == aluno.getRa()) {
		aluno = structure[index];
		return true;
	}
	return false;
}

void Hash::deleteItem(Aluno aluno) {
	int index = searchAlunoIndex(aluno);
	if (structure[index].getRa() == aluno.getRa()) {
		structure[index] = Aluno(-2);
		length--;
	}
}

void Hash::insertItem(Aluno aluno) {
	int index = searchAlunoIndex(aluno);
	if (structure[index].getRa() < 0) {
		structure[index] = aluno;
		length++;
	}
}

void Hash::print() {
	for (int i = 0; i < max_items; i++) {
		cout << i << ":" << structure[i].getRa() << ", " << structure[i].getNome() << endl;
	}
}

