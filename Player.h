#pragma once

#include "Board.h"

#include <string>

class Player {
public:
	const virtual string name() const = 0;
	const virtual Coordinate play(const Board& board) = 0;
	char myChar;
	char getChar() { return myChar; };
	void setChar(char val) { myChar = val; };

};