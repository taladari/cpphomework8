#include "IllegalCharException.h"

IllegalCharException::IllegalCharException(char token)
{
	this->token = token;
}

char IllegalCharException::theChar() const
{
	return this->token;
}
