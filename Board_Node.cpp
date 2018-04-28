#include "Board_Node.h"
#include "IllegalCharException.h"

Board_Node::Board_Node(char token)
{
	this->token = token;
}

Board_Node::Board_Node(size_t i, size_t j)
{
	this->i = i;
	this->j = j;
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

