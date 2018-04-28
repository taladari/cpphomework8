#include "IllegalCharException.h"

IllegalCharException::IllegalCharException(char token) : token(token)
{
}

char IllegalCharException::theChar() const
{
	return this->token;
}
