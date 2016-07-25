all:test

CXXFLAGS ?= -std=c++11 -g -O3 -L.


test: test_vector.cpp
	g++ $(CXXFLAGS) test_vector.cpp -o test
	rm -f *.o

clean:
	rm -f *.o
cleanall:
	rm -f *.o test
