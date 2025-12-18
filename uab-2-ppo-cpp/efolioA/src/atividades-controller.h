#pragma once
#include <vector>
#include "atividade.h"

class atividades_controller
{
public:
	std::tuple<bool, std::string> criar(const atividade& nova_atividade);
	void ordenar(const std::string& campo);
	std::vector<atividade> atividades;

	atividades_controller();
private:
};
