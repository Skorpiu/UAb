/****************************
* Inteligência Artificial	*
*	Rui Sousa				*
*	Nº 1901774				*
*	Data:	09-09-2021		*
*****************************/

class teste :
{
public:
    teste(void);
    ~teste(void);

	static int x=6, y=3;		
	int plataforma[x][y];				/* definição do tamanho da plataforma de jogo */
	
	static int player;					/* para o caso de haver mais de 2 jogadores (1=playerOne, 2=playerTwo, etc...) */
	int contagemX, contagemO;			/* contagem de símbolos X e 0, respetivamente */

	/*	utilizando o algoritmo disponibilizado pelo professor:
		coloca em sucessores a lista de objectos sucessores (sao alocados neste metodo e tem de ser apagados)
		o custo nao necessita de ser preenchido, custo é constante, custo é nulo */
	void funcSucess(vetor<searchTree*>&sucessores, vetor<int>&custo);
};