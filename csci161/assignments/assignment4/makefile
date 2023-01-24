pex4: main.o stack.o browser.o
	g++ -o pex4 main.o stack.o browser.o
stack.o: stack.cpp stack.h
	g++ -c stack.cpp
browser.o: browser.cpp browser.h
	g++ -c browser.cpp
main.o: main.cpp browser.h
	g++ -c main.cpp
