#pragma once
#include "Jogador.h"

class TempoJogado
{
public:
	TempoJogado(const Jogador& jogador, int minutos, int segundos = 0);

	Jogador jogador;
	int minutos;
	int segundos;
};

