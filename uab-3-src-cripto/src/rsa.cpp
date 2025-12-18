/*
||	Segurança em Redes e Computadores	||
||										         ||
||	Criptografia Assimétrica RSA		   ||
||										         ||
||	05-11-2021							      ||
||	Rui Sousa	(1901774)				   ||
*/

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

// função para encontrar o maior divisor comum (mdc)
int mdc(int a, int b)
{
   int t;
   while(1)
   {
      t = a % b;
      if(t == 0) return b;
      a = b;
      b = t;
   }
}

//Lista de números primos (dos 2 aos 90), serve de apoio ao utilizador 
void primos()
{
   int i, j, linhas = 3, colunas = 7;
   
   //Apresentação da tabela de primos ao utilizador
   cout << endl << (char) 201;
   for (i = 0; i <= 25; ++i){ cout << (char) 205; }
   cout << (char) 187;
   cout << endl << (char) 186 << " Tabela de numeros primos " << (char) 186 << endl << (char) 204;
   for (i = 0; i <= 25; ++i) { cout << (char) 205; }
   cout << (char) 185 << endl; 

   //Lista de números primos dos 10 ao 100
   int primos[linhas][colunas] = {{11, 13, 17, 19, 23, 29, 31}, {37, 41, 43, 47, 53, 59, 61}, {67, 71, 73, 79, 83, 89, 97}};

   for (i = 0; i < linhas; ++i)
   {
      if (i == 0)
      {
      cout << (char) 186 << "   ";
      for (j = 0; j <= colunas-1; ++j) { cout << primos[i][j] << " "; }
      cout << "  " << (char) 186 << endl;
      }
      else
      {
      cout << (char) 186 << "   ";
      for (j = 0; j <= colunas-1; ++j) { cout << primos[i][j] << " "; }
      cout << "  " << (char) 186 << endl;
      }
   }
   cout << (char) 200;
   for (i = 0; i <= 25; ++i) { cout << (char) 205; }
   cout << (char) 188 << endl << endl;
}

//Função que verifica se o número, introduzido pelo utilizador, é primo
bool isPrimo(int x)
{
   double Px, Py;

   for (int i = 2; i <= x / i; ++i)
   {
      if (x % i == 0)
      {
         if (x == Px)
         {
            cout << endl << "ERRO!" << endl << "Numero introduzido nao e primo!" << endl << endl;
            cout << "Por favor verifique a tabela dos Numeros Primos, insira um numero pertencente a tabela." << endl << endl;
            cout << endl << "Insira um numero primo: " << endl;
            cout << "Px: ";
            cin >> Px;
         }
         else if (x == Py)
         {
            cout << endl << "ERRO!" << endl << "Numero introduzido nao e primo!" << endl << endl;
            cout << "Por favor verifique a tabela dos Numeros Primos, insira um numero pertencente a tabela." << endl << endl;
            cout << endl << "Insira outro numero primo: " << endl;
            cout << "Py: ";
            cin >> Py;               
         }
         else { return false; }
      }
   }
   return true;
}

//verifica igualdade dos números primos, introduzidos pelo utilizador
double verificaIgualdadePrimos(double x, double y)
{
   double Py;

   if (y == x)
   {
      cout << endl << "ERRO!" << endl << "Numero introduzido igual a Px!" << endl << endl;
      cout << "Por favor introduza um numero primo, recorrendo a tabela, diferente de Px." << endl << endl;
      cout << "Py: ";
      cin >> Py;
   }

   return Py;
}

//Função que verifica o menor número de entre Px, Py, n e phi
double verificaMenorValor(double x, double y, double k, double l)
{
   double numLista[4] = {x, y, k, l};   
   double min = numLista[0];
   for (int i = 0; i < 4; i++)
   {
      if (numLista[i] < min) { min = numLista[i]; }
   }
   return min;
}

// Passa char para ascii e depois o int ascii para str
int toNum(char letra)
{
   return (unsigned int)letra;
}

