/*
* UC: 21071 - Introducao Inteligencia Artificial
*
* Aluno: 1900979 - Sergio Meren
* Descricao: Sucessores
*
*/

#include "CJogo1.h"

// Coloca em sucessores a lista de objectos sucessores (sao alocados neste metodo e tem de ser apagados)
// O custo nao necessita de ser preenchido, caso seja sempre unitario
void CJogo1::Sucessores(TVector<TProcuras*>&sucessores, TVector<int>&custo)
{
    int saida=0;

    //Definicao da rotina de resolucao do problema, nao esquecer custo e heuristica (se aplicavel)
    //Pode ser um ciclo ou similar, ao resolver colocar saida=0

    if(){
        //Duplica sucessores
        CJogo1 *sucessor = (CJogo1*)Duplicar();

        //Realizar proxima jogada
        //Mudar de jogador
        CJogo1->jogador=proximoJogador();

        //Validar se "cercou" o inimigo
        //Contabilizar pontos ganhos e adicionar ao score do jogador

        //Eliminar "cercados"
        
        //Adiciona sucessores
        sucessor->sucessores.Add();        
        sucessores.Add(sucessor);
        saida=1;
    } 
    else{
        saida=0;
    }

    //Saida
    if(saida==0){
        TProcuras::Sucessores(sucessores,custo);
        return;
    }
	
    TProcuras::Sucessores(sucessores,custo);
} //Fim sucessores()