:- dynamic(clientes/3).
:- dynamic(artigo/3).
:- dynamic(inventario/2).
:- dynamic(vendas/3).

clientes('Daniel', 'Funchal', 'xxx').
clientes('David', 'Aveiro', 'aaa').
clientes('Rui', 'Aveiro', 'bbb').
clientes('Julia', 'Leiria', 'xxx').
clientes('Jose', 'Caldas da Rainha', 'xxx').
clientes('Tomas', 'Coimbra', 'xxx').
clientes('Americo', 'Sintra', 'xxx').

artigo('a1', 'Rato Otico', 10).
artigo('a2', 'Teclado sem Fios', 10).
artigo('a3', 'LCD 15"', 10).
artigo('a4', 'Portatil Zen 5013', 10).
artigo('a5', 'Portatil Zen 5050', 10).
artigo('a6', 'Pen 512Mb Blue', 10).
artigo('a7', 'Disco Externo 2Gb', 10).

inventario('a1', 10).
inventario('a2', 10).
inventario('a3', 10).
inventario('a4', 78).
inventario('a5', 23).
inventario('a6', 14).
inventario('a7', 8).

vendas('Daniel', 'a1', 12).
vendas('Americo', 'a4', 1).

/*
INPUT:  inventario_quantidade_stock('Rato Otico').
INPUT:  inventario_quantidade_stock('CPU i9-9900k').
            --> digitar "26." (quando é pedido para digitar a "Quantidade a inserir no stock: ")
        inventario_quantidade_stock('CPU i9-9900k').
        listing(artigo).
        listing(inventario).
*/
inventario_quantidade_stock(Artigo) :- 
    artigo(Referencia, Artigo, _),
    inventario(Referencia, Quantidade),
    format('~nReferencia: ~w~nArtigo: ~w~nQuantidade: ~w', [Referencia, Artigo, Quantidade]),
    !, true.
inventario_quantidade_stock(Artigo) :-
    findall(Referencia, artigo(Referencia,_,_), L),    /* contar numero de referencias existentes e guarda numa lista L */
    length(L, X),                                      /* contar numero de elementos da lista L e guarda na variavel X */
    M is X + 1,                                        /* incrementar uma referencia */
    number_atom(M, N),
    atom_concat('a', N, Nova_Referencia),              /* cria uma nova referência para o novo artigo */
    assertz(artigo(Nova_Referencia, Artigo, 10)),
    format('~nQuantidade de ~w, a inserir no stock: ', [Artigo]),
    read(Novo_Artigo_Quantidade), 
    assertz(inventario(Nova_Referencia, Novo_Artigo_Quantidade)),
    format('~nReferencia: ~w~nArtigo: ~w~nQuantidade: ~w', [Nova_Referencia, Artigo, Novo_Artigo_Quantidade]),
    !, false.

/*
INPUT:  artigo_verificar_abaixo_min_alerta('Disco Externo 2Gb').
INPUT:  artigo_verificar_abaixo_min_alerta('LCD 15"').
INPUT:  artigo_verificar_abaixo_min_alerta('Portatil Zen 5013').
*/
artigo_verificar_abaixo_min_alerta(Artigo) :-
    artigo(Referencia, Artigo, Quantidade_min_alerta),
    inventario(Referencia, Quantidade),
    Quantidade < Quantidade_min_alerta,
    format('~nALERTA!!!~nStock do artigo: ~w, esta abaixo do limite minimo, ja so existem ~w unidades!', [Artigo, Quantidade]), !.
artigo_verificar_abaixo_min_alerta(Artigo) :-
    artigo(Referencia, Artigo, Quantidade_min_alerta),
    inventario(Referencia, Quantidade),
    Quantidade > Quantidade_min_alerta,
    X is Quantidade - Quantidade_min_alerta,
    format('~nStock do artigo: ~w, esta acima ~w unidades do limite minimo!', [Artigo, X]), !.
artigo_verificar_abaixo_min_alerta(Artigo) :-
    artigo(Referencia, Artigo, Quantidade_min_alerta),
    inventario(Referencia, Quantidade),
    Quantidade =:= Quantidade_min_alerta,
    format('~nStock do artigo: ~w, esta no limite minimo, existem exatamente ~w unidades!', [Artigo, Quantidade_min_alerta]), !.

