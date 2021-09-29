#include <iostream>
#include <iomanip>
#include "account.h"
using namespace std;

// O construtor já está construído.
Account::Account(int no, double b) : accountNumber(no), balance(b) { }


/*
  A função print também já está implementada.
 */
void Account::print() const {
	cout << fixed << setprecision(2);
	cout << "A/C no: " << accountNumber << " Balance=R$" << balance << endl;
}


int Account::getAccountNumber() const {
	return accountNumber;
}


double Account::getBalance() const {
	return balance;
}


void Account::setBalance(double b) {
	balance = b;
}

/*
  Não esqueça que amount deve ser positivo.
 */

void Account::credit(double amount) {
	if (amount < 0.0)
		amount = 0.0;
	balance += amount;
}

/*
  Não esqueça que a nossa conta corrente não pode ficar negativa.
 */
void Account::debit(double amount) {
	if (amount <= balance)
		balance -= amount;
}


