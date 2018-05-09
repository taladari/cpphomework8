#include "Token.h"
#include "IllegalCharException.h"


Token::Token(char tok) {
	_tok = tok;
	this->Object = tok;
}

Token& Token::operator=(char token) {
	if (token != '.' && token != 'O' && token != 'X')
	{
		throw IllegalCharException(token);
	}
	_tok = token;
	this->Object = token;
	return *this;
}

ostream& operator<<(ostream& os, const Token& tok) {
	os << tok._tok;
	return os;
}

bool Token::operator==(char other) const {
	return other == this->_tok || other == this->Object;
}