/*
INPUT:  venda_validar_artigo_cliente('Rui', 'Rato Otico', 10).
INPUT:  venda_validar_artigo_cliente('Rui', 'Rato Otico', 24).
INPUT:  venda_validar_artigo_cliente('David', 'Rato Otico', 10).
INPUT:  venda_validar_artigo_cliente('David', 'Rato Otico', 24).
*/
venda_validar_artigo_cliente(Nome, Artigo, Quantidade_a_comprar) :-
    artigo(Referencia, Artigo,_),
    inventario(Referencia, Quantidade),
    (clientes(Nome,_,'aaa'),
    Quantidade_a_comprar =< Quantidade),
    format('~nCliente: ~w~nArtigo: ~w~nReferencia: ~w ~nCliente: ~w ~nFinalizar Venda!', [Nome, Artigo, Referencia, Quantidade]), !, true;
    (clientes(Nome,_,'bbb');
    clientes(Nome,_,'xxx')),
    format('~nCliente: ~w~nArtigo: ~w~nReferencia: ~w~nQuantidade: ~w~nFalha!~nCliente deve, primeiro, regularizar as contas em atraso.', [Nome, Artigo, Referencia, Quantidade]), !, false;
    (Quantidade_a_comprar > Quantidade),
    format('~nCliente: ~w~nArtigo: ~w~nReferencia: ~w~nQuantidade: ~w~nFalha!~nSem stock!', [Nome, Artigo, Referencia, Quantidade]), !, false.

/*
INPUT:  inventario_atualiza_artigo('Rato Otico').
            --> digitar "31." (quando é pedido para digitar a "Quantidade nova a inserir")  
        listing(inventario).
*/
inventario_atualiza_artigo(Artigo) :-
    artigo(Referencia, Artigo,_),
    inventario(Referencia, Quantidade),
    retract(inventario(Referencia, _)),
    format('~nInsira a nova quantidade para~nArtigo: ~w~nReferencia: ~w~nQuantidade Anterior: ~w~n~nNova Quantidade: ', [Artigo, Referencia, Quantidade]),
    read(Quantidade_Nova_Stock),
    assertz(inventario(Referencia, Quantidade_Nova_Stock)),
    format('~n~nATUALIZACAO~nArtigo: ~w~nReferencia: ~w~nQuantidade: ~w', [Artigo, Referencia, Quantidade_Nova_Stock]).

/*
INPUT:  venda_artigo_cliente.
            --> digitar "'Rui'." (quanto é pedido para introduzir o nome do cliente)
            --> digitar "'Rato Otico'." (quando é pedido o nome do artigo)
            --> digitar "7." (quando é pedido a quantidade que o cliente deseja comprar)
INPUT:  venda_artigo_cliente.
            --> digitar "'David'." (quanto é pedido para introduzir o nome do cliente)
            --> digitar "'Rato Otico'." (quando é pedido o nome do artigo)
            --> digitar "26." (quando é pedido a quantidade que o cliente deseja comprar)
INPUT:  venda_artigo_cliente.
            --> digitar "'David'." (quanto é pedido para introduzir o nome do cliente)
            --> digitar "'Rato Otico'." (quando é pedido o nome do artigo)
            --> digitar "7." (quando é pedido a quantidade que o cliente deseja comprar)
        listing(inventario).
        listing(vendas).
*/
venda_artigo_cliente :-
    write('Introduza o nome do cliente: '),
    read(Nome), nl,
    write('Introduza o nome do artigo: '),
    read(Artigo), nl,
    write('Insira a quantidade que o cliente deseja comprar: '),
    read(Quantidade_a_comprar), nl,
    (clientes(Nome,_,'aaa'),
    artigo(Referencia, Artigo,_),
    inventario(Referencia, Quantidade),
    Quantidade_a_comprar =< Quantidade,
    retract(inventario(Referencia, _)),
    Quantidade_Nova_Stock is Quantidade - Quantidade_a_comprar,
    assertz(inventario(Referencia, Quantidade_Nova_Stock)),
    assertz(vendas(Nome, Referencia, Quantidade_a_comprar)),
    format('~nCliente: ~w~nArtigo: ~w~nReferencia: ~w ~nCliente: ~w ~nVenda realizada com sucesso!', [Nome, Artigo, Referencia, Quantidade_a_comprar])), !, true;
    nl, write('Falha!'), !, false.

/*
------------------ Funções auxiliares de debugguing -------------------

write_ref(N) :-
    number_atom(N, A), atom_concat(A, 'a', R),
    write(R).

tam_List :-
    findall(Referencia, artigo(Referencia,_,_), List),
    write(List), nl,
    length(List, X),
    X1 is X + 1, 
    format('~w', [X1]).

*/
