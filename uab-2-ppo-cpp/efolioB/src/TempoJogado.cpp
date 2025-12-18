
#include "TempoJogado.h"

TempoJogado::TempoJogado(const Jogador& jogador, const int minutos, const int segundos)
{
	this->jogador = jogador;
	this->minutos = minutos;
	this->segundos = segundos;
}
