pex5: main.o countrylist.o
	g++ -o pex5 main.o countrylist.o
countrylist.o: countrylist.h dictionary.h countrylist.cpp
	g++ -c countrylist.cpp
main.o: countrylist.h main.cpp
	g++ -c main.cpp
