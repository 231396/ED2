#include "aluno.h"

using std::string;

Aluno::Aluno() {
	this->ra = -1;
	this->nome = "";
};
Aluno::Aluno(int ra) {
	this->ra = ra;
	this->nome = "";
};
Aluno::Aluno(int ra, string nome) {
	this->ra = ra;
	this->nome = nome;
}
string Aluno::getNome() const {
	return nome;
}
int Aluno::getRa() const {
	return ra;
}
