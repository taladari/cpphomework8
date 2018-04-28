#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Board
{
public:
	Board(int boardSize);
	friend ostream& operator<<(ostream& os, const Board& board);

private:
	int _boardSize;
	vector<char> _board;
};