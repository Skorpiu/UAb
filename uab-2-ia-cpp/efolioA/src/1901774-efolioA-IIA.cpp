/*
+-------+---------------------------+
|   ID  |         INSTÂNCIA         |
+-------+---------------------------+
|       |   A B .                   |
|   1   |   . . .                   |
|       |   . A B                   |
+-------+---------------------------+
|       |   A . B                   |
|   2   |   . . .                   |
|       |   B . A                   |
+-------+---------------------------+
|       |   A B . C D .             |
|   3   |   . . . . . .             |
|       |   . A B . C D             |
+-------+---------------------------+
|       |   A B . . C D . . . .     |
|   4   |   . . . . . . . . . .     |
|       |   . . . . . . . . . .     |
|       |   . . . A B . . . C D     |
+-------+---------------------------+
|       |   . . . . . . . . . .     |
|   5   |   . . A . . . . B . .     |
|       |   . . B . C D . A . .     |
|       |   C . . . . . . . . D     |
+-------+---------------------------+
|       |   D . . . . . . . . C     |
|   6   |   . . A . . . . B . .     |
|       |   . . B . . . . A . .     |
|       |   C . . . . . . . . D     |
+-------+---------------------------+  
|       |   C . . . . . . . . .     |
|       |   . . . . . D . B A .     |
|   7   |   . . . . . . . . . .     |
|       |   . D A . . . . . . .     |
|       |   . E . . . B . . E .     |
|       |   . . . . . . C . . .     |
+-------+---------------------------+
|       |   . . . . . . . . . .     |
|       |   . . A . . . . B . .     |
|       |   . . B . C D . A . .     |
|   8   |   C . . . . . . . . D     |
|       |   . . . . . . . . . .     |
|       |   . . E . . . . F . .     |
|       |   . . F . G H . E . .     |
|       |   G . . . . . . . . H     |
+-------+---------------------------+
|       |   . . . D . . .           |
|       |   . C . . B E .           |
|       |   . . . C A . .           |
|   9   |   . . . E . . .           |
|       |   . . . . . . .           |
|       |   . . A . . . .           |
|       |   B . . . D . .           |
+-------+---------------------------+
|       |   . . . . . . . . .       |
|       |   . . . B C . . D .       |
|       |   . . . . . D . E .       |
|       |   . . . . . . . . .       |
|   10  |   . . . . F . E . G       |
|       |   . . . . . . . . .       |
|       |   . . . . . . . . .       |
|       |   . . . . . . H . .       |
|       |   A B C A H F . . G       |
+-------+---------------------------+
|       |   . . . . . . . . . .     |
|       |   A . . B A . H I . .     |
|       |   . . . . . . . . I .     |
|       |   . . . G . . F . E .     |
|   11  |   . . F . . H . . J C     |
|       |   B E . . . . . . . .     |
|       |   C . . . . . G . J .     |
|       |   D . . . . . . . . .     |
|       |   . . . . . . . . . D     |
|       |   . . . . . . . . . .     |
+-------+---------------------------+
|       |   A D . . . . . . . . .   |
|       |   . . . C . . H . . . E   |
|       |   . . . . . . I . I . H   |
|       |   . . . . . . . . . . .   |
|       |   . . . . . . . . . . .   |
|   12  |   . . . . . . . . G . .   |
|       |   . . . . . . G F . . .   |
|       |   . . . . . . . . . . .   |
|       |   . . . . . . . A . . .   |
|       |   . D . . . F . . . E .   |
|       |   . . . C . . . . . . .   |
+-------+---------------------------+
*/

/*  Descrição: Código do jogo Numbers Links */
/*	Criador: Vaibhav Agarwal (vaiagarwal96@iitkgp.ac.in) */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node
{
	struct Node *pai;
	int rank;
	int numCaminho;
	int endpoint;
};
typedef struct Node node;

/*    Nome: iniciaTabuleiro()
      Input: 2D-array de ponteiros, tamanho do array linha/coluna
      Output: --void--
      Description: Inicializa uma tabela de ponteiros. */
