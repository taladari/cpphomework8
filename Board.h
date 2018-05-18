#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include "Coordinate.h"
#include "Token.h"
#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"
#include "Image.h"

using namespace std;

class Board
{
public:
	Board() {};
	Board(int boardSize);
	Board(const Board &other);
	Board(vector<Token> tokens) : _board(tokens) { _boardSize = tokens.size(); };
	friend ostream& operator<<(ostream& os,  Board const& board);
	const Token operator[](const Coordinate index) const;
	Token& operator[](const Coordinate index);
	Board & operator=(const char token);
	const int size() const;
	friend istream &operator >> (istream  &input, Board &board);
	string draw(int pixels);

private:
	int _boardSize;
	vector<Token> _board;
};