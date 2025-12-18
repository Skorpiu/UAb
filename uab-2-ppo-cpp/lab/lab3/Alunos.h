/*
 * Alunos.h
 *
 *  Created on: 18 Feb 2014
 *      Author: Elizabeth Carvalho
 *  Edited on: 28 Sep 2021
 *		Edited by: Leonel Morgado
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
	int getMatricula() const { return nMatr; };
	float getNotaM() { return notaM; };
	string getNome() { return nome; };
	string getCurso() { return curso; };
	void setMatricula(int m) { nMatr = m; };
	void setNotaM(float n) { notaM = n; };
	void setNome(string n) { nome = n; };
	void setCurso(string c) { curso = c; };
// Operador a ser utilizado pelo método sort no vector
	bool operator < (const Alunos& a) const {  return (nMatr < a.nMatr); };
};

} /* namespace std */
#endif /* ALUNOS_H_ */
