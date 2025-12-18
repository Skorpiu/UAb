/*
 * Alunos.h
 *
 *  Created on: 18 Feb 2014
 *      Author: Elizabeth Carvalho
 *  Edited on: 21 Sep 2021
 *		Editor: Leonel Morgado
 */

#ifndef ALUNOS_H_
#define ALUNOS_H_

#include <iostream>

namespace std {

class Alunos {
private:
	string nome;
	int nMatr;
	string curso;
	float notaM;
public:
	Alunos();
	Alunos(int);
	virtual ~Alunos();
	void apresentaAluno(string);
	void apresentaAluno();
	int getMatricula() { return nMatr; };
	float getNotaM() { return notaM; };
	string getNome() { return nome; };
	string getCurso() { return curso; };
	void setMatricula(int m) { nMatr = m; };
	void setNotaM(float n) { notaM = n; };
	void setNome(string n) { nome = n; };
	void setCurso(string c) { curso = c; };
};

} /* namespace std */
#endif /* ALUNOS_H_ */
