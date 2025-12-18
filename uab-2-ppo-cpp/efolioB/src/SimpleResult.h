#pragma once
#include <iostream>

class SimpleResult
{
public:
	SimpleResult() = default;
	SimpleResult(bool success, std::string message);
	
	// Esta é uma classe básica para controlar o resultado de uma operação,
	// não vejo necessidade de implementar getters e setters
	bool success;
	std::string message;
};