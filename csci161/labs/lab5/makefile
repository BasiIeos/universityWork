prog: main.o complex.o
	g++ -o prog main.o complex.o
complex.o: complex.cpp complex.h
	g++ -c complex.cpp
main.o: main.cpp complex.h
	g++ -c main.cpp
