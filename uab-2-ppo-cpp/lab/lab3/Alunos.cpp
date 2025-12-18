/*
 * Alunos.cpp
 *
 *  Created on: 18 Feb 2014
 *      Author: Elizabeth Carvalho
 *  Edited on: 28 Sep 2021
 *		Edited by: Leonel Morgado
 */

#include "Alunos.h"

namespace std {

// Construtor personalizado
Alunos::Alunos() {
	cout << "Introduza o nome do aluno:" << endl;
	cin >> nome;
	cout << "Introduza o nome do curso:" << endl;
	cin >> curso;
	cout << "Introduza o número de matrícula:" << endl;
	cin >> nMatr;
	cout << "Introduza a nota média: " << endl;
	cin >> notaM;
}

// Construtor vazio
Alunos::Alunos(int op) {

}

Alunos::~Alunos() {
	// TODO Auto-generated destructor stub
}

// Apresenta os alunos que frequentam o curso escolhido
void Alunos::apresentaAluno(string c) {
	if (!c.compare(curso)) {
		cout << "NOME: " << nome << endl;
		cout << "CURSO: " << curso << endl;
		cout << "MATRÍCULA: " << nMatr << endl;
		cout << "NOTA MÉDIA: " << notaM << endl;
	}
}

// Apresenta todos os alunos
void Alunos::apresentaAluno() {
	cout << "NOME: " << nome << endl;
	cout << "CURSO: " << curso << endl;
	cout << "MATRÍCULA: " << nMatr << endl;
	cout << "NOTA MÉDIA: " << notaM << endl;
}

} /* namespace std */
