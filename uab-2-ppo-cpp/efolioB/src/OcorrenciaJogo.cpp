#include "OcorrenciaJogo.h"

OcorrenciaJogo::OcorrenciaJogo(int minutos, int segundos, std::string mensagem)
{
	if (minutos < 0) {
		minutos = 0;
	}

	if (segundos < 0) {
		segundos = 0;
	}

	// se o utilizador enviar, por exemplo, 70 segundos,
	// vai adicionar 1 minuto e alterar os segundos para 10

	minutos += segundos / 60;
	segundos = segundos % 60;


	this->minutos = minutos;
	this->segundos = segundos;

	this->mensagem = mensagem;
}

bool OcorrenciaJogo::operator==(const OcorrenciaJogo& rhs) const
{
	return rhs.minutos == this->minutos && rhs.segundos == this->segundos;
}

bool OcorrenciaJogo::operator >(const OcorrenciaJogo& rhs) const
{
	return this->minutos > rhs.minutos || (this->minutos == rhs.minutos && this->segundos > rhs.segundos);
}

bool OcorrenciaJogo::operator<(const OcorrenciaJogo& rhs) const
{
	return this->minutos < rhs.minutos || (this->minutos == rhs.minutos && this->segundos < rhs.segundos);
}

bool OcorrenciaJogo::operator>=(const OcorrenciaJogo& rhs) const
{
	return 
		(rhs.minutos == this->minutos && rhs.segundos == this->segundos) || 
		(this->minutos > rhs.minutos || (this->minutos == rhs.minutos && this->segundos > rhs.segundos));
}

bool OcorrenciaJogo::operator<=(const OcorrenciaJogo& rhs) const
{
	return
		(rhs.minutos == this->minutos && rhs.segundos == this->segundos) ||
		(this->minutos < rhs.minutos || (this->minutos == rhs.minutos && this->segundos < rhs.segundos));
}

bool OcorrenciaJogo::operator!=(const OcorrenciaJogo& rhs) const
{
	return this->minutos != rhs.minutos || this->segundos != rhs.segundos;
}
