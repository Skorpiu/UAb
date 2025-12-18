#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <vector>
#include "Result.h"

/// <summary>
/// Limpa os espaços no início e no fim de uma string
/// </summary>
/// <param name="str">String a limpar</param>
/// <returns>String original, sem espaços no inicio nem no fim</returns>
std::string trim(const std::string& str);

/// <summary>
/// Converte um número de string para int
/// </summary>
/// <param name="number_string">String com o número a converter</param>
/// <returns>
/// Classe Result com o resultado da conversão. 
/// Se a conversão foi efetuada com sucesso, 
/// é preenchida a propriedade result com o valor
/// </returns>
Result<int> try_parse_int(std::string number_string);

/// <summary>
/// Divide uma string em partes, utilizado o delimitador, e coloca as partes num vetor
/// </summary>
/// <param name="s">String a dividir</param>
/// <param name="delimiter">Delimitador a utilizar para fazer a divisão</param>
/// <returns>
/// Vetor com as partes da string divididas
/// </returns>
std::vector<std::string> split(const std::string& s, char delimiter = ',');

/// <summary>
/// Encontra o índice no vetor de um elemento que corresponda ao predicado
/// </summary>
/// <typeparam name="T">Tipo de dados do vetor</typeparam>
/// <param name="vec">Vetor a procurar</param>
/// <param name="f">Predicado a utilizar contra cada elemento do vetor</param>
/// <returns>Índice do primeiro elemento que corresponde ao predicado, ou -1 se não encontrou</returns>
template <class T>
int find_index(const std::vector<T> vec, const std::function <bool(T)>& f);

template<class T>
inline int find_index(const std::vector<T> vec, const std::function<bool(T)>& f)
{
	auto it = std::find_if(vec.begin(), vec.end(), f);

	if (it != vec.end()) {
		return std::distance(vec.begin(), it);
	}

	return -1;
}

/// <summary>
/// Recebe um vetor e devolve um item aleatório deste vetor
/// </summary>
template <class T>
T get_random_element(const std::vector<T> vec)
{
	const int index = rand() % vec.size();

	return vec.at(index);
}

/// <summary>
/// Gera e devolve um nome + apelido aleatório
/// </summary>
std::string get_nome_aleatorio();
