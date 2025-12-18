/*
 * Conjunto.cpp
 *
 *  Created on: 18 Feb 2014
 *      Author: Elizabeth Carvalho
 *  Edited on: 28 Sep 2021
 *		Edited by: Leonel Morgado
 */

#include "Conjunto.h"

namespace std {

Conjunto::Conjunto() {
	// TODO Auto-generated constructor stub

}

Conjunto::Conjunto(int n) {
	this->n = n;
	for (int i = 0; i < n; ++ i) conjAlunos.push_back(Alunos());
}

Conjunto::~Conjunto() {
	// TODO Auto-generated destructor stub
}

// Apresenta as notas máxima e mínima do conjunto de alunos
void Conjunto::apresentaMaxMin() {
	float maior = 0, menor = 20;

	for (it = conjAlunos.begin(); it != conjAlunos.end(); it++) {
		if ((*it).getNotaM() < menor) menor = (*it).getNotaM();
		if ((*it).getNotaM() > maior) maior = (*it).getNotaM();
	}

	cout << "MAIOR NOTA: " << maior << endl;
	cout << "MENOR NOTA: " << menor << endl;
}

// Calcula a média global das notas do conjunto de alunos
float Conjunto::calculaMediaGlobal(){
	float media = 0;

	for (it = conjAlunos.begin(); it != conjAlunos.end(); it++) media = media + (*it).getNotaM();

	return (media/n);
}

// Ordena os alunos pelo número de matrícula
void Conjunto::ordenaAlunos () {
	sort(conjAlunos.begin(), conjAlunos.end());
}

// Apresenta os alunos do curso indicado
void Conjunto::apresentaAlunos(string c) {
	for (it = conjAlunos.begin(); it != conjAlunos.end(); it++) (*it).apresentaAluno(c);
}

// Apresenta todos os alunos
void Conjunto::apresentaAlunos() {
	for (it = conjAlunos.begin(); it != conjAlunos.end(); it++) (*it).apresentaAluno();
}
} /* namespace std */
