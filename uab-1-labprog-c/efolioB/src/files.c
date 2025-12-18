/*
UC: 21178 - Laboratorio de Programação
Ano 2019/20    E-folio B

Universidade Aberta - Engenharia Informática

Nº 1901774  Rui Sousa

Ficheiro: files.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "files.h"
#include "utilities.h"

// transforma a linha lida em estrutura
RETANGULO *descodifica_linha_do_ficheiro(char *linha)
{
    int x, y, w, h;

    const char delimitar[2] = ";";
    int i = 0;
    char *token = strtok(linha, delimitar);

    while (token != NULL)
    {
        switch (i)
        {
            case 0:
                x = atoi(token);
                break;
            case 1:
                y = atoi(token);
                break;
            case 2:
                w = atoi(token);
                break;
            case 3:
                h = atoi(token);
                break;

            default:
                break;
        }

        // linha seguinte
        token = strtok(NULL, delimitar);
        i++;
    }

    RETANGULO *r = cria_retangulo(x, y, w, h);     
    return r;
}

// lê o ficheiro "coord.txt"
int ler_ficheiro(LISTA_RETANGULOS *listaRetangulos)
{
    printf("Ficheiro de leitura: coord.txt\n");
    FILE *ficheiro = fopen("./files/coord.txt", "r");

    int count = 0;
    int tamLinha = 20;
    char linha[tamLinha];
   
    if (ficheiro != NULL)
    {
        while (fgets(linha, 20, ficheiro) != 0)
        {
            // transforma linha lida na estrutura
            RETANGULO *retanguloLinha = descodifica_linha_do_ficheiro(linha);
            // adiciona estrutura à lista
            listaRetangulos->retangulos[count++] = retanguloLinha;            
            // aumenta a memória da lista para o proximo objecto
            listaRetangulos->retangulos = realloc(listaRetangulos->retangulos, sizeof(listaRetangulos->retangulos) * (count+1));
        }
    } else {
        printf("\nERROR ao abrir o ficheiro!!\n");
        exit(0);
    }

    fclose(ficheiro);
    return count;
}

/* EOF */
