/*
 * 21093 - Programação por Objetos
 * E-Fólio Global
 *
 * 1901774 - Rui Sousa
 */

#include "Loja.h"

// 4.
Loja Loja::operator+(const ProdutoDeLoja& produto)
{
	this->produtos.push_back(produto);

	return *this;
}

// 4.
Loja Loja::operator+(const CampanhaAtiva& campanha)
{
	this->campanhas.push_back(campanha);

	return *this;
}
