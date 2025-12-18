/*
 * Conjunto.h
 *
 *  Created on: 18 Feb 2014
 *      Author: Elizabeth Carvalho
 *	Edited on: 27 Sep 2021
 *		Editor: Leonel Morgado
 */

#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include "Alunos.h"

namespace std {

class Conjunto {
private:
	Alunos *pAlunos;
	int n;
public:
	Conjunto();
	Conjunto(int);
	virtual ~Conjunto();
	float calculaMediaGlobal();
	void apresentaMaxMin();
	void ordenaAlunos();
	void apresentaAlunos(string);
	void apresentaAlunos();
};

} /* namespace std */
#endif /* CONJUNTO_H_ */
