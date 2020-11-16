CC=g++
CFLAGS=-std=c++11 -pthread

BrowseDir: BrowseDir.cpp
	$(CC) $(CFLAGS) BrowseDir.cpp -o browsedir

clean:
	rm -rf browsedir