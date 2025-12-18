#pragma once
#include "atividades-controller.h"

class consola {
public:
	void inicializar();
	explicit consola(atividades_controller atividades_ctrl);
private:
	static void cabecalho();
	static void limpar();
	static void pressionar_qualquer_tecla();
	void listar_atividades() const;
	void nova_atividade();

	atividades_controller atividades_ctrl_;
};
