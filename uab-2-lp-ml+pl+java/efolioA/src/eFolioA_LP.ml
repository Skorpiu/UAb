(*
----- eFólio A - Linguagens de Programação -----

NOTA: 
      1  -> tem N doencas           [int]
      2  -> toma N medicamento      [int]
      3  -> teve acidentes          [bool]
      4  -> tem doença restritiva   [bool]
      5  -> vive sozinho            [bool]
      6  -> é autónomo              [bool]
      7  -> praticou desporto       [bool]
      8  -> tem autonomia física    [bool]
      9  -> pratica caminhadas      [bool]
      10 -> risco da profissão      [alto || medio || baixo]
      
Instituição: Universidade Aberta
Ano letivo:  2020/2021       
Autor: Rui Sousa (Nº 1901774)
*)

(* Função que verifica o risco de cada indivíduo *)
(* recurso: https://medium.com/arena-tech-blog/ocaml-operators-cheatsheet-d9a33bb39072 *)
(* recurso: https://ocaml.org/manual/ *)
(* recurso: http://xahlee.info/ocaml/ocaml_basics.html *)
let aplicaRisco linha =
  let atributos = String.split_on_char '|' linha in     (* Aqui fazemos a separação de cada atributo, do utente, através do caracter '|' *)
    if
      int_of_string (List.nth atributos 1) > 2
      && int_of_string (List.nth atributos 2) > 3
      && (List.nth atributos 4 = "s")
      && (List.nth atributos 6 = "n")
      && (List.nth atributos 8 = "n")
      && (List.nth atributos 10 = "medio" || List.nth atributos 10 = "alto")
        then
          Printf.printf "|     %s     | Alto  |\n" (List.nth atributos 0)

    else if 
      int_of_string (List.nth atributos 1) < 3
      && int_of_string (List.nth atributos 2) < 4
      && (List.nth atributos 7 = "n")
      && (List.nth atributos 9 = "n")
      && (List.nth atributos 10 = "baixo" || List.nth atributos 10 = "medio")
        then
          Printf.printf "|     %s     | Médio |\n" (List.nth atributos 0)

    else if 
      int_of_string (List.nth atributos 1) = 0
      && int_of_string (List.nth atributos 2) < 3
      && (List.nth atributos 3 = "n")
      && (List.nth atributos 5 = "n")
      && (List.nth atributos 10 = "baixo")
        then
          Printf.printf "|     %s     | Baixo |\n" (List.nth atributos 0)

    else
      Printf.printf "|     %s     |  n.a. |\n" (List.nth atributos 0)

(* Função para ler ficheiro *)
(* recurso: https://www.youtube.com/watch?v=EM_c1BbwjZQ *)
let lerBaseDados file_name =

  Printf.printf "+--------------------------+\n";
  Printf.printf "| Lista de Utentes | Risco |\n";
  Printf.printf "+--------------------------+\n";

  let in_channel = open_in file_name in
  try
    while true do
      let linha = input_line in_channel in
        aplicaRisco linha;                            (* Aqui aplicamos a função principal 'aplicaRisco' a cada linha lida, do ficheiro 'baseDados.txt' *)
    done
  with End_of_file ->
    close_in in_channel;
    Printf.printf "+--------------------------+\n";;
(* Fim do Ficheiro *)