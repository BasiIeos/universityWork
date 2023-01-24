// Vasily Kontorer
// Assignment 5
// Implementation of class CountryList (Clist)

#include <iostream>
#include <string>
#include "dictionary.h"
#include <fstream>

using namespace std;

class Clist
{
	public:
		Clist();
		~Clist();
		void list();
		void show();
		void remove();
		void add();
		void update();
		void help();
		void exit();
	private:
		struct Info
		{
			string capital;
			string language;
			float area;
			long int population;
			string description;
		};
		Dictionary <string, Info> a;
};

string tolowercase(string s);
