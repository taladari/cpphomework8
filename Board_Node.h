#pragma once

class Board_Node
{
public:
	size_t i, j;
	char token;
	Board_Node(char token);
	Board_Node(size_t i, size_t j);
	Board_Node & operator=(char token);

private:
};