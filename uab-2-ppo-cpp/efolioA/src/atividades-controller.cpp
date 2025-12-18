#include "atividades-controller.h"
#include <algorithm>

atividades_controller::atividades_controller() = default;

std::tuple<bool, std::string> atividades_controller::criar(const atividade& nova_atividade)
{
	// O URL tem de começar por http:// ou https://
	if (nova_atividade.url.rfind("http://", 0) != 0 && nova_atividade.url.rfind("https://", 0) != 0)
	{
		return { false, "O URL tem de iniciar com http:// ou https:// " };
	}

	if (nova_atividade.imersao_agencia < 0 || nova_atividade.imersao_agencia > 1)
	{
		return { false, "O valor do grau de imersao pela agencia tem de estar compreendido entre 0 e 1" };
	}

	if (nova_atividade.imersao_narrativa < 0 || nova_atividade.imersao_narrativa > 1)
	{
		return { false, "O valor do grau de imersao pela narrativa tem de estar compreendido entre 0 e 1" };
	}

	if (nova_atividade.imersao_sistema < 0 || nova_atividade.imersao_sistema > 1)
	{
		return { false, "O valor do grau de imersao pelo sistema tem de estar compreendido entre 0 e 1" };
	}

	atividades.push_back(nova_atividade);

	return { true, "Atividade inserida com sucesso" };
}

void atividades_controller::ordenar(const std::string& campo)
{
	sort(atividades.begin(), atividades.end(), [campo](const atividade& a, const atividade& b)
	{
		if (campo == "imersao_sistema")
		{
			return a.imersao_sistema > b.imersao_sistema;
		}

		if (campo == "imersao_agencia")
		{
			return a.imersao_agencia > b.imersao_agencia;
		}

		if (campo == "imersao_narrativa")
		{
			return a.imersao_narrativa > b.imersao_narrativa;
		}

		throw new std::exception("Campo de ordenacao invalido!!");
	});
}