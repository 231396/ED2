#include <iostream>
#include "heap.h"
#include "account.h"

using namespace std;

int main() {
	Heap heap = Heap();
	heap.print();
	int numbers[7] = { 12704, 31300, 1234, 49001, 52202, 65606, 91234 };
	int balances[7] = { 10,    100,   1000,     5,    15,    20, 25 };

	cout << "\n" << endl;

	for (int i = 0; i < 7; i++) {
		Account account = Account(numbers[i], balances[i]);
		heap.enqueue(account);
	}

	heap.print();

	cout << "\n------------------------------\n" << endl;

	/* Vamos agora obter a conta que está no topo. Essa é a conta corrente com mais dinheiro. */
	Account account = heap.dequeue();
	cout << account.getAccountNumber() << " -> " << account.getBalance() << endl;

	cout << "\n------------------------------\n" << endl;
	heap.print();

	cout << "\nFim Original" << endl;

	auto x = getchar();
	x = getchar();
}
