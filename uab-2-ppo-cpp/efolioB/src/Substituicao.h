#pragma once
#include "Jogador.h"

class Substituicao
{
public:
	Substituicao(const Jogador& jogador_expulso, int minuto);
	Substituicao(const Jogador& jogador_substituido, const Jogador& jogador_substituto, int minuto);

	Jogador substituido;
	Jogador substituto;
	bool expulsao;
	int minuto;
};

