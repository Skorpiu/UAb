/*
 * AF4.cpp
 *
 *  Created on: 19 Feb 2014
 *      Author: Elizabeth Carvalho
 *  Edited on: 28 Sep 2021
 *		Edited by: Leonel Morgado
 */

#include "Conjunto.h"

using namespace std;

int main() {
	int n;

	cout << "               **AF4**" << endl;
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



