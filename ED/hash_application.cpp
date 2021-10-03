#include <iostream>
#include "hash.h" 

using namespace std;

int main() {
	Hash myHash = Hash(11);
	int ras[] = { 41, 48, 19, 12, 30 };
	string nomes[] = {
		"Pedro", "Raul", "Paulo",
		"Carlos", "Lucas", "Maria",
		"Samanta" 
	};

	for (int i = 0; i < 5; i++) {
		Aluno aluno = Aluno(ras[i], nomes[i]);
		myHash.insertItem(aluno);
	}
	myHash.print();

	cout << "\n------------------------------\n" << endl;

	Aluno aluno(19);
	bool found = myHash.retrieveItem(aluno);
	cout << aluno.getNome() << " -> " << found << endl;

	cout << "\n------------------------------\n" << endl;

	myHash.deleteItem(aluno);
	myHash.print();
	cout << "Fim" << endl;

	auto x = getchar();
	x = getchar();
}
