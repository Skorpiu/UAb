#include "SimpleResult.h"

SimpleResult::SimpleResult(bool success, std::string message)
{
	this->success = success;
	this->message = message;
}
