CC=g++

all: test

test: test.o stack.o
	$(CC) stack.o test.o -o test

test.o: test.cpp
	$(CC) -c test.cpp

stack.o: stack.hpp stack.cpp
	$(CC) -c stack.cpp

clean:
	rm -rf *.o test