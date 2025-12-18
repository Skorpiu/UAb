/*
 * Conjunto.h
 *
 *  Created on: 18 Feb 2014
 *      Author: Elizabeth Carvalho
 *  Edited on: 28 Sep 2021
 *		Edited by: Leonel Morgado
 */

#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include "Alunos.h"
#include <list>
#include <vector>
#include <algorithm>

namespace std {

class Conjunto {
private:
	vector<Alunos> conjAlunos;
	vector<Alunos>::iterator it;
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
