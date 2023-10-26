DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
FLAGS = -Wall -pedantic-errors

compile: Matrix.o p1.o
	g++ $(FLAGS) -o p1 Matrix.o p1.o

Matrix.o: Matrix.cpp Matrix.h
	g++ $(CFLAGS) Matrix.cpp

p1.o: p1.cpp Matrix.h
	g++ $(CFLAGS) p1.cpp

run: compile
	./p1

clean:
	rm -f p1
	rm -f *.o
