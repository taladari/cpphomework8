#pragma once

#include "Board.h"
#include "Player.h"

class TicTacToe {
private:
	int _boardSize;
	Board _gameBoard;
	int playSingleTurn(Player &player);
	bool isWinner(Player &player);
	bool isBoardFull();
	void restartBoard();
	Player* _gameWinner;

public:
	TicTacToe(int size);
	void play(Player &p1, Player &p2);
	Player& winner() const;
	Board board() const;
};