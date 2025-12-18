/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio B

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Ficheiro: utilities.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "utilities.h"

// cria retangulo dando as coordenadas iniciais e o seu tamanho
RETANGULO *cria_retangulo(int x, int y, int w, int h)
{
    RETANGULO *retangulo = calloc(1, sizeof(RETANGULO));

    // posicoes iniciais
    retangulo->x = x;
    retangulo->y = y;
    retangulo->largura = w;
    retangulo->altura = h;

    // utilitarios de ajuda
    retangulo->x0 = x;          retangulo->y0 = y;
    retangulo->x1 = x + w - 1;  retangulo->y1 = y;
    retangulo->x2 = x;          retangulo->y2 = y + h - 1;
    retangulo->x3 = x + w - 1;  retangulo->y3 = y + h - 1;

    return retangulo;
}

// retorna o caractere a imprimir do retangulo passado na posicao x,y
char qual_o_simbolo_do_objecto_na_posicao(int x, int y, RETANGULO *r)
{
    // extremos
    if (x == r->x0 && y == r->y0)
        return '+';
    else if (x == r->x1 && y == r->y1)
        return '+';
    else if (x == r->x2 && y == r->y2)
        return '+';
    else if (x == r->x3 && y == r->y3)
        return '+';
    // linha
    else if (y == r->y0 && (x > r->x0 && x < r->x1))
        return '-';
    else if (y == r->y2 && (x > r->x2 && x < r->x3))
        return '-';
    // coluna
    else if (x == r->x0 && (y > r->y0 && y < r->y2))
        return '|';
    else if (x == r->x1 && (y > r->y1 && y < r->y3))
        return '|';
    
    // resto
    return ' ';
}

// roda o objecto 90 graus
RETANGULO *roda_retangulo(RETANGULO *original, BASE *base)
{    
    // o x é o y anterior
    int x = original->y;
    // o y, como desenhamos de cima para baixo, a largura da base menos a posica de x anterior
    int y = base->largura - original->x;

    return cria_retangulo(x, y, original->altura, original->largura);
}

// roda o plano e todos os objectos
void roda_plano(LISTA_RETANGULOS *listaRetangulos, BASE *base)
{
    printf("A rodar o plano e o seu conteudo...\n");

    // roda base
    int altura = base->altura;
    int largura = base->largura;
    base->altura = largura;
    base->largura = altura;

    // roda objectos
    for(int z = 0; z < listaRetangulos->quantidade; z += 1)
        for (int i = 0; i < listaRetangulos->quantidade; i+=1)
            listaRetangulos->retangulos[i] = roda_retangulo(listaRetangulos->retangulos[i], base);
}

// utilitário para imprimir coordenadas dos objectos
void imprime_coordenadas(LISTA_RETANGULOS *listaRetangulos)
{
    for( int i = 0; i < listaRetangulos->quantidade; i += 1)
    {
        RETANGULO *r = listaRetangulos->retangulos[i];
        printf("Retangulo %d = x(%d) y(%d) %dx%d\n", i+1, r->x, r->y, r->largura, r->altura);
    }
}

/* EOF */
