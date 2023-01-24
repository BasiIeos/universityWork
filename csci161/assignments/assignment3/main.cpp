#include <iostream>
#include "reslist.h"

using namespace std;

int main()
{
	ResList taxi;
	bool succTerm = false;
	char command;
	while (!succTerm)
	{
		cout << "-----------------------------------\n";
		cout << "Please enter your command: ";
		cin >> command;
		if ((command == 's') || (command == 'S'))
			taxi.submit();
		else if ((command == 'p') || (command == 'P'))
			taxi.pickup();
		else if ((command == 'h') || (command == 'H'))
			taxi.help();
		else if ((command == 'l') || (command == 'L'))
			taxi.list();
		else if ((command == 't') || (command == 'T'))
		{
			if (taxi.term())
				succTerm = true;
		}
		else
			cout << "No such command. Please try again.\n";
	}
       	return 0;
}
