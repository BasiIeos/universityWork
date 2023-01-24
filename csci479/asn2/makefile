pex2: triple.o main.o
	g++ -o pex2 triple.o main.o
triple.o: triple.cpp triple.h
	g++ -c triple.cpp
main.o: triple.h main.cpp
	g++ -c main.cpp
