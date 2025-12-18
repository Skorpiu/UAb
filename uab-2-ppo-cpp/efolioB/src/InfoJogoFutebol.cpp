#include "InfoJogoFutebol.h"
#include "Helpers.h"
#include <iomanip>

std::string InfoJogoFutebol::get_nome_modalidade()
{
	return "Futebol";
}

int InfoJogoFutebol::get_numero_titulares() {
	return 11;
}

int InfoJogoFutebol::get_numero_suplentes()
{
	return 7;
}

std::vector<Posicao> InfoJogoFutebol::get_posicoes()
{
	std::vector<Posicao> vec;
	
	vec.emplace_back('G', "Guarda-redes");
	vec.emplace_back('D', "Defesa");
	vec.emplace_back('M', "Medio");
	vec.emplace_back('A', "Avancado");

	return vec;
}

bool InfoJogoFutebol::permite_empate()
{
	return true;
}

void InfoJogoFutebol::print_detalhes()
{
	this->print_resumo();

	std::cout << "          CASA          |          FORA          " << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	for (int i = 0; i < this->get_numero_titulares(); i++)
	{
		auto titular1 = this->titulares1.at(i);
		auto titular2 = this->titulares2.at(i);
		std::cout << " " << std::setw(2) << titular1.get_numero() << " " << std::setw(19) << titular1.get_nome() << " |";
		std::cout << " " << std::setw(2) << titular2.get_numero() << " " << std::setw(19) << titular2.get_nome() << " " << std::endl;
	}

	std::cout << "-------------------------------------------------" << std::endl;

	for (int i = 0; i < this->get_numero_suplentes(); i++)
	{
		auto suplente1 = this->suplentes1.at(i);
		auto suplente2 = this->suplentes2.at(i);
		std::cout << " " << std::setw(2) << suplente1.get_numero() << " " << std::setw(19) << suplente1.get_nome() << " |";
		std::cout << " " << std::setw(2) << suplente2.get_numero() << " " << std::setw(19) << suplente2.get_nome() << " " << std::endl;
	}

	std::cout << "-------------------------------------------------" << std::endl << std::endl;

	for (int i = 1; i <= 2; i++)
	{
		auto equipa = i == 1 ? this->equipa_1 : this->equipa_2;
		auto total_golos = i == 1 ? this->total_golos_1 : this->total_golos_2;
		auto golos = i == 1 ? this->golos1 : this->golos2;

		if (total_golos > 0)
		{
			std::cout << "GOLOS " << equipa << ": " << std::endl;

			for (auto golo : golos)
			{
				if (golo.autogolo)
				{
					std::cout << "    " << "Autogolo - " << golo.minuto << "\"" << std::endl;
				}
				else
				{
					std::cout << "    " << golo.jogador.get_numero() << " " << golo.jogador.get_nome() << " - " << golo.minuto << "\"" << std::endl;
				}
			}

			std::cout << std::endl;
		}
	}

	for (int i = 1; i <= 2; i++)
	{
		auto equipa = i == 1 ? this->equipa_1 : this->equipa_2;
		auto substituicoes = i == 1 ? this->substituicoes1 : this->substituicoes2;

		if (!substituicoes.empty())
		{
			std::cout << "SUBSTITUCOES/EXPULSOES " << equipa << ": " << std::endl;

			for (auto sub : substituicoes)
			{
				if (sub.expulsao)
				{
					std::cout << "    " << sub.substituido.get_numero() << " " << sub.substituido.get_nome() << " EXPULSO - " << sub.minuto << "\"" << std::endl;
				}
				else
				{
					std::cout << "    " << sub.substituido.get_numero() << " " << sub.substituido.get_nome();
					std::cout << " <> ";
					std::cout << sub.substituto.get_numero() << " " << sub.substituto.get_nome() << " - " << sub.minuto << std::endl;
				}
			}

			std::cout << std::endl;
		}
	}
}

void InfoJogoFutebol::registar_relato()
{
	registar_substituicoes(1);
	registar_substituicoes(2);
	if (this->total_golos_1 != 0)
	{
		registar_golos(1);
	}

	if (this->total_golos_2)
	{
		registar_golos(2);
	}
}

