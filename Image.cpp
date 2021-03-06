#include "Image.h"

Image::Image(int dim) : dim(dim)
{
	colors = new RGB[dim*dim];
}


string Image::createPPM(vector<Token> board, int boardSize)
{
	int cellSize = dim / boardSize;
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			if (board[i*boardSize + j] == 'X')
			{
				drawX(i, j, cellSize);
			}
			else if (board[i*boardSize + j] == 'O')
			{
				drawO(i, j, cellSize);
			}
			else {
				drawBlank(i, j, cellSize);
			}
		}
	}
	return savePPMFile();
}


void Image::drawX(int row, int col, int cellSize)
{
	int currRow = row*cellSize;
	int currCol = col*cellSize;
	for (int i = 0; i < cellSize; i++) {
		currCol = col*cellSize;
		for (int j = 0; j < cellSize; j++) {
			if (((i == j || i + j == cellSize) && i > 20 && i < cellSize - 20 && j > 20 && j < cellSize -20) 
				|| i % (cellSize - 1) == 0 || j % (cellSize - 1) == 0)
			{
				colors[currRow*dim + currCol].red = 0;
				colors[currRow*dim + currCol].green = 0;
				colors[currRow*dim + currCol].blue = 0;
			}
			currCol++;
		}
		currRow++;
	}
}

void Image::drawBlank(int row, int col, int cellSize)
{
	int currRow = row*cellSize;
	int currCol = col*cellSize;
	for (int i = 0; i < cellSize; i++)
	{
		currCol = col*cellSize;
		for (int j = 0; j < cellSize; j++)
		{
			if (i % (cellSize - 1) == 0 || j % (cellSize - 1) == 0)
			{
				colors[currRow*dim + currCol].red = 0;
				colors[currRow*dim + currCol].green = 0;
				colors[currRow*dim + currCol].blue = 0;
			}
			currCol++;
		}
		currRow++;
	}
}

void Image::drawO(int row, int col, int cellSize)
{
	int radius = cellSize / 2 - 20;
	int midX = cellSize / 2, midY = cellSize / 2;
	int currRow = row*cellSize;
	int currCol = col*cellSize;
	for (int i = 0; i < cellSize; i++) {
		currCol = col*cellSize;
		for (int j = 0; j < cellSize; j++) {

			const double x_diff = j - midX;
			const double y_diff = i - midY;
			double distance = sqrt(x_diff * x_diff + y_diff * y_diff);

			if ((distance >= radius - 1 && distance <= radius + 1) || i % (cellSize - 1) == 0 || j % (cellSize - 1) == 0)
			{
				colors[currRow*dim + currCol].red = 0;
				colors[currRow*dim + currCol].green = 0;
				colors[currRow*dim + currCol].blue = 0;
			}
			currCol++;
		}
		currRow++;
	}	
}

string Image::savePPMFile()
{
	srand(time(0));
	string fileName = "board" + to_string(rand()) + ".ppm";
	ifstream f(fileName.c_str());
	int i = 0;
	while (f.good()) {
		fileName = "board" + to_string(rand()) + to_string(i) + ".ppm";
		i++;
		f.close();
		f = ifstream(fileName.c_str());
	}
	ofstream imageFile(fileName, ios::out | ios::binary);
	imageFile << "P6" << endl << dim << " " << dim << endl << 255 << endl;
	imageFile.write(reinterpret_cast<char*>(colors), 3 * dim*dim);
	imageFile.close();
	return fileName;
}

Image::~Image()
{
	delete[] colors;
}