#pragma once
#include "Jogador.h"

class Pontos
{
public:
	Pontos(const Jogador& jogador, int pontos);

	Jogador jogador;
	int pontos;
};

