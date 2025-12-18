/*
 * 21093 - Programação por Objetos
 * E-Fólio Global
 *
 * 1901774 - Rui Sousa
 */

#include "Campanha.h"
#include "Helpers.h"

#include <fstream>
#include <iostream>

// 1.d.
bool Campanha::Ler(std::ifstream& stream)
{
	std::string linha;
	if (std::getline(stream, linha))
	{
		auto partes = split(linha, ",");

		this->titulo = partes[0];
		this->percentagem = stof(partes[1]);

		return true;
	}

	return false;
}

// 1.d.
void Campanha::Escrever()
{
	std::cout << this->titulo << ": " << this->percentagem * 100 << "%" << std::endl;
}
