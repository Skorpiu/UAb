#include "consola.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

consola::consola(atividades_controller atividades_ctrl)
{
	this->atividades_ctrl_ = std::move(atividades_ctrl);
};

void consola::cabecalho() {
	limpar();

	std::cout << "  Exploracao de atividades imersivas  " << std::endl;
	std::cout << "                 ###                  " << std::endl;
	std::cout << "          1901774 - Rui Sousa         " << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << std::endl;
}

void consola::inicializar() {
	cabecalho();
	
	std::cout << "OPCOES DISPONIVEIS:" << std::endl;
	std::cout << "    Consultar atividades:" << std::endl;
	std::cout << "        1: Ordenadas por grau de imersao pelo sistema" << std::endl;
	std::cout << "        2: Ordenadas por grau de imersao pela narrativa" << std::endl;
	std::cout << "        3: Ordenadas por grau de imersao pela agencia" << std::endl;
	std::cout << "    Gerir atividades:" << std::endl;
	std::cout << "        4: Inserir nova atividade" << std::endl;
	std::cout << "    Aplicacao:" << std::endl;
	std::cout << "        5: Sair" << std::endl;
	std::cout << std::endl;
	std::cout << "Introduza a opcao pretendida:";

	std::string opcao;
	std::cin >> opcao;

	std::cout << std::endl;

	if (opcao == "1") {
		atividades_ctrl_.ordenar("imersao_sistema");
		cabecalho();
		std::cout << "LISTAGEM DE ATIVIDADES" << std::endl << "ORDENADAS POR GRAU DE IMERSAO PELO SISTEMA" << std::endl << std::endl;
		listar_atividades();
	}
	else if (opcao == "2") {
		atividades_ctrl_.ordenar("imersao_narrativa");
		cabecalho();
		std::cout << "LISTAGEM DE ATIVIDADES" << std::endl << "ORDENADAS POR GRAU DE IMERSAO PELA NARRATIVA" << std::endl << std::endl;
		listar_atividades();
	}
	else if (opcao == "3") {
		atividades_ctrl_.ordenar("imersao_agencia");
		std::cout << "LISTAGEM DE ATIVIDADES" << std::endl << "ORDENADAS POR GRAU DE IMERSAO PELA AGENCIA" << std::endl << std::endl;
		cabecalho();
		listar_atividades();
	}
	else if (opcao == "4") {
		nova_atividade();
	}
	else if (opcao == "5") {
		return;
	}

	inicializar();
}

void consola::nova_atividade() {
	const auto nova_atividade = new atividade();

	bool sucesso = true;
	std::string mensagem;
	do
	{
		cabecalho();
		std::cin.ignore();

		std::cout << "INSERIR NOVA ATIVIDADE" << std::endl;
		std::cout << "Preencha os campos abaixo:" << std::endl;

		if (!sucesso)
		{
			std::cout << std::endl << "## ERRO AO INSERIR:" << std::endl;
			std::cout << "## " << mensagem << std::endl << std::endl;
		}

		std::cout << std::endl << "    Titulo: ";
		std::getline(std::cin, nova_atividade->titulo);

		std::cout << std::endl << "    Descricao: ";
		std::getline(std::cin, nova_atividade->descricao);

		std::cout << std::endl << "    URL do video: ";
		std::cin >> nova_atividade->url;

		std::cout << std::endl << "    Grau de imersao pelo sistema: ";
		std::cin >> nova_atividade->imersao_sistema;

		std::cout << std::endl << "    Grau de imersao pela narrativa: ";
		std::cin >> nova_atividade->imersao_narrativa;

		std::cout << std::endl << "    Grau de imersao pela agencia: ";
		std::cin >> nova_atividade->imersao_agencia;

		std::tie(sucesso, mensagem) = this->atividades_ctrl_.criar(*nova_atividade);
	} while (!sucesso);

	std::cout << "## ATIVIDADE INSERIDA COM SUCESSO." << std::endl;
	pressionar_qualquer_tecla();
}

void consola::limpar()
{
	// Ver se é windows ou linux: https://stackoverflow.com/a/8249232
	// Limpar consola: https://stackoverflow.com/a/62517693
#if defined(_WIN32)
	system("cls");
#endif

#if defined(unix) || defined(__unix) || defined(__unix__) || defined(__linux__) || defined (__APPLE__) || defined(__MACH__)
	system("clear");
#endif

	std::cin.sync();
	std::cin.clear();
}

void consola::pressionar_qualquer_tecla()
{
	std::cout << "Pressionar qualquer tecla para voltar" << std::endl;

	// Ver se é windows ou linux: https://stackoverflow.com/a/8249232
	// Pressionar qualquer tecla em C++: https://stackoverflow.com/a/1452701
#if defined(_WIN32)
	system("pause");
#endif

#if defined(unix) || defined(__unix) || defined(__unix__) || defined(__linux__) || defined (__APPLE__) || defined(__MACH__)
	system("read");
#endif
}

void consola::listar_atividades() const
{
	std::cout << std::setw(20) << std::left << "Titulo";
	std::cout << std::setw(8) << std::right << "Sistema";
	std::cout << std::setw(10) << std::right << "Narrativa";
	std::cout << std::setw(8) << std::right << "Agencia";
	std::cout << std::endl;

	std::cout << "----------------------------------------------" << std::endl;

	for(const auto& [titulo, descricao, url, imersao_sistema, imersao_narrativa, imersao_agencia] : atividades_ctrl_.atividades)
	{
		std::cout << std::setw(20) << std::left << titulo;
		std::cout << std::setw(8) << std::right << imersao_sistema;
		std::cout << std::setw(10) << std::right << imersao_narrativa;
		std::cout << std::setw(8) << std::right << imersao_agencia;

		std::cout << std::endl;
	}

	if (atividades_ctrl_.atividades.empty())
	{
		std::cout << "Nao existem atividades a listar." << std::endl;
	}

	std::cout << std::endl;

	pressionar_qualquer_tecla();
}
