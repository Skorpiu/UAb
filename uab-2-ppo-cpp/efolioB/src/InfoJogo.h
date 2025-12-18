#pragma once
#include <vector>

#include "Jogador.h"
#include "Posicao.h"
#include "OcorrenciaJogo.h"
#include "Result.h"

class InfoJogo {
public:
	// Funções pure virtual, é obrigatório os herdeiros implementarem

	/// <summary>
	/// Adquire o nome da modalidade/desporto (neste caso, futebol ou basquetebol)
	/// </summary>
	virtual std::string get_nome_modalidade() = 0;

	/// <summary>
	/// Devolve o número de jogadores titulares na modalidade
	/// </summary>
	virtual int get_numero_titulares() = 0;

	/// <summary>
	/// Devolve o número de suplentes na modalidade
	/// </summary>
	virtual int get_numero_suplentes() = 0;

	/// <summary>
	/// Devolve uma lista das possíveis posições dos jogadores na modalidade
	/// </summary>
	virtual std::vector<Posicao> get_posicoes() = 0;

	/// <summary>
	/// Indica se a modalidade permite ou não que um jogo acabe em empate
	/// </summary>
	virtual bool permite_empate() = 0;

	/// <summary>
	/// Mostra no ecrã os detalhes do jogo (jogadores titulares/suplentes, pontos/golos, tempo jogado/substituições)
	/// </summary>
	virtual void print_detalhes() = 0;

	/// <summary>
	/// Pede ao utilizador para registar os detalhes do jogo (pontos/golos marcados, tempo jogado/substituições)
	/// </summary>
	virtual void registar_relato() = 0;

	/// <summary>
	/// Mostra no ecrã um resumo do jogo, numa única linha (equipas e resultado)
	/// </summary>
	virtual void print_resumo();

	/// <summary>
	/// Pede ao utilizador os dados básicos do jogo, e de seguida chama o registar_relato
	/// </summary>
	void inicializar();

	/// <summary>
	/// Valida se o código da posição recebido é válido para esta modalidade
	/// </summary>
	bool valida_posicao(char codigo_posicao);

	/// <summary>
	/// Procura nos titulares e suplentes da equipa recebida pelo jogador com o número recebido
	/// </summary>
	Result<Jogador> encontrar_jogador(int equipa, int numero) const;
protected:
	/// <summary>
	/// Número de golos/pontos da primeira equipa
	/// </summary>
	int total_golos_1 = 0;

	/// <summary>
	/// Número de golos/pontos da segunda equipa
	/// </summary>
	int total_golos_2 = 0;

	/// <summary>
	/// Nome da primeira equipa
	/// </summary>
	std::string equipa_1;

	/// <summary>
	/// Nome da segunda equipa
	/// </summary>
	std::string equipa_2;

	/// <summary>
	/// Lista de jogadores titulares da primeira equipa
	/// </summary>
	std::vector<Jogador> titulares1;

	/// <summary>
	/// Lista de jogadores suplentes da primeira equipa
	/// </summary>
	std::vector<Jogador> suplentes1;

	/// <summary>
	/// Lista de jogadores titulares da segunda equipa
	/// </summary>
	std::vector<Jogador> titulares2;

	/// <summary>
	/// Lista de jogadores suplentes da segunda equipa
	/// </summary>
	std::vector<Jogador> suplentes2;
private:
	/// <summary>
	/// Pede ao utilizador para escrever os dados dos jogadores titulares e suplentes de cada equipa
	///	que jogaram neste jogo
	/// </summary>
	void registar_jogadores();

	/// <summary>
	/// Pede ao utilizador para escrever dados de um jogador, para a equipa recebida
	///	<param name="equipa">Equipa 1 ou 2</param>
	///	<param name="random">Indica se o nome do jogador deve ser aleatório</param>
	///	<param name="current_index">Índice atual do jogador a preencher, para preencher o número da camisola</param>
	/// </summary>
	Jogador registar_jogador(int equipa, bool random, int current_index = 0);
};
