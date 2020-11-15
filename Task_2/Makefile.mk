CC=g++

recursion: recursion.cpp
	$(CC) recursion.cpp -o recursion

clean:
	rm -rf recursion
