/*
  Vamos agora criar o comportamento da classe declarada em
  circle.h. Primeiramente, nós temos que ver a classe, então escreva o
  "include" apropriado.
 */

// ToDo: Insira o include apropriado.
#include <iostream>
#include "circle.h"

/*
  Abaixo eu já escrevi os nomes dos métodos para você
  implementar. Você irá implementar todos eles com facilidade.
*/

// Veja que aqui eu não preciso repetir os parâmetros default
Circle::Circle(double r, string c) : radius(r), color(c) { }

double Circle::getRadius() const {
	return radius;
}
 
string Circle::getColor() const {
	return color;
}
 
double Circle::getArea() const {
	return 3.14 * radius * radius;
}
 
