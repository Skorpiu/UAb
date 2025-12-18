/*
* UC: 21071 - Introducao Inteligencia Artificial
*
* Aluno: 1900979 - Sergio Meren
* Descricao: Estrutura de dados do Jogo/Problema
*
*/

#include "TProcuras.h"

#define MAX_N 6
#define MAX_M 6

//Movimentacao no tabuleiro (assume diagonais)
int DIRS1[][2] = { {-1, -1}, {-1, 0}, {-1, 1},
				   { 0, -1},          { 0, 1},
				   { 1, -1}, { 1, 0}, { 1, 1} };

//Movimentacao no tabuleiro (sem diagonais)
int DIRS2[][2] = {           {-1, 0},
				   { 0, -1},          { 0, 1},
				             { 1, 0} };

class CJogo1 :
    public TProcuras
{
public:
    CJogo1(void);
    ~CJogo1(void);

    // Variaveis de estado
	int tabuleiro[MAX_N][MAX_M];
	
    // variaveis da instancia de jogo
    static int _N, _M, _K; 
    static int instancia[][MAX_N][MAX_M];

    static int dimensoes[][3];
    static int instID;

	//Array/vetor com valores inteiros do jogo

	//Jogador atual (1=Jogador1, 2=Jogador2)
	static int jogador;

	// Cria um objecto que e uma copia deste
	TProcuras* Duplicar(void);
    void Copiar(TProcuras*objecto);

	// Coloca o objecto no estado inicial da procura
    void SolucaoVazia(void); // Inicializar instancia

	// Coloca em sucessores a lista de objectos sucessores (sao alocados neste metodo e tem de ser apagados)
	// O custo nao necessita de ser preenchido, caso seja sempre unitario
	void Sucessores(TVector<TProcuras*>&sucessores, TVector<int>&custo);

	// Retorna verdade caso o estado actual seja um estado objectivo
    bool SolucaoCompleta(void); // verificar se atingiu a Solucao

	// Escrever informacao de debug sobre o objecto currente
	// (utilizar variavel TProcuras::debug para seleccionar o detalhe pretendido)
	void Debug(void);
    bool Distinto(TProcuras*estado);

    // Redefinir para poder utilizar os algoritmos informados
	// O custo desde o no inicial e tido em conta, esta funcao deve devolver o custo estimado
	// nunca sobre estimando, deste estado ate ao no final mais proximo (e um minimo)
	// chamar para actualiacao de avaliacoes
	int Heuristica(void);

    //Definicao de metodos adicionais/auxiliares
};