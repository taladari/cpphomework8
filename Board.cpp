#include "Board.h"



Board::Board(int boardSize)
{
	this->_boardSize = boardSize;
	//for (size_t i = 0; i < _boardSize; i++)
	//{
	//	vector<char> temp;
	//	for (size_t j = 0; j < _boardSize; j++)
	//	{
	//		temp.push_back('.');
	//	}
	//	_board.push_back(temp);
	//}
	vector<char> temp(boardSize*boardSize, '.');
	_board = temp;
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
