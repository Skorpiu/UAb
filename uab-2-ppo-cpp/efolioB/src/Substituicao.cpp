#include "Substituicao.h"

Substituicao::Substituicao(const Jogador& jogador_expulso, const int minuto)
{
	this->substituido = jogador_expulso;
	this->minuto = minuto;
	this->expulsao = true;
}

Substituicao::Substituicao(const Jogador& jogador_substituido, const Jogador& jogador_substituto, const int minuto)
{
	this->substituido = jogador_substituido;
	this->substituto = jogador_substituto;
	this->minuto = minuto;
	this->expulsao = true;
}
