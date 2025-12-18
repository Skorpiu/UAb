/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio B

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Ficheiro: main.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "files.h"
#include "utilities.h"

// variavel global que contem todos os objectos no plano
LISTA_RETANGULOS *listaRetangulos;
BASE *base;

// desenha plano com objectos
void desenha(BASE *base) {
    int w = base->largura;
    int h = base->altura;
        
    for (int y = h; y >= 0; y -= 1) // y
    {
        for (int x = 0; x <= w; x += 1)
        {
            // x, y
            if ((x == 0 && y == 0) || (x == w && y == h) 
                || (x == 0 && y == h) || (x == w && y == 0))
                printf("*");
            else if (x == 0 || x == w)
            {
                printf("|");
            }
            else if (y == 0 || y == h)
            {
                printf("-");
            }
            else
            {
                char *simbolos = calloc(listaRetangulos->quantidade, sizeof(char));
                char simbolo_a_imprimir = ' ';
                
                // le todos os simbolos para posicao x,y
                for (int i = 0; i < listaRetangulos->quantidade; i+=1)
                {
                    RETANGULO *r = listaRetangulos->retangulos[i];
                    simbolos[i] = qual_o_simbolo_do_objecto_na_posicao(x, y, r);
                }
                
                for (int i = 0; i < listaRetangulos->quantidade; i+=1)
                {
                    if (simbolos[i] == '+') { simbolo_a_imprimir = '+'; break; }
                    else if(simbolos[i] == '-') { simbolo_a_imprimir = '-'; }
                    else if(simbolos[i] == '|') { simbolo_a_imprimir = '|'; }
                }

                printf("%c", simbolo_a_imprimir);
                free(simbolos);
            }
        }
        printf("\n");
    }
}

// aplica a gravidade num retangulo
RETANGULO *aplica_gravidade_por_retangulo(int posicao)
{
    RETANGULO *original = listaRetangulos->retangulos[posicao];
    RETANGULO *novo = calloc(1, sizeof(RETANGULO));

    int xMin = original->x0 + 1; // (+1) margem esquerda nao é contada
    int xMax = original->x1 - 1; // (-1) margem direita nao é contada
    int yMax = original->y0;
    int yMin = 1; // base do plano

    int posicoes_a_mover = original->y0-1; // assume-se que pode ir até abaixo (y=1)
    int objeto_foi_movido = 0;

    for(int y = yMax; y >= yMin; y -= 1)
    {
        for(int x = xMin; x <= xMax; x += 1)
        {
            // x,y

            char *simbolos = calloc(listaRetangulos->quantidade, sizeof(char));
            
            // le todos os simbolos para posicao x,y
            for (int i = 0; i < listaRetangulos->quantidade; i+=1)
            {
                if (i == posicao) continue;
                RETANGULO *r = listaRetangulos->retangulos[i];
                simbolos[i] = qual_o_simbolo_do_objecto_na_posicao(x, y, r);
            }
            
            for (int i = 0; i < listaRetangulos->quantidade; i+=1)
            {
                if (i == posicao) continue;

                if (simbolos[i] != ' ')
                { 
                    posicoes_a_mover = yMax - y;
                    objeto_foi_movido = 1;
                    break;
                }
            }

            free(simbolos);
        }
        if (objeto_foi_movido == 1) break;
    }

    // posicoes anteriores
    novo->largura = original->largura;
    novo->altura = original->altura;
    novo->x0 = original->x0;
    novo->x1 = original->x1;
    novo->x2 = original->x2;
    novo->x3 = original->x3;

    novo->x = original->x;
    novo->y = original->y - posicoes_a_mover;

    // novas posicoes    
    novo->y0 = original->y0 - posicoes_a_mover;
    novo->y1 = original->y1 - posicoes_a_mover;
    novo->y2 = original->y2 - posicoes_a_mover;
    novo->y3 = original->y3 - posicoes_a_mover;

    // printf("Retangulo %d move-se %d posicoes\n", posicao+1, posicoes_a_mover);

    free(original);
    return novo;
}

// aplica gravidade a todos os objectos
void aplica_gravidade()
{
    printf("Aplicar gravidade...\n");

    // verifica novamente por causa da ordenacao dos rectangulos na lista
    for(int z = 0; z < listaRetangulos->quantidade; z += 1)
        // aplica gravidade por cada objecto
        for (int i = 0; i < listaRetangulos->quantidade; i+=1)
            listaRetangulos->retangulos[i] = aplica_gravidade_por_retangulo(i);
}

// clear && gcc -Wall -Werror -o retangulos ./src/*.c && ./retangulos
int main(int argc, char *argv[])
{
    base = calloc(1, sizeof(BASE));
    base->largura = 80;
    base->altura = 25;

    // mostra dimensoes do plano
    printf("PLANO BASE tem %dx%d\n", base->largura, base->altura);
    
    // lista dos objectos
    listaRetangulos = calloc(1, sizeof(listaRetangulos));
    listaRetangulos->retangulos = calloc(1, sizeof(listaRetangulos->retangulos));
    
    // le o ficheiro e descodifica o seu conteudo
    listaRetangulos->quantidade = ler_ficheiro(listaRetangulos);

    // pocisoes originais
    imprime_coordenadas(listaRetangulos);
    desenha(base);

    // com gravidade
    aplica_gravidade();
    imprime_coordenadas(listaRetangulos);
    desenha(base);

    // rodar 90 graus e com gravidade
    roda_plano(listaRetangulos, base);
    imprime_coordenadas(listaRetangulos);
    aplica_gravidade();
    imprime_coordenadas(listaRetangulos);
    desenha(base);

    // libertar memoria usada
    free(listaRetangulos->retangulos);
    free(listaRetangulos);

    exit(EXIT_SUCCESS);
}

/* EOF */