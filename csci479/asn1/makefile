pex1: trie.o main.o
	g++ -o pex1 trie.o main.o
trie.o: trie.cpp trie.h
	g++ -c trie.cpp
main.o: trie.h main.cpp
	g++ -c main.cpp
