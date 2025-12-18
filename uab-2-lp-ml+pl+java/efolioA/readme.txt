----- eFólio A - Linguagens de Programação -----

Instituição: Universidade Aberta
Ano letivo:  2020/2021       
Autor: Rui Sousa (Nº 1901774)


Ficheiros:
	Executável	->	"eFolioA_LP.ml"
	Base de dados	->	"baseDados.txt"


Funções:
	'aplicaRisco'
	'lerBaseDados'

Como usar (caso tenha o Ocaml instalado):
-> Abrir o Ocaml.exe
	-> digitar 'cd "[path da pasta onde guardou os ficheiros (eFolioA.ml e baseDados.txt)]"'
		-> digitar '#use "eFolioA_LP.ml";;' --> {Enter}
			-> digitar 'lerBaseDados "baseDados.txt";;' --> {Enter}

Como usar (caso use um editor de texto, por exemplo o VSC):
-> Abrir o VSC
	-> Abrir o ficheiro "eFolioA_LP.ml"
		-> acresentar código: 	[nova linha 26] {digitar}	let ficheiro = "baseDados.txt" in
					[nova linha 27] {digitar}	   lerBaseDados ficheiro
			-> no "Terminal": digitar 'cd "[path da pasta onde guardou os ficheiros (eFolioA_LP.ml e baseDados.txt)]"' --> {Enter}
				-> para Compilar: digitar 'ocamlc -o eFolioA_LP eFolioA_LP.ml' --> {Enter}
					-> para Executar: digitar './eFolioA_LP' --> {Enter}

NOTA:
	Pode usar qualquer outro ficheiro como base de dados (desde que esteja formatado de forma idêntica ao fornecido)
	exemplo: 'nomeUtente|1|2|3|4|5|6|7|8|9|10' (cada parâmetro tem de estar separado pelo caracter '|')

	Parâmetros	1  -> tem N doencas		[int]
			2  -> toma N medicamento	[int]
			3  -> teve acidentes		[bool]
			4  -> tem doença restritiva	[bool]
			5  -> vive sozinho		[bool]
			6  -> é autónomo		[bool]
			7  -> praticou desporto		[bool]
			8  -> tem autonomia física	[bool]
			9  -> pratica caminhadas	[bool]
      			10 -> risco da proffisão 	[alto || medio || baixo]