#pragma once
#include "Jogador.h"

class Golo
{
public:
	Golo(int minuto);
	Golo(const Jogador& jogador, int minuto, bool autogolo = false);

	Jogador jogador;
	int minuto;
	bool autogolo;
};

