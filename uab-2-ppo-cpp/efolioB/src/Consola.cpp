#include "Consola.h"
#include <iostream>

void limpar()
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

void pressionar_qualquer_tecla()
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

void cabecalho() {
	limpar();

	std::cout << "              10porto               " << std::endl;
	std::cout << "                ###                 " << std::endl;
	std::cout << "         1901774 - Rui Sousa        " << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << std::endl;
}