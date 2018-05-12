#include "TicTacToe.h"

TicTacToe::TicTacToe(int size) : _boardSize(size), _gameBoard(size)
{
}

void TicTacToe::play(Player & p1, Player & p2)
{
	restartBoard();
	p1.setChar('X');
	p2.setChar('O');
	Player* currPlayer = &p1;
	bool gameOver = false;
	while (!gameOver)
	{
		int result = playSingleTurn(*currPlayer);
		if (result == -1)
		{
			_gameWinner = currPlayer == &p1 ? &p2 : &p1;
			gameOver = true;
			continue;
		}
		if (isWinner(*currPlayer))
		{
			_gameWinner = currPlayer;
			gameOver = true;
			continue;
		}
		else if (isBoardFull())
		{
			_gameWinner = &p2;
			gameOver = true;
			continue;
		}
		currPlayer = currPlayer == &p1 ? &p2 : &p1;
	}
}

int TicTacToe::playSingleTurn(Player & player)
{
	Coordinate toMove;
	try
	{
		toMove = player.play(this->_gameBoard);
		if (_gameBoard[toMove] != '.')
			return -1;
		_gameBoard[toMove] = player.getChar();
		return 0;
	}
	catch (string s)
	{
		return -1;
	}
	catch (exception& e) {
		return -1;
	}	
}

Player & TicTacToe::winner() const
{
	return *_gameWinner;
}

Board TicTacToe::board() const
{
	return _gameBoard;
}

bool TicTacToe::isWinner(Player & player)
{
	char check = player.getChar();
	char emptySlot = '.';
	int size = _boardSize;
	bool hasWon = true;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i*j == 0 || i == size - 1 || j == size - 1)
			{
				char curr = _gameBoard[{i, j}]._tok;
				if (curr == emptySlot)
					continue;
				if (j == 0)			// look right
				{
					for (size_t k = 1; k < size; k++)
					{
						if (_gameBoard[{i, k}]._tok != curr)
						{
							hasWon = false;
							break;
						}
					}
					if (hasWon)
						return true;
				}
				hasWon = true;
				if (i == 0)			// look down
				{
					for (size_t k = 1; k < size; k++)
					{
						if (_gameBoard[{k, j}]._tok != curr)
						{
							hasWon = false;
							break;
						}
					}
					if (hasWon)
						return true;
					hasWon = true;
					if (j == 0) // look down right
					{
						for (size_t k = 1; k < size; k++)
						{
							if (_gameBoard[{i + k, j + k}]._tok != curr)
							{
								hasWon = false;
								break;
							}
						}
						if (hasWon)
							return true;
					}
					hasWon = true;
					if (j == size - 1) // look down left
					{
						for (size_t k = 1; k < size; k++)
						{
							if (_gameBoard[{i + k, j - k}]._tok != curr)
							{
								hasWon = false;
								break;
							}
						}
						if (hasWon)
							return true;
					}
				}
			}
		}
	}
	return false;
}

bool TicTacToe::isBoardFull()
{
	for (size_t i = 0; i < _gameBoard.size(); i++)
	{
		for (size_t j = 0; j < _gameBoard.size(); j++)
		{
			if (_gameBoard[{i, j}] == '.')
			{
				return false;
			}
		}
	}
	return true;
}

void TicTacToe::restartBoard()
{
	_gameBoard = Board(_boardSize);
}