prog: array.o main.o
	g++ -o prog array.o main.o
array.o: array.h array.cpp
	g++ -c array.cpp
main.o: array.h main.cpp
	g++ -c main.cpp

