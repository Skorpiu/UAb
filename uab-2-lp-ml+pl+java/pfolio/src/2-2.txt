teste_covid('Artur', '12 Jan 21', 'Negativo', 'PCR').
teste_covid('Inácio', '01 Abr 21', 'Positivo', 'Sorologico').
teste_covid('Augusto', '31 Mar 21', 'Positivo', 'Sorologico').
teste_covid('Tião', '17 Fev 21', 'Negativo', 'Sorologico').
teste_covid('Fontes', '10 Mai 21', 'Negativo', 'PCR').
teste_covid('Valverde', '22 Jun 21', 'Positivo', 'PCR').

testes_positivos(X,Y,L):-
    findall(X, teste_covid(_,X,'Positivo',_), L),
    write(L).