#include "InfoJogoBasquetebol.h"

#include <iomanip>

#include "Helpers.h"


std::string InfoJogoBasquetebol::get_nome_modalidade()
{
	return "Basquetebol";
}

int InfoJogoBasquetebol::get_numero_titulares() {
	return 5;
}

int InfoJogoBasquetebol::get_numero_suplentes()
{
	return 7;
}

std::vector<Posicao> InfoJogoBasquetebol::get_posicoes()
{
	std::vector<Posicao> vec;

	vec.emplace_back('B', "Base");
	vec.emplace_back('E', "Extremo");
	vec.emplace_back('P', "Poste");

	return vec;
}


bool InfoJogoBasquetebol::permite_empate()
{
	return false;
}

void InfoJogoBasquetebol::print_detalhes()
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
		auto total_pontos = i == 1 ? this->total_golos_1 : this->total_golos_2;
		auto pontos = i == 1 ? this->pontos_1 : this->pontos_2;

		if (total_pontos > 0)
		{
			std::cout << "PONTOS " << equipa << ": " << std::endl;

			for (auto p : pontos)
			{
				std::cout << "    " << p.jogador.get_numero() << " " << p.jogador.get_nome() << " - " << p.pontos << std::endl;
			}

			std::cout << std::endl;
		}
	}

	for (int i = 1; i <= 2; i++)
	{
		auto equipa = i == 1 ? this->equipa_1 : this->equipa_2;
		auto tempo_jogado = i == 1 ? this->tempo_jogado_1 : this->tempo_jogado_2;

		if (!tempo_jogado.empty())
		{
			std::cout << "TEMPO DE JOGO " << equipa << ": " << std::endl;

			for (auto t : tempo_jogado)
			{
				std::cout << "    " << t.jogador.get_numero() << " " << t.jogador.get_nome() << " - " << t.minutos << ":" << t.segundos << std::endl;
			}

			std::cout << std::endl;
		}
	}
}

void InfoJogoBasquetebol::registar_relato()
{
	this->registar_tempo_jogado(1);
	this->registar_tempo_jogado(2);
	this->registar_pontuacao(1);
	this->registar_pontuacao(2);
}

void InfoJogoBasquetebol::registar_tempo_jogado(int equipa)
{
	std::cout << "REGISTAR TEMPO JOGADO (EQUIPA " << equipa << ")" << std::endl;
	std::cout << "Formato: [jogador]: [minutos]:[segundos]" << std::endl;
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

		auto parts = split(input, ':');

		if (parts.size() != 3) {
			std::cout << "Input invalido. O formato tem de ser [jogador]: [minutos]:[segundos]" << std::endl;
			continue;
		}

		const auto parse_numero_result = try_parse_int(parts.at(0));
		if (!parse_numero_result.success || parse_numero_result.result < 0 || parse_numero_result.result > 99)
		{
			std::cout << "Numero de jogador invalido" << std::endl;
			continue;
		}

		const auto parse_minutos_result = try_parse_int(parts.at(1));
		if (!parse_minutos_result.success || parse_minutos_result.result < 0 || parse_minutos_result.result >= 60)
		{
			std::cout << "Tempo jogado (minutos) invalido" << std::endl;
			continue;
		}

		const auto parse_segundos_result = try_parse_int(parts.at(2));
		if (!parse_segundos_result.success || parse_segundos_result.result < 0 || parse_segundos_result.result >= 60)
		{
			std::cout << "Tempo jogado (segundos) invalido" << std::endl;
			continue;
		}

		auto find_jogador_result = this->encontrar_jogador(equipa, parse_numero_result.result);

		if (!find_jogador_result.success)
		{
			std::cout << "O jogador com o numero " << parse_numero_result.result << " nao foi encontrado" << std::endl;
			continue;
		}

		auto tempo_jogado = TempoJogado(find_jogador_result.result, parse_minutos_result.result, parse_segundos_result.result);

		equipa == 1 ? this->tempo_jogado_1.push_back(tempo_jogado) : this->tempo_jogado_2.push_back(tempo_jogado);
	} while (true);
}

void InfoJogoBasquetebol::registar_pontuacao(const int equipa)
{
	const int pontos_equipa = equipa == 1 ? this->total_golos_1 : this->total_golos_2;

	if (pontos_equipa == 0)
	{
		// A equipa não pontuou, não precisamos de pedir pontos
		return;
	}

	std::cout << "REGISTAR PONTUACAO (EQUIPA " << equipa << ")" << std::endl;
	std::cout << "Formato: [numero jogador], [pontos]" << std::endl;

	bool concluido = false;
	int pontos_registados = 0;

	do
	{
		std::string input;
		std::cin.sync();
		std::getline(std::cin, input);

		input = trim(input);

		auto parts = split(input, ',');

		if (parts.size() != 2) {
			std::cout << "Input invalido. O formato tem de ser [numero jogador], [pontos]" << std::endl;
			continue;
		}

		const auto parse_numero_result = try_parse_int(parts.at(0));
		if (!parse_numero_result.success || parse_numero_result.result < 0 || parse_numero_result.result > 99)
		{
			std::cout << "Numero de jogador invalido" << std::endl;
			continue;
		}

		const auto find_jogador_result = this->encontrar_jogador(equipa, parse_numero_result.result);

		if (!find_jogador_result.success)
		{
			std::cout << "O jogador com o numero " << parse_numero_result.result << " nao foi encontrado" << std::endl;
			continue;
		}

		const auto parse_pontos_result = try_parse_int(parts.at(1));
		if (!parse_pontos_result.success || parse_pontos_result.result < 0)
		{
			std::cout << "Pontuacao invalida. Tem de ser um numero inteiro, maior que 0" << std::endl;
			continue;
		}

		const int pontos_jogador = parse_pontos_result.result;

		if (pontos_jogador + pontos_registados > pontos_equipa)
		{
			std::cout << "A pontuacao introduzida para o jogador (" << pontos_jogador << ") ";
			std::cout << "faz com que os pontos introduzidos excedam o resultado final da equipa(" << pontos_equipa << ")" << std::endl;
			continue;
		}

		auto pontuacao = Pontos(find_jogador_result.result, pontos_jogador);
		equipa == 1 ? this->pontos_1.push_back(pontuacao) : this->pontos_2.push_back(pontuacao);

		pontos_registados += pontos_jogador;
	} while (pontos_registados != pontos_equipa);
}
