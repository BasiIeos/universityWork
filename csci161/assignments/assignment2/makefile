pex2: image.o main.o
	g++ -o pex2 image.o main.o
image.o: image.cpp image.h
	g++ -c image.cpp
main.o: main.cpp image.h
	g++ -c main.cpp
