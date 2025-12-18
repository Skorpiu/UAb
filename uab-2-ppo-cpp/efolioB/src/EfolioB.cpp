#include <iostream>
#include "Consola.h"
#include "Helpers.h"
#include "InfoJogoFutebol.h"
#include "InfoJogoBasquetebol.h"

std::vector<InfoJogoFutebol> jogos_futebol;
std::vector<InfoJogoBasquetebol> jogos_basquetebol;

void print(const int id_jogo)
{
	cabecalho();

	std::cout << "JOGOS DE " << (id_jogo == 0 ? "FUTEBOL" : "BASQUETEBOL") << std::endl;
	std::cout << "    0. Voltar" << std::endl;
	std::cout << "    1. Registar novo jogo" << std::endl << std::endl;

	const auto tamanho_lista = id_jogo == 0 ? jogos_futebol.size() : jogos_basquetebol.size();
	for (int i = 0; i < tamanho_lista; i++)
	{
		std::cout << "    " << i + 2 << ". ";
		id_jogo == 0 ? jogos_futebol.at(i).print_resumo() : jogos_basquetebol.at(i).print_resumo();
	}

	if (jogos_futebol.empty())
	{
		std::cout << "Ainda nao existem jogos para esta modalidade";
	}

	std::cout << std::endl;
	std::cout << "Introduza a opcao pretendida: ";

	std::string resposta;
	std::cin >> resposta;

	std::cout << std::endl;

	const auto parse_result = try_parse_int(resposta);

	if (parse_result.success)
	{
		const int opcao = parse_result.result;

		if (opcao == 0)
		{
			return;
		}

		if (opcao == 1)
		{
			std::cout << "NOVO JOGO" << std::endl;

			if (id_jogo == 0)
			{
				auto novo_jogo = InfoJogoFutebol();
				novo_jogo.inicializar();
				jogos_futebol.push_back(novo_jogo);
			}
			else if (id_jogo == 1)
			{
				auto novo_jogo = InfoJogoBasquetebol();
				novo_jogo.inicializar();
				jogos_basquetebol.push_back(novo_jogo);
			}
		}
		else if (opcao - 2 >= 0 && opcao - 2 < jogos_futebol.size())
		{
			cabecalho();
			id_jogo == 0 ? jogos_futebol.at(opcao - 2).print_detalhes() : jogos_basquetebol.at(opcao - 2).print_detalhes();
			pressionar_qualquer_tecla();
		}
	}

	print(id_jogo);
}

void inicializar()
{
    cabecalho();

	std::cout << "SELECCIONE UMA OPCAO:" << std::endl;
	std::cout << "    Modalidades:" << std::endl;
	std::cout << "        1: Futebol" << std::endl;
	std::cout << "        2: Basquetebol" << std::endl;
	std::cout << "    Aplicacao:" << std::endl;
	std::cout << "        9: Sair" << std::endl;
	std::cout << std::endl;
	std::cout << "Introduza a opcao pretendida: ";

	std::string opcao;
	std::cin >> opcao;

	std::cout << std::endl;

	if (opcao == "1") {
		print(0);
	}
	else if (opcao == "2") {
		print(1);
	}
	else if (opcao == "9") {
		return;
	}

	inicializar();
}

int main()
{
	srand(time(nullptr));
	inicializar();
}