void InfoJogoFutebol::registar_substituicoes(int equipa)
{
	auto titulares = equipa == 1 ? this->titulares1 : this->titulares2;
	auto suplentes = equipa == 1 ? this->suplentes1 : this->suplentes2;

	std::cout << "REGISTAR SUBSTITUICOES (EQUIPA " << equipa << ")" << std::endl;
	std::cout << "Formato: [substituido], [substituto], [tempo]" << std::endl;
	std::cout << "Para expulsoes, colocar # no substituto" << std::endl;
	std::cout << "Para terminar de preencher, escrever OK" << std::endl;

	do
	{
		std::string input;
		std::cin.sync();
		std::getline(std::cin, input);

		input = trim(input);

		if (input == "OK" || input == "ok")
		{
			return;
		}

		auto parts = split(input, ',');

		if (parts.size() != 3) {
			std::cout << "Input invalido. O formato tem de ser [substituido], [substituto], [tempo]" << std::endl;
			continue;
		}

		const auto parse_tempo_result = try_parse_int(parts.at(2));
		if (!parse_tempo_result.success || parse_tempo_result.result < 0)
		{
			std::cout << "Tempo invalido" << std::endl;
			continue;
		}

		int tempo = parse_tempo_result.result;

		const auto parse_substituido_result = try_parse_int(parts.at(0));

		if (!parse_substituido_result.success)
		{
			std::cout << "Numero do jogador substituido invalido" << std::endl;
			continue;
		}

		const auto find_substituido_result = this->encontrar_jogador(equipa, parse_substituido_result.result);

		if (!find_substituido_result.success)
		{
			std::cout << "O jogador substituido nao foi encontrado" << std::endl;
			continue;
		}

		const auto substituido = find_substituido_result.result;

		if (find_index<Substituicao>(equipa == 1 ? this->substituicoes1 : this->substituicoes2,
			[&substituido](const Substituicao& sub) { return sub.substituido == substituido; }) >= 0) 
		{
			std::cout << "O jogador com o numero " << substituido.get_numero() << " ja foi substituido/expulso" << std::endl;
			continue;
		}


		const bool expulso = parts.at(1) == "#";

		if (expulso)
		{
			auto substituicao = Substituicao(find_substituido_result.result, tempo);
			substituicao.expulsao = true;
			equipa == 1 ? this->substituicoes1.push_back(substituicao) : this->substituicoes2.push_back(substituicao);
		}
		else
		{
			const auto parse_substituto_result = try_parse_int(parts.at(1));

			if (!parse_substituido_result.success)
			{
				std::cout << "Numero do jogador substituto invalido" << std::endl;
				continue;
			}

			int numero_substituto = parse_substituto_result.result;
			int index_substituto = find_index<Jogador>(suplentes, [&numero_substituto](const Jogador& jog) { return jog.get_numero() == numero_substituto; });

			if (index_substituto < 0) {
				std::cout << "O jogador com o numero " << numero_substituto << " nao esta no banco" << std::endl;
				continue;
			}

			auto substituto = suplentes.at(index_substituto);

			auto substituicao = Substituicao(substituido, substituto, tempo);
			substituicao.expulsao = false;
			equipa == 1 ? this->substituicoes1.push_back(substituicao) : this->substituicoes2.push_back(substituicao);
		}
	} while (true);
}

void InfoJogoFutebol::registar_golos(int equipa)
{
	auto titulares = equipa == 1 ? this->titulares1 : this->titulares2;
	auto suplentes = equipa == 1 ? this->suplentes1 : this->suplentes2;
	auto total_golos = equipa == 1 ? this->total_golos_1 : this->total_golos_2;

	std::cout << "REGISTAR GOLOS (EQUIPA " << equipa << ")" << std::endl;
	std::cout << "Formato: [numero jogador], [tempo]" << std::endl;
	std::cout << "Para autogolo, colocar # no numero do jogador" << std::endl;

	do
	{
		std::string input;
		std::cin.sync();
		std::getline(std::cin, input);

		input = trim(input);

		auto parts = split(input, ',');

		if (parts.size() != 2) {
			std::cout << "Input invalido. O formato tem de ser [numero jogador], [tempo]" << std::endl;
			continue;
		}

		const auto parse_tempo_result = try_parse_int(parts.at(1));
		if (!parse_tempo_result.success || parse_tempo_result.result < 0)
		{
			std::cout << "Tempo invalido" << std::endl;
			continue;
		}

		const int tempo = parse_tempo_result.result;

		const bool autogolo = parts.at(0) == "#";

		if (autogolo) {
			auto golo = Golo(tempo);
			equipa == 1 ? this->golos1.push_back(golo) : this->golos2.push_back(golo);
		}
		else
		{
			const auto parse_numero_result = try_parse_int(parts.at(0));

			if (!parse_numero_result.success)
			{
				std::cout << "Numero do jogador invalido" << std::endl;
				continue;
			}

			int numero = parse_numero_result.result;

			const int index_titular = find_index<Jogador>(titulares, [&numero](const Jogador& jog) { return jog.get_numero() == numero;  }) >= 0;
			const int index_suplente = find_index<Jogador>(suplentes, [&numero](const Jogador& jog) { return jog.get_numero() == numero;  }) >= 0;

			// aqui podiamos validar tambem se o jogador estava a jogar no momento em que marcou o golo.
			// para este efolio, omiti esta validação por brevidade

			if (index_titular < 0 && index_suplente < 0) {
				std::cout << "O jogador com o numero " << numero << " nao foi encontrado" << std::endl;
				continue;
			}

			const auto jogador = index_titular >= 0 ? titulares.at(index_titular) : suplentes.at(index_suplente);

			auto golo = Golo(jogador, tempo);
			equipa == 1 ? this->golos1.push_back(golo) : this->golos2.push_back(golo);
		}
	} while ((equipa == 1 ? this->golos1.size() : this->golos2.size()) < total_golos);
}
