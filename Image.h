#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <math.h>
#include "Token.h"


using namespace std;

typedef unsigned char uint8_t;

struct RGB {
	uint8_t red, green, blue;
public:
	RGB() : red(255), green(255), blue(255) {}
	RGB(uint8_t red, uint8_t green, uint8_t blue) : red(red), green(green), blue(blue) {}
};

class Image {
private:
	int dim;
	RGB* colors;
	void drawX(int row, int col, int cellSize);
	void drawO(int row, int col, int cellSize);
	void drawBlank(int row, int col, int cellSize);
	void savePPMFile(string fName);

public:
	Image(int dim);
	string createPPM(vector<Token> board, int boardSize);
};