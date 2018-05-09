#include "Coordinate.h"
#include "IllegalCharException.h"

#include <iostream>
using namespace std;

//Coordinate::Coordinate(char token) : token(token)
//{
//}

Coordinate::Coordinate(size_t i, size_t j) : i(i), j(j)
{
}

//Coordinate & Coordinate::operator=(char token)
//{
//	if (token != '.' && token != 'X' && token != 'O')
//	{
//		throw IllegalCharException(token);
//	}
//	this->token = token;
//	return *this;
//}
//
//ostream & operator <<(ostream& out, Coordinate node) {
//	out << node.token;
//	return out;
//}