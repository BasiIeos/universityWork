// Vasily Kontorer
// Assignment 5
// Main part of program

#include <iostream>
#include <string>
#include <fstream>
#include "countrylist.h"

using namespace std;

int main()
{
	Clist wikiCountry;
	string s;
	while (s != "exit")
	{
		cout << "--------------------------" << '\n';
		cout << "Enter your command choice: ";
		cin >> s;
		s = tolowercase(s);
		if (s == "list")
			wikiCountry.list();
		else if (s == "show")
			wikiCountry.show();
		else if (s == "add")
			wikiCountry.add();
		else if (s == "remove")
			wikiCountry.remove();
		else if (s == "update")
			wikiCountry.update();
		else if (s == "help")
			wikiCountry.help();
		else if (s == "exit")
			wikiCountry.exit();
		else
			cout << "Wrong command. Please enter help to see the list of commands or try again.\n";
	}
	return 0;
}
