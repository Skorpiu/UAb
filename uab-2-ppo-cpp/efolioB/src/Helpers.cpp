#include "Helpers.h"

std::string trim(const std::string& str)
{
    const auto whitespace = " \t";

    // Posição do primeiro caractere na string que não seja espaço
    const auto strStart = str.find_first_not_of(whitespace);

    // String vazia
    if (strStart == std::string::npos) {
        return "";
    }

    // Posição do último caractere na string que não seja espaço
    const auto strEnd = str.find_last_not_of(whitespace);

    // Cortamos a string, apenas queremos o conteúdo entre o primeiro
    // e o último caractere que não sejam espaços
    return str.substr(strStart, strEnd - strStart + 1);
}

Result<int> try_parse_int(std::string number_string)
{
    number_string = trim(number_string);

    std::stringstream convertor;
    int number;

    convertor << number_string;
    convertor >> number;

    if (convertor.fail())
    {
        return {false, "Numero invalido"};
    }

    return {true, "OK", number};
}

std::vector<std::string> split(const std::string& str, char delimiter)
{
    std::vector<std::string> parts;
    std::string split;
    std::istringstream ss(str);
    while (std::getline(ss, split, delimiter))
    {
        parts.push_back(trim(split));
    }
    return parts;
}

std::string get_nome_aleatorio()
{
    std::vector<std::string> nomes_proprios;
    std::vector<std::string> apelidos;

    nomes_proprios.emplace_back("Joao");
    nomes_proprios.emplace_back("Santiago");
    nomes_proprios.emplace_back("Martim");
    nomes_proprios.emplace_back("Rodrigo");
    nomes_proprios.emplace_back("Afonso");
    nomes_proprios.emplace_back("Francisco");
    nomes_proprios.emplace_back("Tiago");
    nomes_proprios.emplace_back("Diogo");
    nomes_proprios.emplace_back("Miguel");
    nomes_proprios.emplace_back("Tomas");
    nomes_proprios.emplace_back("Manuel");
    nomes_proprios.emplace_back("Leonel");
    nomes_proprios.emplace_back("Rui");

    apelidos.emplace_back("Silva");
    apelidos.emplace_back("Santos");
    apelidos.emplace_back("Ferreira");
    apelidos.emplace_back("Pereira");
    apelidos.emplace_back("Oliveira");
    apelidos.emplace_back("Costa");
    apelidos.emplace_back("Rodrigues");
    apelidos.emplace_back("Martins");
    apelidos.emplace_back("Jesus");
    apelidos.emplace_back("Sousa");
    apelidos.emplace_back("Fernandes");
    apelidos.emplace_back("Goncalves");
    apelidos.emplace_back("Gomes");
    apelidos.emplace_back("Lopes");
    apelidos.emplace_back("Marques");
    apelidos.emplace_back("Alves");
    apelidos.emplace_back("Almeida");
    apelidos.emplace_back("Ribeiro");
    apelidos.emplace_back("Pinto");
    apelidos.emplace_back("Carvalho");
    apelidos.emplace_back("Teixeira");

    const int index_nome = rand() % nomes_proprios.size();

    const int index_apelido = rand() % apelidos.size();

    return nomes_proprios.at(index_nome) + " " + apelidos.at(index_apelido);
}