void iniciaTabuleiro(node ***arr, int t)
{
	int n, m;
	for (n=0;n<t;n++){
		for (m=0;m<t;m++){
			node *tab;
			tab = (node *)malloc(sizeof(node));
			tab->rank = 0;
			tab->pai = NULL;
			tab->numCaminho = 0;
			tab->endpoint = 0;
			arr[n][m] = tab;
		}
	}
}
/***********************/

/*    Name: encontraPar()
      Input: um nó
      Output: ponteiro a qual o nó pertence
      Description: Pega no nó e retorna o ponteiro do seu par. */
node *encontraPar(node *t)
{
	if (t->pai != NULL)
		t = t->pai;
	return t;
}
/************************/

/*    Name: unirPar()
      Input: nós x e y
      Output: --void--
      Description: une os dois pares que contêm x and y.
*/
void unirPar(node *x, node *y)
{
	x = encontraPar(x);
	y = encontraPar(y);
	if (x->rank > y->rank)
		y->pai = x;
	else{
		x->pai = y;
		if(x->rank == y->rank)
			y->rank++;
	}
}
/**************************/

/*    Name: vizinhos()
      Input: tamanho do array linha/coluna, 2D-array de ponteiros
      Output: retorna os valores encriptados de k1 e k2 ou -1 se falhar.
      Description: Encontra os pontos de partida do fluxo. */
int vizinhos(int t, node ***arr)
{
	int n1, n2, m1, m2, contador = 0, flag = 0, a, b,k2;
	int k = rand()%(t*t);
	while (contador < (t*t)){
		k %= (t*t);
		n1 = k/t;
		m1 = k%t;

		if (arr[n1][m1]->numCaminho==0)
		{
			int kk = rand()%4;
			int cc = 0;
			switch (kk)
			{
				case 0: n2= n1-1;
						m2= m1-0;
						if(n2>=0 && n2<t && m2<t){
							if(arr[n2][m2]->numCaminho==0){
								flag=1;
								break;
							}
						}
						cc++;

				case 1:	n2= n1-0;
						m2= m1-1;
						if(m2>=0 && n2<t && m2<t){
							if(arr[n2][m2]->numCaminho==0){
								flag=1;
								break;
							}
						}
						cc++;

				case 2: n2= n1+1;
						m2= m1-0;
						if(n2<t && m2<t){
							if(arr[n2][m2]->numCaminho==0){
								flag=1;
								break;
							}
						}
						cc++;

				case 3: n2= n1-0;
						m2= m1+1;
						if(n2<t && m2<t){
							if(arr[n2][m2]->numCaminho==0){
								flag=1;
								break;
							}
						}
						cc++;


				case 4: if(cc==4)
							break;
						n2= n1-1;
						m2= m1-0;
						if(n2>=0 && n2<t && m2<t){
							if(arr[n2][m2]->numCaminho==0){
								flag=1;
								break;
							}
						}
						cc++;

				case 5: if(cc==4)
							break;
						n2= n1-0;
						m2= m1-1;
						if(m2>=0 && n2<t && m2<t){
						if(arr[n2][m2]->numCaminho==0){
								flag=1;
								break;
							}
						}
						cc++;

				case 6: if(cc==4)
							break;
						n2= n1+1;
						m2= m1-0;
						if(n2<t && m2<t){
							if(arr[n2][m2]->numCaminho==0){
								flag=1;
								break;
							}
						}
						cc++;

				case 7: if(cc==4)
							break;
						n2= n1-0;
						m2= m1+1;
						if(n2<t && m2<t){
							if(arr[n2][m2]->numCaminho==0){
								flag=1;
								break;
							}
						}
						cc++;
			}
		}
		if(flag==1)
			break;

		contador++;
		k++;
	}

	if(contador<t*t){
		k2= (n2*t)+m2;
		return k*(t*t)+k2;
	}
	else{
		return -1;
	}
}
/************************/

