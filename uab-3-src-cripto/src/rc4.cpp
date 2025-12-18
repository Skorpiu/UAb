/*
||	Segurança em Redes e Computadores	||
||										||
||	Criptografia Simétrica RC4			||
||										||
||	05-11-2021							||
||	Rui Sousa	(1901774)				||
*/

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

unsigned char s[256];
unsigned int i, j;
int size;
char *textOriginal;
char *enblock;

//Função que faz a troca dos elementos
void troca(unsigned char *s, unsigned int i, unsigned int j)
{
	unsigned char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

//Função que cria a chave de segurança (mensagem/chave de encriptação)
void rc4Input (unsigned char *pass, unsigned int keylen)
{
	for (i = 0; i < 256; i++) 
		s[i] = i;

	for (i = 0, j = 0; i < 256; i++)
	{
		j = (j + pass[i % keylen] + s[i]) % 256;
		troca(s, i , j);
	}
	i = 0;
	j = 0;
}

//Função que aplica os cálculos do algoritmo RC4
unsigned char rc4Output()
{
	i = (i + 1) % 256;
	j = (j + s[i]) % 256;
	troca(s, i, j);

	return s[(s[i] + s[j]) % 256];
}

int main()
{   
    //Inicialização das variáveis
	string mensagem, minhaKey;
	
	//Apresentação ao utilizador
	cout << endl << (char) 201;
	for (i = 0; i <= 29; ++i){ cout << (char) 205; }
	cout << (char) 187;
	cout << endl << (char) 186 << " Algoritmo de encriptacao RC4 " << (char) 186 << endl << (char) 200;
	for (i = 0; i <= 29; ++i) { cout << (char) 205; }
	cout << (char) 188 << endl;

	//Interação com o utilizador
    cout << endl << "Insira a menssagem que deseja encriptar: ";
    getline(cin, mensagem);
    cout << endl;

	cout << "Introduza a chave de seguranca: ";
	getline(cin, minhaKey);
	cout << endl;

	//Verifica se a password é demasiado comprida
	if (minhaKey.length() > 16)
	{
		cout << "ERRO!" << endl << "Chave demasiado comprida!" << endl;
		cout << "Por favor introduza uma chave ate 16 caracteres: ";
		getline(cin, minhaKey);
		cout << endl;	
	}

	//passa o conteúdo do apontador minhaKey para key, variável utilizada na encriptação e decifração
    unsigned char* key[16] = {(unsigned char*) minhaKey.c_str()};

    //Cria a chave de encriptação
	rc4Input(key[0], strlen((char*)key[0]));

	//Determina o tamanho da menssagem
	size = mensagem.length();

    //Cria blocos de memória e passa a mensagem para o bloco textOriginal
    textOriginal = new char [size];
    enblock = new char [size];
	strcpy(textOriginal, mensagem.c_str());

	//Menu
	int opcao;

	do
	{
		cout << "Selecione:" << endl << "1 - Encriptar Mensagem" << endl << "2 - Decifrar Mensagem" << endl << endl << "0 - Sair" << endl << endl << "Opcao: ";
		cin >> opcao;
		cout << endl;

		switch(opcao)
		{
			case 0:
				cout << "Programa terminado!" << endl << endl;
				
				return 0;

			case 1:
				//Encriptação
				for (int x = 0; x < size; x++) { enblock[x] = (textOriginal[x] ^ rc4Output()); }

				//Imprime a menssagem encriptada
				cout << "Menssagem encriptada: ";
				for (int x = 0; x < size; x++) { cout << enblock[x]; }
				cout << endl << endl;

				break;	

			case 2:
				//Reseta o array s, portanto s = vazio
				rc4Input(key[0], strlen((char*)key[0]));

				//Decifração
				for (int x = 0; x < size; x++) { enblock[x] = (enblock[x] ^ rc4Output()); }

				//Imprime a menssagem original
				cout << "Menssagem original: ";
				for (int x = 0; x < size; x++) { cout << enblock[x]; }
				cout << endl << endl;
			
				break;			
			
			default:
				cout << "Insira uma opcao valida: ";
		}
	}
	while(opcao != 0);

	//Libertar memória alocada
	delete[] textOriginal;
	delete[] enblock;

    return 0;
}

//Fim