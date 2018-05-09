CXX=clang++-5.0
CPPFLAGS=-std=c++17 

all: Board.o Coordinate.o IllegalCoordinateException.o IllegalCharException.o Token.o CharWrapper.o

Board.o: Board.cpp Board.h
	$(CXX) $(CPPFLAGS) --compile Board.cpp -o Board.o
	
Board.o: Coordinate.cpp Coordinate.h
	$(CXX) $(CPPFLAGS) --compile Coordinate.cpp -o Coordinate.o
	
Board.o: IllegalCoordinateException.cpp IllegalCoordinateException.h
	$(CXX) $(CPPFLAGS) --compile IllegalCoordinateException.cpp -o IllegalCoordinateException.o
	
Board.o: IllegalCharException.cpp IllegalCharException.h
	$(CXX) $(CPPFLAGS) --compile IllegalCharException.cpp -o IllegalCharException.o
	
Board.o: Token.cpp Token.h
	$(CXX) $(CPPFLAGS) --compile Token.cpp -o Token.o
	
Board.o: CharWrapper.cpp CharWrapper.h
	$(CXX) $(CPPFLAGS) --compile CharWrapper.cpp -o CharWrapper.o