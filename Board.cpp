#include "Board.h"

Board::Board(int boardSize) : _boardSize(boardSize), _board(boardSize*boardSize, { '.' })
{
}

Board::Board(const Board & other) : _board(other._board), _boardSize(other._boardSize)
{
}

//char Board::operator[](Coordinate index) const
//{
//	int boardIndex = index.i * _boardSize + index.j;
//	if (boardIndex < 0 || boardIndex >= _board.size())
//	{
//		throw IllegalCoordinateException(index.i, index.j);
//	}
//	return _board[index.i * _boardSize + index.j].getToken();
//}

Token & Board::operator[](const Coordinate index)
{
	int boardIndex = index.i * _boardSize + index.j;
	if (boardIndex < 0 || boardIndex >= _board.size())
	{
		throw IllegalCoordinateException(index.i, index.j);
	}
	return _board[index.i * _boardSize + index.j];
}

Board & Board::operator=(const char token)
{
	if (token != '.')
	{
		throw IllegalCharException(token);
	}
	for (size_t i = 0; i < _board.size(); i++)
	{
		_board[i] = '.';
	}
	return *this;
}

ostream & operator<<(ostream & os, Board const & board)
{
	for (size_t i = 0; i < board._board.size(); i++)
	{
		if (i != 0 && i % board._boardSize == 0)
		{
			os << endl;
		}
		os << board._board[i]._tok;
	}
	return os;
}