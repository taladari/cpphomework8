CC =g++
CFLAGS = -Wall -g

all.out:main.o Board.o Coordinate.o IllegalCoordinateException.o IllegalCharException.o Token.o CharWrapper.o 
	$(CC) $(CFLAGS) -o all main.o Board.o Coordinate.o IllegalCoordinateException.o IllegalCharException.o Token.o CharWrapper.o -o all.out 
	

Board.o: Board.cpp Board.h
	$(CC) $(CFLAGS) -c Board.cpp

Coordinate.o: Coordinate.cpp Coordinate.h
	$(CC) $(CFLAGS) -c Coordinate.cpp 

Token.o: Token.cpp Token.h
	$(CC) $(CFLAGS) -c Token.cpp

CharWrapper.o: CharWrapper.cpp CharWrapper.h
	$(CC) $(CFLAGS) -c CharWrapper.cpp
	
IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h
	$(CC) $(CFLAGS) -c IllegalCoordinateException.cpp

IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	$(CC) $(CFLAGS) -c IllegalCharException.cpp
	
clean:
	
		rm *.o all.out