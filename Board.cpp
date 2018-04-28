#include "Board.h"

// i = row * boardSize + col

Board::Board(int boardSize)
{
	this->_boardSize = boardSize;
	vector<char> temp(boardSize*boardSize, '.');
	_board = temp;
}

char Board::operator[](boardIndex index) const
{
	return _board[index.i * _boardSize + index.j];
}

char & Board::operator[](boardIndex index)
{
	return (*this)[index];
}

ostream & operator<<(ostream & os, const Board & board)
{
	for (size_t i = 0; i < board._boardSize*board._boardSize; i++)
	{
		if (i != 0 && i % board._boardSize == 0)
		{
			os << endl;
		}
		os << board._board[i];
	}
	return os;
}
