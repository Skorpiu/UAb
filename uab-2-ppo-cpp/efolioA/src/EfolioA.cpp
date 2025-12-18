// EfolioA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "consola.h"

int main()
{
	auto atividades_ctrl = atividades_controller();

	auto skill_training = atividade("Skill Training", "Skill Training", "https://skill.com", 0, 0.5, 1);
	auto collaboration = atividade("Collaboration", "Collaboration", "https://collaborate.com", 0, 0.25, 1);

	// demostração do overload do operador
	auto somatorio = skill_training + collaboration;
	somatorio.titulo = "Somatorio";
	somatorio.descricao = "Somatorio das duas atividades";
	somatorio.url = "https://skill-collaborate.com";

	atividades_ctrl.criar(skill_training);
	atividades_ctrl.criar(collaboration);
	atividades_ctrl.criar(somatorio);
	

	auto cmd = consola(atividades_ctrl);

	cmd.inicializar();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
