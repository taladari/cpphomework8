#pragma once  

#include "CharWrapper.h"

#include <iostream>
using namespace std;

class Token : public CharWrapper<char>{
public:
	char _tok;
	Token(char tok);
	Token& operator=(char token);
	friend ostream& operator<<(ostream& os, const Token& tok);
	bool operator ==(char other);

private:
	
};
