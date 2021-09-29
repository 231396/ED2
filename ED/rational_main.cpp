#include <iostream>
#include "rational.h"
#include "mains.h"

using std::cout;
using std::endl;


int rationalMain() {
	/*
	  Observe que para economizar espaço, nós podemos declarar mais de
	  uma instância de um mesmo objeto de uma vez só.
	 */
	Rational c(2, 6), d(7, 8), x;

	/*
	  Abaixo, temos várias chamadas aos métodos para fins de
	  teste. Observe a saída desses comandos e compare com os seus
	  colegas para saber o que eles estão fazendo. Caso você não tenha
	  amigos (recomendo que tente fazer alguns, é sempre bom ter outros
	  programadores como amigos), veja um exemplo de saída no final do
	  arquivo.
	 */

	//ADD
	c.printRational();
	cout << " + ";
	d.printRational();
	x = c.addition(d);

	cout << " = ";
	x.printRational();
	cout << '\n';
	x.printRational();
	cout << " = ";
	x.printRationalAsDouble();
	cout << "\n\n";

	//SUB
	c.printRational();
	cout << " - ";
	d.printRational();
	x = c.subtraction(d);

	cout << " = ";
	x.printRational();
	cout << '\n';
	x.printRational();
	cout << " = ";
	x.printRationalAsDouble();
	cout << "\n\n";

	//MULT
	c.printRational();
	cout << " * ";
	d.printRational();
	x = c.multiplication(d);

	cout << " = ";
	x.printRational();
	cout << '\n';
	x.printRational();
	cout << " = ";
	x.printRationalAsDouble();
	cout << "\n\n";

	//DIVISION
	c.printRational();
	cout << " / ";
	d.printRational();
	x = c.division(d);

	cout << " = ";
	x.printRational();
	cout << '\n';
	x.printRational();
	cout << " = ";
	x.printRationalAsDouble();
	cout << endl;
	return 0;
}

/*
1/3 + 7/8 = 29/24
29/24 = 1.20833

1/3 - 7/8 = -13/24
-13/24 = -0.541667

1/3 x 7/8 = 7/24
7/24 = 0.291667

1/3 / 7/8 = 8/21
8/21 = 0.380952
*/
