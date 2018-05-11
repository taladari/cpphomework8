#pragma once

#include "IllegalCharException.h"

#include <iostream>
using namespace std;


class Coordinate
{
public:
	size_t i, j;
	Coordinate(size_t i, size_t j);
	Coordinate() {};
	//friend ostream & operator <<(ostream& out, Coordinate node);
	//Coordinate & operator=(char token);

private:
};