/*
 * 21093 - Programação por Objetos
 * E-Fólio Global
 *
 * 1901774 - Rui Sousa
 */

#include "Helpers.h"
#include <regex>

std::vector<std::string> split(const std::string str, const std::string regex_str)
{
	std::regex regexz(regex_str);
	std::vector < std::string > list(std::sregex_token_iterator(str.begin(), str.end(), regexz, -1), std::sregex_token_iterator());

	return list;
}