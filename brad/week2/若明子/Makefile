all:test

CXXFLAGS ?= -std=c++11 -g -O3 -L.


test: rectangle.cpp
	g++ $(CXXFLAGS) rectangle.cpp -o test
	rm -f *.o

clean:
	rm -f *.o
cleanall:
	rm -f *.o test
