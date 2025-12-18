/*
 * 21093 - Programação por Objetos
 * E-Fólio Global
 *
 * 1901774 - Rui Sousa
 */

#pragma once
#include <fstream>
#include <string>

// 1.a.
class Produto
{
public:
	// 1.a.
	bool Ler(std::ifstream& stream);
	void Escrever();

private:
	// 1.a.
	std::string nome = "";
	std::string descricao = "";
	float preco = 0;
};
