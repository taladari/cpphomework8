CXX=clang++-5.0
CXXFLAGS=-std=c++17 

all: Board.o Coordinate.o IllegalCoordinateException.o IllegalCharException.o Token.o CharWrapper.o
	
Board.o: 
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o
	
Coordinate.o: 
	$(CXX) $(CXXFLAGS) -c Coordinate.cpp -o Coordinate.o
	
Token.o: 
	$(CXX) $(CXXFLAGS) -c Token.cpp -o Token.o
	
CharWrapper.o: 
	$(CXX) $(CXXFLAGS) -c CharWrapper.cpp -o CharWrapper.o
	
IllegalCoordinateException.o: 
	$(CXX) $(CXXFLAGS) -c IllegalCoordinateException.cpp -o IllegalCoordinateException.o
	
IllegalCharException.o: 
	$(CXX) $(CXXFLAGS) -c IllegalCharException.cpp -o IllegalCharException.o
	
clean:
rm *.o a.out