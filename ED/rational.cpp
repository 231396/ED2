#include <iostream>
//#include <iomanip>
#include "rational.h"

using std::cout;

/*
  Observe abaixo que agora somos obrigados a dar um nome para o
  parâmetro. A função já está implementada, use como referência para
  todas as outras.
 */
Rational::Rational(int n, int d) {
	numerator = n;
	denominator = d;
	//gcd(n, d); 
}

/*
  Abaixo o método que deve multiplicar dois números racionais. O
  primeiro número racional é a instância atual da classe, o segundo
  número racional é o que veio por parâmetro. Note que a multiplicação
  não deve alterar nenhum desses objetos, mas criar um terceiro objeto
  que será devolvido ao usuário desta função.
 */

Rational Rational::multiplication(const Rational& m) {
	Rational t; // Cria um objeto racional que será retornaldo.

	t.numerator = m.numerator * numerator;
	t.denominator = m.denominator * denominator;
	return t;
}


/*
  Abaixo os outros métodos que você deve implementar. Eu já comecei a
  implementação de todos eles para você.
 */
Rational Rational::addition(const Rational& r) {
	Rational t;
	int g = lcm(r.denominator, denominator);

	int a = (g / denominator) * numerator;
	int b = (g / r.denominator) * r.numerator;

	t.denominator = g;
	t.numerator = a + b;
	return t;
}

Rational Rational::subtraction(const Rational& r) {
	Rational t;
	int g = lcm(r.denominator, denominator);

	int a = (g / denominator) * numerator;
	int b = (g / r.denominator) * r.numerator;

	t.denominator = g;
	t.numerator = a - b;
	return t;
}

Rational Rational::division(const Rational& r) {
	Rational t;
	t.numerator = numerator * r.denominator;
	t.denominator = denominator * r.numerator;
	return t;
}

/*
  Crie agora os métodos que vão imprimir o número racional na tela do
  usuário. Não esqueça da divisão por zero. Acredito que você
  precisará fazer algumas pesquisas na internet e no StackOverFlow.
 */
void Rational::printRational() {
	cout << numerator << "/" << denominator;
}

void Rational::printRationalAsDouble() {
	if (denominator == 0)
		cout << "Division by 0";
	//cout << std::fixed << std::setprecision(2);
	cout << numerator / (double)denominator;
}

/*
  Implemente agora o método privado "reduction". Mostre ao professor
  que você saber computar o máximo divisor comum (lcm) de dois números.
 */
int Rational::gcd(int a, int b) {
	int temp;
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int Rational::lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}