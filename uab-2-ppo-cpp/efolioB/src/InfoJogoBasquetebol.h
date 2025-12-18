#pragma once

#include "InfoJogo.h"
#include "Pontos.h"
#include "TempoJogado.h"

class InfoJogoBasquetebol : public InfoJogo {
public:
	std::string get_nome_modalidade() override;
	int get_numero_titulares() override;
	int get_numero_suplentes() override;
	std::vector<Posicao> get_posicoes() override;
	bool permite_empate() override;
	void print_detalhes() override;
	void registar_relato() override;
private:
	/// <summary> Pede ao utilizador para registar o tempo jogado por cada jogador da equipa recebida </summary>
	void registar_tempo_jogado(int equipa);

	/// <summary> Pede ao utilizador para registar a pontuação por cada jogador da equipa recebida </summary>
	void registar_pontuacao(int equipa);

	/// <summary> Pontuação por jogador da primeira equipa </summary>
	std::vector<Pontos> pontos_1;

	/// <summary> Pontuação por jogador da segunda equipa </summary>
	std::vector<Pontos> pontos_2;

	/// <summary> Tempo de jogo por jogador da primeira equipa </summary>
	std::vector<TempoJogado> tempo_jogado_1;

	/// <summary> Tempo de jogo por jogador da segunda equipa </summary>
	std::vector<TempoJogado> tempo_jogado_2;
};
