/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio B

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Ficheiro: files.h
*/
#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include "structures.h"

// transforma a linha lida em estrutura
RETANGULO *descodifica_linha_do_ficheiro(char *linha);

// lê o ficheiro "coord.txt"
int ler_ficheiro();

#endif

/* EOF */
