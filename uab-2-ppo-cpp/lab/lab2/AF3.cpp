/*
 * AF3.cpp
 *
 *  Created on: 18 Feb 2014
 *      Author: Elizabeth Carvalho
 *  Edited on: 27 Sep 2021
 *		Editor: Leonel Morgado
 */

#include "Conjunto.h"

using namespace std;

int main() {
	int n;

	cout << "               **AF3**" << endl;
	cout << "Quantos alunos vai ter o conjunto? " << endl;
	cin >> n;

	Conjunto conjAlunos(n);

	cout << "//////////////////////////////////////" << endl;
	conjAlunos.ordenaAlunos();
	conjAlunos.apresentaAlunos();
	cout << "//////////////////////////////////////" << endl;
	conjAlunos.apresentaAlunos("medicina");
	cout << "//////////////////////////////////////" << endl;
	cout << "Média Global: " << conjAlunos.calculaMediaGlobal();
	cout << "//////////////////////////////////////" << endl;
	conjAlunos.apresentaMaxMin();

	return 0;
}


