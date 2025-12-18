#pragma once

#include "Golo.h"
#include "InfoJogo.h"
#include "Substituicao.h"

class InfoJogoFutebol : public InfoJogo {
public:
	std::string get_nome_modalidade() override;
	int get_numero_titulares() override;
	int get_numero_suplentes() override;
	std::vector<Posicao> get_posicoes() override;
	bool permite_empate() override;
	void print_detalhes() override;
	void registar_relato() override;
private:
	/// <summary> Pede ao utilizador para registar as substituições/expulsões da equipa recebida </summary>
	void registar_substituicoes(int equipa);

	/// <summary> Pede ao utilizador para registar os golos marcados da equipa recebida</summary>
	void registar_golos(int equipa);

	/// <summary> Listagem de substituições/expulsões efetuadas pela primeira equipa </summary>
	std::vector<Substituicao> substituicoes1;

	/// <summary> Listagem de substituições/expulsões efetuadas pela segunda equipa </summary>
	std::vector<Substituicao> substituicoes2;

	/// <summary> Listagem de golos marcados e respetivo jogador, da primeira equipa </summary>
	std::vector<Golo> golos1;

	/// <summary> Listagem de golos marcados e respetivo jogador, da segunda equipa </summary>
	std::vector<Golo> golos2;
};