int main()
{
   //Apresentação ao utilizador
   cout << endl << (char) 201;
   for (int i = 0; i <= 29; ++i){ cout << (char) 205; }
   cout << (char) 187;
   cout << endl << (char) 186 << " Algoritmo de encriptacao RSA " << (char) 186 << endl << (char) 200;
   for (int i = 0; i <= 29; ++i) { cout << (char) 205; }
   cout << (char) 188 << endl;

   //Inicializa as variaveis Px e Py, e verifica se são primos, caso contrário adverte o utilizador
   double Px, Py;
   primos();

   cout << "Insira um numero primo: " << endl;
   cout << "Px: ";
   cin >> Px;
   isPrimo(Px);

   cout << endl << "Insira outro numero primo: " << endl;
   cout << "Py: ";
   cin >> Py;
   isPrimo(Py);

   //Px e Py têm de ser diferentes, verifica igualdade
   verificaIgualdadePrimos(Px, Py);
   cout << endl << "Numeros primos inseridos:   Px = " << Px << ",   Py = " << Py << endl << endl;

   //Calcula n e phi
   double n, phi;
   n = Px * Py;
   phi = (Px - 1) * (Py - 1);

   //Public Key
   //Chave pública gerada aleatóriamente num determinado limite
   double e;
   e = verificaMenorValor(Px, Py, n, phi);

   //Verifica se 1 < e < phi(n) e mdc(e, phi(n)) = 1
   //i.e., e e phi(n) são co-primos.
   double track;
   
   while(e < phi)
   {
      track = mdc(e, phi);
      if(track == 1) { break; }
      else { e++; }
   }

   //Private Key
   //Escolhemos d de forma a que satisfaça a seguinte condição: d * e = 1 mod phi
   double d, dAux;
   dAux = 1 / e;
   d = fmod(dAux, phi);

   //Pede ao utilizador a mensagem que deseja encriptar/proteger
   string msgOriginal;

   cin.ignore();        //Sem este comando, o programa sai. Problema recorrente quando existe mais do que um 'cin' no mesmo código.

   cout << "Introduza a mensagem que deseja proteger: ";
   getline(cin, msgOriginal);
   cout << msgOriginal << endl;
   cout << endl;

   //Cria uma lista, onde se vão guardar todos os caracteres da mensagem, convertidos em inteiros.
   int size = msgOriginal.length();
   int mList[size];
   
   for(int i = 0; i < size; ++i) { mList[i] = toNum(msgOriginal[i]); }
   
   //Inicializa duas listas, uma onde guarda a mensagem encriptada e outra onde guarda a mensagem decifrada
   double c[size], m[size];

   for(int i = 0; i < size; ++i) { c[i] = pow(mList[i], e); }    //encripta a mensagem
   for(int i = 0; i < size; ++i) { m[i] = pow(c[i], d); }        //decifra a menssagem

   for(int i = 0; i < size; ++i) { c[i] = fmod(c[i], n); }
   for(int i = 0; i < size; ++i) { m[i] = fmod(m[i], n); }


   //Apresentação de resultados -> resumo
   cout << endl << (char) 201;
   for (int i = 0; i <= 7; ++i){ cout << (char) 205; }
   cout << (char) 187;
   cout << endl << (char) 186 << " Resumo " << (char) 186 << endl << (char) 200;
   for (int i = 0; i <= 7; ++i) { cout << (char) 205; }
   cout << (char) 188 << endl;

   cout << "Mensagem original = " << msgOriginal;
   cout << endl << "Numero primo Px: " << Px;
   cout << endl << "Numero primo Py: " << Py;
   cout << endl << "n = p * q = " << n;
   cout << endl << "phi = " << phi;
   cout << endl << "Chave publica: " << e;
   cout << endl << "Chave privada: " << d;
   cout << endl << "Mensagem encriptada: ";
   for (int i = 0; i <= size; ++i) { cout << c[i]; }
   cout << endl << "Mensagem decifrada: ";
   for (int i = 0; i <= size; ++i) { cout << (char)(m[i]); }
   cout << endl << endl << "Programa Terminado!";

   return 0;
}

//Fim