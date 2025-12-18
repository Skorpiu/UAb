/*
 * 21093 - Programação por Objetos
 * E-Fólio Global
 * 
 * 1901774 - Rui Sousa
 */

#include <iostream>
#include <fstream>
#include <vector>

#include "Campanha.h"
#include "Loja.h"
#include "Produto.h"

int main()
{
	// 5.
	auto loja = Loja();

	// -----------------------------------------------
	// Ler produtos
	// 2.a.

	std::cout << "----------------------------------" << std::endl;
	std::cout << "PRODUTOS: " << std::endl << std::endl;

	std::ifstream fprodutos("produtos.csv");
	if (fprodutos.is_open())
	{
		std::vector<Produto> produtos;
		bool ainda_tem_produtos;

		// Ignorar a linha de cabeçalho
		std::string cabecalho;
		std::getline(fprodutos, cabecalho);

		do
		{
			auto p = ProdutoDeLoja();
			ainda_tem_produtos = p.Ler(fprodutos);

			if (ainda_tem_produtos)
			{
				// 2.a.
				produtos.push_back(p);

				// 5.
				loja = loja + p;

				// 2.b.
				p.Escrever();
			}
		} while (ainda_tem_produtos);

		fprodutos.close();
	}

	// -----------------------------------------------
	// Ler descontos

	std::cout << std::endl << "----------------------------------" << std::endl;
	std::cout << "CAMPANHAS: " << std::endl << std::endl;

	std::ifstream fcampanhas("descontos.csv");

	if (fcampanhas.is_open())
	{
		std::vector<Campanha> campanhas;
		bool ainda_tem_campanhas;

		// Ignorar a linha de cabeçalho
		std::string cabecalho;
		std::getline(fcampanhas, cabecalho);

		do
		{
			auto c = CampanhaAtiva();
			ainda_tem_campanhas = c.Ler(fcampanhas);

			if (ainda_tem_campanhas)
			{
				// 2.a.
				campanhas.push_back(c);

				// 5.
				loja = loja + c;

				// 2.b.
				c.Escrever();
			}
		} while (ainda_tem_campanhas);

		fcampanhas.close();
	}
}

