/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio B

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Ficheiro: strutures.h
*/
#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

// tamanho da base original
typedef struct BASE
{
    int largura, altura;
} BASE;

// estrutura usada pelos objectos criados
typedef struct RETANGULO
{
    /*
    x2,y2 -- x3,y3
        |     |
        |     |
    x0,y0 -- x1,y1
    */
    int x0, y0, x1, y1, x2, y2, x3, y3;
    int x, y, largura, altura;
} RETANGULO;

// estrutura que guarda os objectos e a quantidade dos mesmos
typedef struct LISTA_RETANGULOS
{
    RETANGULO **retangulos;
    int quantidade;
} LISTA_RETANGULOS;

#endif

/* EOF */