#pragma once
#include <string>
#include "SimpleResult.h"

// Nesta classe excepcionalmente, como tem um template, tenho de ter a definição e a implementação
// dos membros dentro do mesmo ficheiro

template <typename T>
class Result : public SimpleResult
{
public:
	Result(const bool success, std::string message) : SimpleResult(success, message)
	{
	}

	Result(bool success, std::string message, T result) : Result(success, message)
	{
		this->result = result;
	}

	T result;
};