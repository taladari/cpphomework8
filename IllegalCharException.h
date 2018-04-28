#pragma once

#include <exception>

using namespace std;

class IllegalCharException : public exception
{
public:
	IllegalCharException(char token);
	char theChar() const;

private:
	char token;
};