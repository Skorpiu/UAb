#include "InfoJogo.h"
#include "Helpers.h"
#include <algorithm>
#include <iostream>

void InfoJogo::print_resumo()
{
	std::cout << this->equipa_1 << " [" << this->total_golos_1 << "] - [" << this->total_golos_2 << "] " << this->equipa_2 << std::endl;
}

void InfoJogo::inicializar()
{
	std::cin.ignore();

	do
	{
		std::cout << "Equipa casa: ";
		std::cin.sync();
		std::getline(std::cin, this->equipa_1);
		this->equipa_1 = trim(this->equipa_1);
	} while (this->equipa_1.empty());

	do
	{
		std::cout << "Equipa fora: ";
		std::cin.sync();
		std::getline(std::cin, this->equipa_2);
		this->equipa_2 = trim(this->equipa_2);
	} while (this->equipa_2.empty());

	bool resultado_valido = false;
	do
	{
		bool golos_casa_parsed = false;
		do
		{
			std::string golos_casa;
			std::cout << "Golos/pontos casa: ";
			std::cin >> golos_casa;

			const auto parse_result = try_parse_int(golos_casa);
			golos_casa_parsed = parse_result.success && parse_result.result >= 0;

			if (golos_casa_parsed)
			{
				this->total_golos_1 = parse_result.result;
			}
		} while (!golos_casa_parsed);

		bool golos_fora_parsed = false;
		do
		{
			std::string golos_fora;
			std::cout << "Golos/pontos fora: ";
			std::cin >> golos_fora;

			const auto parse_result = try_parse_int(golos_fora);
			golos_fora_parsed = parse_result.success && parse_result.result >= 0;

			if (golos_fora_parsed)
			{
				this->total_golos_2 = parse_result.result;
			}
		} while (!golos_fora_parsed);

		resultado_valido = this->permite_empate() || this->total_golos_1 != this->total_golos_2;

		if (!resultado_valido)
		{
			std::cout << "A modalidade " << this->get_nome_modalidade() << " nao permite empates." << std::endl;
		}

	} while (!resultado_valido);

	this->registar_jogadores();
	this->registar_relato();
}

void InfoJogo::registar_jogadores() {
	std::string resposta;
	std::cout << "Pretende gerar nomes automaticamente? (S/N): ";
	std::cin.ignore();
	std::getline(std::cin, resposta);

	const bool gerar_automaticamente = !resposta.empty() && tolower(resposta[0]) == 's';

	std::cout << "REGISTAR JOGADORES" << std::endl;
	std::cout << "Formato: [sigla posicao], [numero], [nome]" << std::endl;
	std::cout << "Posicoes disponiveis: ";

	const auto posicoes = this->get_posicoes();

	for (int i = 0; i < posicoes.size(); i++) {
		auto pos = posicoes.at(i);
		
		std::cout << "[" << pos.codigo << "] " << pos.descricao;

		if (i < posicoes.size() - 1) {
			std::cout << ", ";
		}
	}

	std::cout << std::endl << "TITULARES EQUIPA 1:" << std::endl;

	for (int i = 0; i < this->get_numero_titulares(); i++) {
		this->titulares1.push_back(this->registar_jogador(1, gerar_automaticamente, i));
	}

	std::cout << std::endl << "SUPLENTES EQUIPA 1:" << std::endl;
	for (int i = 0; i < this->get_numero_suplentes(); i++) {
		this->suplentes1.push_back(this->registar_jogador(1, gerar_automaticamente, i + this->get_numero_titulares()));
	}

	std::cout << std::endl << "TITULARES EQUIPA 2:" << std::endl;

	for (int i = 0; i < this->get_numero_titulares(); i++) {
		this->titulares2.push_back(this->registar_jogador(2, gerar_automaticamente, i));
	}

	std::cout << std::endl << "SUPLENTES EQUIPA 2:" << std::endl;
	for (int i = 0; i < this->get_numero_suplentes(); i++) {
		this->suplentes2.push_back(this->registar_jogador(2, gerar_automaticamente, i + this->get_numero_titulares()));
	}
}

bool InfoJogo::valida_posicao(char codigo_posicao)
{
	auto index = find_index<Posicao>(
		this->get_posicoes(), 
		[&codigo_posicao](const Posicao& p) { return toupper(p.codigo) == toupper(codigo_posicao); });

	return index >= 0;
}

Result<Jogador> InfoJogo::encontrar_jogador(const int equipa, int numero) const
{
	const auto titulares = equipa == 1 ? this->titulares1 : this->titulares2;
	const auto suplentes = equipa == 1 ? this->suplentes1 : this->suplentes2;

	const auto index_titulares = find_index<Jogador>(titulares, [&numero](const Jogador& jog) { return jog.get_numero() == numero; });
	const auto index_suplentes = find_index<Jogador>(suplentes, [&numero](const Jogador& jog) { return jog.get_numero() == numero; });

	if (index_titulares < 0 && index_suplentes < 0)
	{
		return { false, "O jogador nao foi encontrado" };
	}

	const auto jogador = index_titulares >= 0 ? titulares.at(index_titulares) : suplentes.at(index_suplentes);
	return {true, "OK", jogador};
}

Jogador InfoJogo::registar_jogador(const int equipa, const bool random, const int current_index)
{
	if (random)
	{
		auto jogador = Jogador(get_random_element(this->get_posicoes()).codigo, current_index + 1, get_nome_aleatorio());
		std::cout << jogador.get_posicao() << ", " << jogador.get_numero() << ", " << jogador.get_nome() << std::endl;

		return jogador;
	}

	while (true)
	{
		std::string input;
		std::cin.sync();
		std::getline(std::cin, input);

		auto parts = split(input, ',');

		if (parts.size() != 3) {
			std::cout << "Input invalido. O formato tem de ser [sigla posicao], [numero], [nome]" << std::endl;
			continue;
		}

		if (parts.at(0).size() != 1 || !this->valida_posicao(parts.at(0)[0])) {
			std::cout << "Posicao invalida" << std::endl;
			continue;
		}

		const auto parse_numero_result = try_parse_int(parts.at(1));

		if (!parse_numero_result.success) {
			std::cout << "Numero invalido" << std::endl;
			continue;
		}

		if (parts.at(2).empty()) {
			std::cout << "Nome invalido" << std::endl;
			continue;
		}

		auto jogador = Jogador(parts.at(0)[0], parse_numero_result.result, parts.at(2));

		const auto lista_titulares = equipa == 1 ? this->titulares1 : this->titulares2;
		const auto lista_suplentes = equipa == 1 ? this->suplentes1 : this->suplentes2;

		if (find_index<Jogador>(lista_titulares, [&jogador](const Jogador& jog) { return jog.get_numero() == jogador.get_numero(); }) >= 0)
		{
			std::cout << "Ja existe um jogador titular com esse numero" << std::endl;
			continue;
		}

		if (find_index<Jogador>(lista_suplentes, [&jogador](const Jogador& jog) { return jog.get_numero() == jogador.get_numero(); }) >= 0)
		{
			std::cout << "Ja existe um jogador suplente com esse numero" << std::endl;
			continue;
		}

		std::cout << "   OK!" << std::endl;

		return jogador;
	}
}
