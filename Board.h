#pragma once

#include <iostream>
#include <vector>
#include "Coordinate.h"
#include "Token.h"

using namespace std;

class Board
{
public:
	Board(int boardSize);
	Board(const Board &other);
	friend ostream& operator<<(ostream& os, const Board& board);
	//char operator[](Coordinate index) const;
	Token& operator[](Coordinate index);
	Board & operator=(char token);

private:
	int _boardSize;
	vector<Token> _board;
};


//template<typename T> class Wrapper
//{
//	T Object;
//public:
//	operator T&() { return Object; };
//};
//
//class Class : public Wrapper<char>
//{
//public:
//	char token;
//	Class& operator =(char ch) {
//		if (ch != 'O') {
//			cout << "WRONG" << endl;
//			return *this;
//		}
//		token = ch;
//		return *this;
//	}
//	
//};