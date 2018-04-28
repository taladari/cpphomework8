#include "Board_Node.h"
#include "IllegalCharException.h"

Board_Node::Board_Node(char token) : token(token)
{
}

Board_Node::Board_Node(size_t i, size_t j) : i(i), j(j)
{
}

Board_Node & Board_Node::operator=(char token)
{
	if (token != '.' && token != 'X' && token != 'O')
	{
		throw IllegalCharException(token);
	}
	this->token = token;
	return *this;
}