/*    Name: verificaVizinhos()
      Input: k1, k2, tamanho do array linha/coluna, 2D-array de ponteiros
      Output: retorna um escolha booleana: 1 se verdadeiro, 0 se falso.
      Description: Verifica os vizinhos nos 4 lados e encontra se houver mais de 1 vizinho para o mesmo par.
*/
int verificaVizinhos(int k1, int k2, int t, node ***arr)
{
	int n= k2/t;
	int m= k2%t;
	int nn= k1/t;
	int mm= k1%t;

	int contador=0;
	if(n>0 && encontraPar(arr[n-1][m])==encontraPar(arr[nn][mm]))   //verifica Oeste
		contador++;
	if(n<t-1 && encontraPar(arr[n+1][m])==encontraPar(arr[nn][mm])) //verifica Este
		contador++;
	if(m>0 && encontraPar(arr[n][m-1])==encontraPar(arr[nn][mm]))   //verifica Norte
		contador++;
	if(m<t-1 && encontraPar(arr[n][m+1])==encontraPar(arr[nn][mm])) //verifica Sul
		contador++;

	if(contador>1)
		return 0;
	else
		return 1;
}
/****************************/

/*    Name: encontraProximo()
      Input: começa em k, tamanho do array linha/coluna, 2D-array de ponteiros
      Output: retorna o valor de k2 ou -1 se falhar.
      Description: Encontra as próximas coordenadas válidas, do fluxo.
*/
int encontraProximo(int k, int t, node ***arr)
{
	int n1, n2, m1, m2, a, b, kk, stat, contador=0;
	int flag=0;
	n1= k/t;
	m1= k%t;
	kk= rand()%4;
	switch(kk)
	{
		case 0: n2= n1-1;
				m2= m1-0;
				if(n2>=0 && n2<t && m2<t){
					if(arr[n2][m2]->numCaminho==0){
						stat= verificaVizinhos(k, (t*n2 + m2), t, arr);
						//printf("%d\n",stat);
						if(stat){
							flag=1;
							break;
						}
					}
				}
				contador++;

		case 1:	n2= n1-0;
				m2= m1-1;
				if(m2>=0 && n2<t && m2<t){
					if(arr[n2][m2]->numCaminho==0){
						stat= verificaVizinhos(k, (t*n2 + m2), t, arr);
						//printf("%d\n",stat);
						if(stat){
							flag=1;
							break;
						}
					}
				}
				contador++;

		case 2: n2= n1+1;
				m2= m1-0;
				if(n2<t && m2<t){
					if(arr[n2][m2]->numCaminho==0){
						stat= verificaVizinhos(k, (t*n2 + m2), t, arr);
						//printf("%d\n",stat);
						if(stat){
							flag=1;
							break;
						}
					}
				}
				contador++;

		case 3: n2= n1-0;
				m2= m1+1;
				if(n2<t && m2<t){
				if(arr[n2][m2]->numCaminho==0){
						stat= verificaVizinhos(k, (t*n2 + m2), t, arr);
						//printf("%d\n",stat);
						if(stat){
							flag=1;
							break;
						}
					}
				}
				contador++;

		case 4: if(contador==4)
					break;
				n2= n1-1;
				m2= m1-0;
				if(n2>=0 && n2<t && m2<t){
					if(arr[n2][m2]->numCaminho==0){
						stat= verificaVizinhos(k, (t*n2 + m2), t, arr);
						//printf("%d\n",stat);
						if(stat){
							flag=1;
							break;
						}
					}
				}
				contador++;

		case 5:	if(contador==4)
					break;
				n2= n1-0;
				m2= m1-1;
				if(m2>=0 && n2<t && m2<t){
					if(arr[n2][m2]->numCaminho==0){
						stat= verificaVizinhos(k, (t*n2 + m2), t, arr);
						//printf("%d\n",stat);
						if(stat){
							flag=1;
							break;
						}
					}
				}
				contador++;

		case 6: if(contador==4)
					break;
				n2= n1+1;
				m2= m1-0;
				if(n2<t && m2<t){
					if(arr[n2][m2]->numCaminho==0){
						stat= verificaVizinhos(k, (t*n2 + m2), t, arr);
						//printf("%d\n",stat);
						if(stat){
							flag=1;
							break;
						}
					}
				}
				contador++;

		case 7: if(contador==4)
					break;
				n2= n1-0;
				m2= m1+1;
				if(n2<t && m2<t){
				if(arr[n2][m2]->numCaminho==0){
						stat= verificaVizinhos(k, (t*n2 + m2), t, arr);
						//printf("%d\n",stat);
						if(stat){
							flag=1;
							break;
						}
					}
				}
				contador++;

	}
	//printf("flag- %d\n",flag);
	if(flag==0)
		return -1;
	if(flag){
		//printf("value sent- %d\n", n2*t + m2);
		return (n2*t)+m2;
	 }
}
/********************/

