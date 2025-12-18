#include<tuple>

#include "Jogador.h"
#include "Helpers.h"

Jogador::Jogador(const char posicao, const int numero, const std::string& nome)
{
	this->set_posicao(posicao);
	this->set_numero(numero);
	this->set_nome(nome);
}

char Jogador::get_posicao() const
{
    return this->posicao;
}

SimpleResult Jogador::set_posicao(const char nova_posicao)
{
    this->posicao = toupper(nova_posicao);
    return {true, "OK"};
}

int Jogador::get_numero() const
{
    return this->numero;
}

SimpleResult Jogador::set_numero(const int novo_numero)
{
    if (novo_numero < 0 || novo_numero > 99) {
        return {false, "O numero da camisola do jogador apenas pode ser entre 0 e 99."};
    }

    this->numero = novo_numero;

    return {true, "OK"};
}


SimpleResult Jogador::set_numero(const std::string& novo_numero)
{
	const auto result = try_parse_int(novo_numero);

    if (!result.success) {
        return static_cast<SimpleResult>(result);
    }

    return this->set_numero(result.result);
}

std::string Jogador::get_nome()
{
    return this->nome;
}

SimpleResult Jogador::set_nome(std::string novo_nome)
{
    novo_nome = trim(novo_nome);

    if (novo_nome.empty()) {
        return {false, "O jogador tem de ter um nome"};
    }

    this->nome = novo_nome;

    return {true, "OK"};
}

bool Jogador::operator==(const Jogador& rhs) const
{
    return this->numero == rhs.numero;
}
