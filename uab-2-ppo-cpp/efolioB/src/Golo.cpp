#include "Golo.h"

Golo::Golo(const int minuto)
{
	this->jogador = Jogador('X', 0, "Autogolo");
	this->autogolo = true;
	this->minuto = minuto;
}

Golo::Golo(const Jogador& jogador, const int minuto, const bool autogolo)
{
	this->jogador = jogador;
	this->minuto = minuto;
	this->autogolo = autogolo;
}
