/* Implementação da classe Time */
#include <iostream>  // A função std::cout será usada para implementar
			 // a função print.
#include "time.h"    // Para visualizar a classe Time
#include <iomanip>   // Para ter mais opções na hora de escrever o
			 // std::cout

using namespace std; // Para podermos escrever cout ao invés de
			 // std::cout.

/*
   Eu já implementei o método getHour para você ter como referência,
   implemente os demais.
 */
int Time::getHour() const {
	return hour;
}

int Time::getMinute() const {
	return minute;
}

int Time::getSecond() const {
	return second;
}

/*
  Nos métodos "set", a classe está recebendo como parâmetro uma
  variável com o mesmo nome do atributo. Esse fato faz com que o
  atributo seja "escondido". Por exemplo, no método setHour abaixo,
  quando usarmos a variável "hour", estaremos nos referindo ao
  parâmetro e não ao atributo da classe.

  Para contornar esse problema, usamos a palavra reservada
  "this". Assim:

  this->hour, this->minute e this->second se referem aos atributos.

  hour, minute e second se referem aos parâmetros dos métodos abaixo.
 */
void Time::setHour(int hour) {
	if (hour < 0)
		hour = 0;
	else if (hour > 23)
		hour = 23;
	this->hour = hour;
}

void Time::setMinute(int minute) {
	if (minute < 0)
		minute = 0;
	else if (minute > 59)
		minute = 59;
	this->minute = minute;
}

void Time::setSecond(int second) {
	if (second < 0)
		second = 0;
	else if (second > 59)
		second = 59;
	this->second = second;
}

void Time::setTime(int hour, int minute, int second) {
	setHour(hour);
	setMinute(minute);
	setSecond(second);
}

// Imprimir esta instância no formato "hh:mm:ss". Use a internet para
// entender por conta própria o que os métodos setfill e setw estão
// fazendo. Você tem a opção também de comentar código e executar o
// programa para ver o que muda.
void Time::print() const {
	cout << setfill('0');
	cout << setw(2) << hour
		<< ":" << setw(2) << minute
		<< ":" << setw(2) << second << endl;
}

// O próximo método aumenta um segundo nesta instância. Escreva esse
// método.
void Time::nextSecond() {
	second++;
	if (second >= 60) {
		second = 0;
		minute++;
		if (minute >= 60) {
			minute = 0;
			hour++;
			if (hour >= 24) {
				hour = 0;
			}
		}
	}
}


/*
  Deixei o construtor para o fim para você conhecer uma sintaxe
  alternativa para inicialização de atributos. Colocamos uma lista de
  inicialização após a declaração dos parâmetros. Para separar os
  parâmetros da lista de inicialização, usamos ":". A lista possui a
  sintaxe:

  atributo1(parâmetroA), atributo2(parâmetroB), ..., atributoN(parâmetroM).
 */

Time::Time(int h, int m, int s) {
	setTime(h, m, s);
	/*
	  O corpo do método executa após as inicializações. Neste caso, ele
	  está vazio porque as inicialiações eram tudo o que queríamos
	  fazer.
	 */
}
