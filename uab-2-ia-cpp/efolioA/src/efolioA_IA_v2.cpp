#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;

void instanciaID (int id)
{
    int linhas, colunas, xLetra, yLetra, contaLetras;  

    switch (id)
    {
        case 1:
            id == 1;
            linhas = 3;
            colunas = 3;
            contaLetras = 2;
            impLetra(0, 0, 'A');
            impLetra(0, 1, 'B');
            impLetra(2, 1, 'A');
            impLetra(2, 2, 'B');
        
        case 2:
            id == 2;
            linhas = 3;
            colunas = 3;
            contaLetras = 2;
            impLetra(0, 0, 'A');
            impLetra(0, 2, 'B');
            impLetra(2, 0, 'B');
            impLetra(2, 2, 'A');

        case 3:
            id == 3;
            linhas = 3;
            colunas = 6;
            contaLetras = 4;
            impLetra(0, 0, 'A');
            impLetra(0, 1, 'B');
            impLetra(0, 3, 'C');
            impLetra(0, 4, 'D');
            impLetra(2, 1, 'A');
            impLetra(2, 2, 'B');
            impLetra(2, 4, 'C');
            impLetra(2, 5, 'D');

        case 4:
            id == 4;
            linhas = 4;
            colunas = 10;
            contaLetras = 4;
            impLetra(0, 0, 'A');
            impLetra(0, 1, 'B');
            impLetra(0, 4, 'C');
            impLetra(0, 5, 'D');
            impLetra(3, 3, 'A');
            impLetra(3, 4, 'B');
            impLetra(3, 8, 'C');
            impLetra(3, 9, 'D');
        
        case 5:
            id == 5;
            linhas = 4;
            colunas = 10;
            contaLetras = 4;
            impLetra(1, 2, 'A');
            impLetra(1, 7, 'B');
            impLetra(2, 2, 'B');
            impLetra(2, 4, 'C');
            impLetra(2, 5, 'D');
            impLetra(2, 7, 'A');
            impLetra(3, 0, 'C');
            impLetra(3, 9, 'D');

        case 6:
            id == 6;
            linhas = 4;
            colunas = 10;
            contaLetras = 4;
            impLetra(0, 0, 'D');
            impLetra(0, 9, 'C');
            impLetra(1, 2, 'A');
            impLetra(1, 7, 'B');
            impLetra(2, 2, 'B');
            impLetra(2, 7, 'A');
            impLetra(3, 0, 'C');
            impLetra(3, 9, 'D');
        
        case 7:
            id == 7;
            linhas = 6;
            colunas = 10;
            contaLetras = 5;
            impLetra(0, 0, 'C');
            impLetra(1, 5, 'D');
            impLetra(1, 7, 'B');
            impLetra(1, 8, 'A');
            impLetra(3, 1, 'D');
            impLetra(3, 2, 'A');
            impLetra(4, 1, 'E');
            impLetra(4, 5, 'B');
            impLetra(4, 8, 'E');
            impLetra(5, 6, 'C');

        case 8:
            id == 8;
            linhas = 8;
            colunas = 10;
            contaLetras = 8;
            impLetra(1, 2, 'A');
            impLetra(1, 7, 'B');
            impLetra(2, 2, 'B');
            impLetra(2, 4, 'C');
            impLetra(2, 5, 'D');
            impLetra(2, 7, 'A');
            impLetra(3, 0, 'C');
            impLetra(3, 9, 'D');
            impLetra(5, 2, 'E');
            impLetra(5, 7, 'F');
            impLetra(6, 2, 'F');
            impLetra(6, 4, 'G');
            impLetra(6, 5, 'H');
            impLetra(6, 7, 'E');
            impLetra(7, 0, 'G');
            impLetra(7, 9, 'H');

        case 9:
            id == 9;
            linhas = 7;
            colunas = 7;
            contaLetras = 5;
            impLetra(0, 3, 'D');
            impLetra(1, 1, 'C');
            impLetra(1, 4, 'B');
            impLetra(1, 5, 'E');
            impLetra(2, 3, 'C');
            impLetra(3, 4, 'A');
            impLetra(4, 3, 'E');
            impLetra(5, 2, 'A');
            impLetra(6, 0, 'B');
            impLetra(6, 4, 'D');

        case 10:
            id == 10;
            linhas = 9;
            colunas = 9;
            contaLetras = 8;
            impLetra(1, 3, 'B');
            impLetra(1, 4, 'C');
            impLetra(1, 7, 'D');
            impLetra(2, 5, 'D');
            impLetra(2, 7, 'E');
            impLetra(4, 4, 'F');
            impLetra(4, 6, 'E');
            impLetra(4, 8, 'G');
            impLetra(7, 6, 'H');
            impLetra(8, 0, 'A');
            impLetra(8, 1, 'B');
            impLetra(8, 2, 'C');
            impLetra(8, 3, 'A');
            impLetra(8, 4, 'H');
            impLetra(8, 5, 'F');
            impLetra(8, 8, 'G');

        case 11:
            id == 11;
            linhas = 10;
            colunas = 10;
            contaLetras = 10;
            impLetra(1, 0, 'A');
            impLetra(1, 3, 'B');
            impLetra(1, 4, 'A');
            impLetra(1, 6, 'H');
            impLetra(1, 7, 'I');
            impLetra(2, 8, 'I');
            impLetra(3, 3, 'G');
            impLetra(3, 6, 'F');
            impLetra(3, 8, 'E');
            impLetra(4, 2, 'F');
            impLetra(4, 5, 'H');
            impLetra(4, 8, 'J');
            impLetra(4, 9, 'C');
            impLetra(5, 0, 'B');
            impLetra(5, 1, 'E');
            impLetra(6, 0, 'C');
            impLetra(6, 6, 'G');
            impLetra(6, 8, 'J');
            impLetra(7, 0, 'D');
            impLetra(8, 9, 'D');

        case 12:
            id == 12;
            linhas = 11;
            colunas = 11;
            contaLetras = 9;
            impLetra(0, 0, 'A');
            impLetra(0, 1, 'D');
            impLetra(1, 3, 'C');
            impLetra(1, 6, 'H');
            impLetra(1, 10, 'E');
            impLetra(2, 6, 'I');
            impLetra(2, 8, 'I');
            impLetra(2, 10, 'H');
            impLetra(5, 8, 'G');
            impLetra(6, 6, 'G');
            impLetra(6, 7, 'F');
            impLetra(8, 7, 'A');
            impLetra(9, 1, 'D');
            impLetra(9, 5, 'F');
            impLetra(9, 9, 'E');
            impLetra(10, 3, 'C');
    }
}

void impLetra (int xLetra, int yLetra, char letra)
{  
    tabuleiro[xLetra][yLetra] = letra;
}

void mostraTabuleiro (desenhaTabuleiro(id))
{
    cout << "[" << linha
         << "][" << coluna << "]";
    cout << tabuleiro[linhas][colunas] << endl;
}

void desenhaTabuleiro(int x, int y)
{
    // um array com x linhas e y colunas.
    int tabuleiro[linhas][colunas];
  
    // output de cada elemento do tabuleiro
    for (int x = 0; x < linhas; x++)
    {
        for (int y = 0; y < colunas; y++)
        {
            if (letra == NULL)
            {
                tabuleiro[linhas][colunas] = " . ";
            }

            else if (letra != NULL)
            {
                instanciaID(id);           
            }
        }
    }

    mostraTabuleiro(desenhaTabuleiro(id));
}

int main ()
{
    desenhaTabuleiro(1);
    mostraTabuleiro(desenhaTabuleiro());
    solucionaTabuleiro(desenhaTabuleiro());
    mostraTabuleiro(solucionaTabuleiro());
}