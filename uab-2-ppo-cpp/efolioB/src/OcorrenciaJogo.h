#pragma once
#include <string>

class OcorrenciaJogo
{
public:
	OcorrenciaJogo(int minutos, int segundos, std::string mensagem);

	bool operator ==(const OcorrenciaJogo& rhs) const;
	bool operator >(const OcorrenciaJogo& rhs) const;
	bool operator <(const OcorrenciaJogo& rhs) const;
	bool operator >=(const OcorrenciaJogo& rhs) const;
	bool operator <=(const OcorrenciaJogo& rhs) const;
	bool operator !=(const OcorrenciaJogo& rhs) const;
private:
	int minutos;
	int segundos;

	std::string mensagem;
};

