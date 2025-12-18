/*
 * Conjunto.cpp
 *
 *  Created on: 18 Feb 2014
 *      Author: Elizabeth Carvalho
 *  Edited on: 21 Sep 2021
 *		Editor: Leonel Morgado
 */

#include "Conjunto.h"

namespace std {

Conjunto::Conjunto() {
	// TODO Auto-generated constructor stub

}

Conjunto::Conjunto(int n) {
	this->n = n;
	pAlunos = new Alunos[n]; // inicializa o ponteiro
}

Conjunto::~Conjunto() {
	// TODO Auto-generated destructor stub
}

// Apresenta as notas máxima e mínima do conjunto de alunos
void Conjunto::apresentaMaxMin() {
	float maior = 0, menor = 20;

	for (int i = 0; i < n; ++i) {
		if (pAlunos[i].getNotaM() < menor) menor = pAlunos[i].getNotaM();
		if (pAlunos[i].getNotaM() > maior) maior = pAlunos[i].getNotaM();
	}

	cout << "MAIOR NOTA: " << maior << endl;
	cout << "MENOR NOTA: " << menor << endl;
}

// Calcula a média global das notas do conjunto de alunos
float Conjunto::calculaMediaGlobal(){
	float media = 0;

	for (int i = 0; i < n; ++i)	media = media + pAlunos[i].getNotaM();

	return (media/n);
}

// Ordena os alunos pelo número de matrícula segundo o algoritmo Bubble Sort
void Conjunto::ordenaAlunos () {
	int i, j;
	Alunos swap(0); // Chama o construtor vazio

	for (i = 0 ; i < ( n - 1 ); i++)
	  {
	    for (j = 0 ; j < n - i - 1; j++)
	    {
	      if ((pAlunos+j)->getMatricula() > (pAlunos+j+1)->getMatricula())
	      {
		    swap = *(pAlunos+j);
	        *(pAlunos+j) = *(pAlunos+j+1);
	        *(pAlunos+j+1) = swap;
	      }
	    }
	  }
}

// Apresenta os alunos do curso indicado
void Conjunto::apresentaAlunos(string c) {

	for (int i = 0; i < n; ++i) pAlunos[i].apresentaAluno(c);
}

// Apresenta todos os alunos
void Conjunto::apresentaAlunos() {

	for (int i = 0; i < n; ++i) pAlunos[i].apresentaAluno();
}
} /* namespace std */
