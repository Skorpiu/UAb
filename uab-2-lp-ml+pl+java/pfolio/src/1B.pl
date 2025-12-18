obter([],[],ListaC). 

obter([H1|T1],[H2|T2],[H3|T3]):- 
    obter_valor(H1,H2,H3), 
    obter(T1,T2,T3). 

obter_valor(H1,H2,Resultado):- 
    ((H1 > 0 and H2 > 0) -> Resultado is (H1+H2)/2; 
    Resultado is (H1+H2). 

run():- 
    ListaA = [1,7,-8,5,4], 
    ListaB = [9,6,3,-5,2], 
    obter(ListaA,ListaB,ListaC), 
    write(ListaC).