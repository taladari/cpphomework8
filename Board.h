#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Coordinate.h"
#include "Token.h"
#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"

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