prog: flag.o main.o
	g++ -o prog flag.o main.o
flag.o: flag.cpp flag.h
	g++ -c flag.cpp
main.o: main.cpp flag.h
	g++ -c main.cpp
