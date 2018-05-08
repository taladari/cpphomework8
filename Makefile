CC = g++
# CC = gcc
CFLAGS  = -g -Wall

all: main.o Board.o Board_Node.o IllegalCoordinateException.o IllegalCharException.o 
	$(CC) $(CFLAGS) -o all main.o Board.o Board_Node.o IllegalCoordinateException.o  IllegalCharException.o 
	

Board.o: Board.cpp Board.hpp
	$(CC) $(CFLAGS) -c Board.cpp

Board_Node.o: Board_Node.cpp Board_Node.hpp
	$(CC) $(CFLAGS) -c Board_Node.cpp 

IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.hpp
	$(CC) $(CFLAGS) -c IllegalCoordinateException.cpp

IllegalCharException.o: IllegalCharException.cpp IllegalCharException.hpp
	$(CC) $(CFLAGS) -c IllegalCharException.cpp
	

clean:
	
	rm *.exe all.out *.class
