/*
 * 21093 - Programação por Objetos
 * E-Fólio Global
 *
 * 1901774 - Rui Sousa
 */

#pragma once
#include <vector>

#include "CampanhaAtiva.h"
#include "ProdutoDeLoja.h"

// 3.
class Loja
{
public:
	// 4.
	Loja operator + (const ProdutoDeLoja& produto);
	Loja operator + (const CampanhaAtiva& campanha);
private:
	// 3.a.
	std::vector<ProdutoDeLoja> produtos;

	// 3.b.
	std::vector<CampanhaAtiva> campanhas;
};
