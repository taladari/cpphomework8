#pragma once

#include <iostream>
#include <vector>
#include "Board_Node.h"

using namespace std;


struct boardIndex
{
	size_t i, j;
};


class Board
{
public:
	Board(int boardSize);
	friend ostream& operator<<(ostream& os, const Board& board);
	Board_Node operator[](Board_Node index) const;
	Board_Node& operator[](Board_Node index);
	Board & operator=(char token);

private:
	int _boardSize;
	vector<Board_Node> _board;
};