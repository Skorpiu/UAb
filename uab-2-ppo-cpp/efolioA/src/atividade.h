#pragma once
#include <iostream>
#include <utility>

class atividade {
public: 
	std::string titulo;
	std::string descricao;
	std::string url;
	float imersao_sistema;
	float imersao_narrativa;
	float imersao_agencia;

	atividade() = default;
	atividade(std::string titulo, std::string descricao, std::string url, float i_sistema, float i_narrativa, float i_agencia)
	{
		this->titulo = std::move(titulo);
		this->descricao = std::move(descricao);
		this->url = std::move(url);
		this->imersao_sistema = i_sistema;
		this->imersao_agencia = i_agencia;
		this->imersao_narrativa = i_narrativa;
	}

	atividade operator +(const atividade& outra) const
	{
		atividade resultado;

		resultado.imersao_sistema = outra.imersao_sistema > this->imersao_sistema
			? outra.imersao_sistema
			: this->imersao_sistema;
		resultado.imersao_narrativa = outra.imersao_narrativa > this->imersao_narrativa
			? outra.imersao_narrativa
			: this->imersao_narrativa;
		resultado.imersao_agencia = outra.imersao_agencia > this->imersao_agencia
			? outra.imersao_agencia
			: this->imersao_agencia;

		return resultado;
	}
};