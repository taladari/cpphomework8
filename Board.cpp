#include "Board.h"
#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"

// i = row * boardSize + col

Board::Board(int boardSize) : _boardSize(boardSize), _board(boardSize*boardSize, { '.' })
{
}

Board::Board(const Board & other) : _board(other._board), _boardSize (other._boardSize)
{
}

Board_Node Board::operator[](Board_Node index) const
{
	int boardIndex = index.i * _boardSize + index.j;
	if (boardIndex < 0 || boardIndex >= _board.size())
	{
		throw IllegalCoordinateException(index.i, index.j);
	}
	return _board[index.i * _boardSize + index.j];
}

Board_Node & Board::operator[](Board_Node index)
{
	int boardIndex = index.i * _boardSize + index.j;
	if (boardIndex < 0 || boardIndex >= _board.size())
	{
		throw IllegalCoordinateException(index.i, index.j);
	}
	return _board[index.i * _boardSize + index.j];
}

Board & Board::operator=(char token)
{
	if (token != '.')
	{
		throw IllegalCharException(token);
	}
	for (size_t i = 0; i < _boardSize * _boardSize; i++)
	{
		_board[i].token = '.';
	}
}

ostream & operator<<(ostream & os, const Board & board)
{
	for (size_t i = 0; i < board._boardSize*board._boardSize; i++)
	{
		if (i != 0 && i % board._boardSize == 0)
		{
			os << endl;
		}
		os << board._board[i].token;
	}
	return os;
}