/*    Name: adicionaCaminho()
      Input: 2D-array de ponteiros, tamanho do array linha/coluna, numero do caminho
      Output: retorna 1 se um novo caminho pode ser (ou é) adicionado, 0 se não.
      Description: Cria um novo caminho de fluxo.
*/
int adicionaCaminho(node ***arr, int t, int cmNo)
{

	int a,b,k1,k2;
	int n1,m1,n2,m2;
	k2= vizinhos( t, arr);

	if(k2==-1)         //não existe um par válido para começar
		return 0;


	k1= k2/(t*t);
	k2= k2%(t*t);
	//printf("%d %d\n",k1,k2);

	n1= k1/t;
	m1= k1%t;
	n2= k2/t;
	m2= k2%t;
	//printf("%d %d\n",n1,m1);
	//printf("%d %d\n",n2,m2);

	//encontrámos n1,m1 and n2,m2
	arr[n1][m1]->endpoint= 1;

	arr[n2][m2]->numCaminho= cmNo;
	arr[n1][m1]->numCaminho= cmNo;


	node *t1, *t2;
	t1= arr[n1][m1];
	t2= arr[n2][m2];
	t1= encontraPar(t1);
	t2= encontraPar(t2);
	unirPar(t1, t2);

	while(1){
		n1= n2;
		m1= m2;
		k1= (n1*t)+m1;

		/******/
		k2= encontraProximo(k1, t, arr);
		//printf("k2- %d\n",k2);

		if(k2==-1){
			arr[n1][m1]->endpoint= 1;
			break;
		}

		n2=k2/t;
		m2=k2%t;
		//printf("%d %d\n",i2,j2);
		arr[n2][m2]->numCaminho= cmNo;
		node *t1, *t2;
		t1= arr[n1][m1];
		t2= arr[n2][m2];
		t1= encontraPar(t1);
		t2= encontraPar(t2);
		unirPar(t1,t2);
	}
	return 1;
}
/************************/

/*    Name: desenhaTabuleiro()
      Input:  2D-array de ponteiros, tamanho do array linha/coluna
      Output: --void--
      Description: Imprime o tabuleiro inicial e o tabuleiro com a solução.
*/
void desenhaTabuleiro(node ***arr, int t)
{
	int n, m;
	printf("Tabuleiro inicial:\n");
	for(n=0;n<t;n++){
		for(m=0;m<t;m++){
			if(arr[n][m]->endpoint ==1){
				if(arr[n][m]->numCaminho/10==0)
					printf("| %d |", arr[n][m]->numCaminho);
				else
					printf("| %d|", arr[n][m]->numCaminho);
			}
			else if(arr[n][m]->numCaminho==0)
				printf("| # |");
			else
				printf("| . |");
		}
		printf("\n");
	}
	printf("\n\nA solução da tabela acima, é a seguinte:\n");
	for(n=0;n<t;n++){
		for(m=0;m<t;m++){
			if(arr[n][m]->numCaminho != 0){
				if(arr[n][m]->numCaminho/10==0)
					printf("| %d |", arr[n][m]->numCaminho);
				else
					printf("| %d|", arr[n][m]->numCaminho);
			}
			else
				printf("| X |");
		}
		printf("\n");
	}
}
/******************/

/*    Name: main()
      Input:  --void--
      Output: retorna 1
      Description: Função main.
*/
int main(void)
{
	srand((unsigned int) time (NULL));
	int n, m;
	int contador = 1;

    // Tamanho do tabuleiro
	int t = 7;

	node*** ponteiros= (node ***)malloc(t*sizeof(node **));
	for (n=0; n<t; n++)
  		ponteiros[n] = (node **)malloc(t*sizeof(node *));

	iniciaTabuleiro(ponteiros, t);


	while(1) {
		n = adicionaCaminho(ponteiros, t, contador);
		if (n==0){
			//printf("Falha\n");
			break;
		}
		else {
			contador++;
			//printf("Sucesso\n");
	    }
	}
	desenhaTabuleiro(ponteiros, t);

	return 0;
}
/**********EOF**********/