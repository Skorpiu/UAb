#pragma once
#include <iostream>
#include "SimpleResult.h"

class Jogador
{
public:
	Jogador() = default;
	Jogador(const char posicao, const int numero, const std::string& nome);

	/// <summary>
	/// Adquire a posição do jogador
	/// </summary>
	/// <returns>Posição atual do jogador</returns>
	char get_posicao() const;

	/// <summary>
	/// Grava a posição do jogador
	/// </summary>
	/// <param name="nova_posicao">Nova posição do jogador</param>
	/// <returns>Tuple que indica se a operação ocorreu com sucesso, juntamente com a mensagem de validação</returns>
	SimpleResult set_posicao(char nova_posicao);

	/// <summary>
	/// Adquire o número do jogador
	/// </summary>
	/// <returns>Número atual do jogador</returns>
	int get_numero() const;
	
	/// <summary>
	/// Grava o número da camisola do jogador
	/// </summary>
	/// <param name="novo_numero">Novo número da camisola do jogador, compreendido entre 1 e 99</param>
	/// <returns>Tuple que indica se a operação ocorreu com sucesso, juntamente com a mensagem de validação</returns>
	SimpleResult set_numero(int novo_numero);

	/// <summary>
	/// Grava o número da camisola do jogador
	/// </summary>
	/// <param name="novo_numero">Novo número da camisola do jogador, compreendido entre 1 e 99</param>
	/// <returns>Tuple que indica se a operação ocorreu com sucesso, juntamente com a mensagem de validação</returns>
	SimpleResult set_numero(const std::string& novo_numero);

	/// <summary>
	/// Adquire o nome do jogador
	/// </summary>
	/// <returns>Nome atual do jogador</returns>
	std::string get_nome();

	/// <summary>
	/// Grava o nome do jogador
	/// </summary>
	/// <param name="novo_nome">Novo nome do jogador</param>
	/// <returns>Tuple que indica se a operação ocorreu com sucesso, juntamente com a mensagem de validação</returns>
	SimpleResult set_nome(std::string novo_nome);

	// Override ao operador == para poder procurar jogadores num vetor através do std::find
	bool operator ==(const Jogador& rhs) const;
	
private:
	int numero;
	char posicao;
	std::string nome;
};

