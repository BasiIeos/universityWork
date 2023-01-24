pex1: main.o joblist.o
	g++ -o pex1 main.o joblist.o
joblist.o: joblist.h pqueue.h joblist.cpp
	g++ -c joblist.cpp
main.o: joblist.h main.cpp
	g++ -c main.cpp
