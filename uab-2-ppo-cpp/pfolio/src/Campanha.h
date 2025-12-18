/*
 * 21093 - Programação por Objetos
 * E-Fólio Global
 *
 * 1901774 - Rui Sousa
 */

#pragma once
#include <string>

// 1.d.
class Campanha
{
public:
	// 1.d.
	bool Ler(std::ifstream& stream);
	void Escrever();

private:
	// 1.d.
	std::string titulo = "";
	float percentagem = 0;

};
