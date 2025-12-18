/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio B

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Ficheiro: utilities.h
*/
#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include "structures.h"
#include "utilities.h"

// cria retangulo dando as coordenadas iniciais e o seu tamanho
RETANGULO *cria_retangulo(int x, int y, int w, int h);

// roda o objecto 90 graus
RETANGULO *roda_retangulo(RETANGULO *original, BASE *base);

// retorna o caractere a imprimir do retangulo passado na posicao x,y
char qual_o_simbolo_do_objecto_na_posicao(int x, int y, RETANGULO *r);

// roda o plano e todos os objectos
void roda_plano(LISTA_RETANGULOS *listaRetangulos, BASE *base);

// utilitário para imprimir coordenadas dos objectos
void imprime_coordenadas(LISTA_RETANGULOS *listaRetangulos);

#endif

/* EOF */
