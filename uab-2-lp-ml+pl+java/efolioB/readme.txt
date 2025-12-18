------- eFólio B - Linguagens de Programação -------

Instituição: Universidade Aberta
Ano letivo:  2020/2021       
Autor: Rui Sousa (Nº 1901774)

----------------------------------------------------

Ficheiros:
	Executável	->	"eFolioB_DB_LP.pl"
	Base de Dados	->	"eFolioB_DB_LP.txt"	(atenção, se abrir com um editor de texto, escolher a linguagem 'Prolog' de forma a poder utilkizar as Syntax Highlightings.)
	Readme		->	"readme.txt"

----------------------------------------------------


INSTRUÇÕES DE INSTALAÇÃO (WINDOWS X64):


http://cygwin.com/install.html
	--> cliccar em "setup-x86 64.exe"	--> executar e seguir os passos
		--> na janela "Select Packages" escolher os "Package" seguintes:	gcc-core: GNU Compiler Collection (C, OpenMP)
											gcc-g++: GNU Compiler Collection (C++)
											gcc-obj: GNU Compiler Collection (Objective-C)
											gdb: The GNU Debugger
											make: The GNU version of the 'make' utility

http://www.gprolog.org/#download
	--> clicar em "Windows intel 64 bits auto-install setup (compiled under x86_64 / windows 7 with MinGW64 gcc under Cygwin)"	--> executar e seguir os passos
		--> com o GNU Prolog Console aberto clicar em "File"	--> "Change Dir..."
			--> aqui podemos usar a diretoria actual ou criar uma pasta que só será usada para os projetos prolog
				--> Criar o ficheiro "db.pl", usando um editor de texto



EXECUTAR O SOFTWARE 'PROLOG'

Executar o ficheiro 'efolioB_DB_LP.pl'
	--> digitar "[efolioB_DB_LP]."	-->"Enter"	(desta forma, temos a certeza que o ficheiro está compilado a pronto a ser utilizado)



INSTRUÇÕES PARA UTILIZAR AS FUNÇÕES:


listar_clientes:			listing(clientes).							-->"Enter"
					clientes(Nome, _, _).							-->"Enter"	-->digitar "a"
					
listar_cliente_bom:			clientes(Nome, _, 'aaa').						-->"Enter"	-->"Enter"
	
total_cliente_cidade:			clientes(Nome, 'Funchal', _).						-->"Enter"	-->"Enter"
					clientes(Nome, 'Aveiro', _).						-->"Enter"	-->digitar ";"	-->"Enter"
					clientes(Nome, 'Leiria', _).						-->"Enter"	-->"Enter"
					clientes(Nome, 'Caldas da Rainha', _).					-->"Enter"	-->"Enter"
					clientes(Nome, 'Coimbra', _).						-->"Enter"	-->"Enter"
					clientes(Nome, 'Sintra', _).						-->"Enter"	-->"Enter"

listar_cliente_vendas:			listing(vendas).										-->"Enter"

inventario_quantidade_stock:		inventario_quantidade_stock('Rato Otico').							-->"Enter"	
					inventario_quantidade_stock('CPU i9-9900k').							-->"Enter"	
						--> digitar "21." (quando é pedido para digitar a "Quantidade a inserir no stock: ")	-->"Enter"
					inventario_quantidade_stock('CPU i9-9900k').							-->"Enter"
					listing(artigo).										-->"Enter"
					listing(inventario).										-->"Enter"

artigo_verificar_abaixo_min_alerta:	artigo_verificar_abaixo_min_alerta('Disco Externo 2Gb').					-->"Enter"
					artigo_verificar_abaixo_min_alerta('LCD 15"').							-->"Enter"
					artigo_verificar_abaixo_min_alerta('Portatil Zen 5013').					-->"Enter"

venda_validar_artigo_cliente:		venda_validar_artigo_cliente('Rui', 'Rato Otico', 10).						-->"Enter"
					venda_validar_artigo_cliente('Rui', 'Rato Otico', 24).						-->"Enter"
					venda_validar_artigo_cliente('David', 'Rato Otico', 10).					-->"Enter"
					venda_validar_artigo_cliente('Rui', 'Rato Otico', 24).						-->"Enter"

inventario_atualiza_artigo:		inventario_atualiza_artigo('Rato Otico').							-->"Enter"	
						--> digitar "31." (quando é pedido para digitar a "Quantidade nova a inserir")		-->"Enter"
					listing(inventario).

venda_artigo_cliente:			venda_artigo_cliente.										-->"Enter"
						--> digitar "'Rui'." (quanto é pedido para introduzir o nome do cliente)		-->"Enter"
						--> digitar "´Rato Otico'." (quando é pedido o nome do artigo)				-->"Enter"
						--> digitar "7." (quando é pedido a quantidade que o cliente deseja comprar)		-->"Enter"
					venda_artigo_cliente.										-->"Enter"
						--> digitar "'David'." (quanto é pedido para introduzir o nome do cliente)		-->"Enter"
						--> digitar "'Rato Otico'." (quando é pedido o nome do artigo)				-->"Enter"
						--> digitar "26." (quando é pedido a quantidade que o cliente deseja comprar)		-->"Enter"
					venda_artigo_cliente.										-->"Enter"
						--> digitar "'David'." (quanto é pedido para introduzir o nome do cliente)		-->"Enter"
						--> digitar "'Rato Otico'." (quando é pedido o nome do artigo)				-->"Enter"
						--> digitar "7." (quando é pedido a quantidade que o cliente deseja comprar)		-->"Enter"
					listing(inventario).										-->"Enter"
					listing(vendas).										-->"Enter"

inventario_relatorio:			listing(inventario).										-->"Enter"