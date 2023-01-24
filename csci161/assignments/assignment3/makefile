pex3: main.o reslist.o
	g++ -o pex3 main.o reslist.o
reslist.o: reslist.h reslist.cpp
	g++ -c reslist.cpp
main.o: reslist.h main.cpp
	g++ -c main.cpp
