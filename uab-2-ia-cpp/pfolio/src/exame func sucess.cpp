
// Coloca em sucessores a lista de objectos sucessores (sao alocados neste metodo e tem de ser apagados)
// O custo nao necessita de ser preenchido, caso seja sempre unitario
void teste::Sucessores(TVector<TProcuras*>&sucessores, TVector<int>&custo)
{
    int saida=0;

    //Definicao da rotina de resolucao do problema, nao esquecer custo e heuristica (se aplicavel)
    //Pode ser um ciclo ou similar, ao resolver colocar saida=0

    //Funcao SolucaoObjetivo ira validar se o jogo chegou ao final 
    if(Objetivo()){
        //Duplica sucessores
        teste *sucessor = (teste*)Duplicar();

        //Realizar proxima jogada
        for (int x=0; x<n; x++)
        {
            for (int y=0; y<m; y++)
            {
                if tabuleiro [x][y] = NULL
                {
                    if player=1 { unidade = 'X'; }
                    else{ unidade = '0'; }

                    tabuleiro [x][y] = unidade;
                    break;
                }
            }
        }

        //Mudar de jogador
        teste->player=proximoJogador();

        //Validar se "cercou" o inimigo
        --
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
        teste::Sucessores(sucessores,custo);
        return;
    }
	
    teste::Sucessores(sucessores,custo);
} //Fim sucessores()