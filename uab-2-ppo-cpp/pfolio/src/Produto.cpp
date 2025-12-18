/*
 * 21093 - Programação por Objetos
 * E-Fólio Global
 *
 * 1901774 - Rui Sousa
 */

#include "Produto.h"
#include "Helpers.h"
#include <fstream>
#include <iomanip>
#include <iostream>

// 1.b.
bool Produto::Ler(std::ifstream& stream)
{
	std::string linha;
	if (std::getline(stream, linha))
	{
		auto partes = split(linha, ",");

		this->nome = partes[0];
		this->descricao = partes[1];
		this->preco = stof(partes[2]);

		return true;
	}

	return false;
}

// 1.c.
void Produto::Escrever()
{
	std::cout << this->nome << " - " << this->descricao << ": " << std::fixed << std::setprecision(2) << this->preco << " EUR" << std::endl;
}
