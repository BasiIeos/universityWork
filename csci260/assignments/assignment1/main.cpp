// Vasily Kontorer
// Assignment 1
// Main part of the program

#include "joblist.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
	int n;
	if (argc > 2)
	{
		cout << "There should be not more than 1 command line argument: size of priority queue, please try again\n";
		return 0;
	} 
	else if (argc == 2)
	{
		try
		{
			n = stoi(argv[1]);
		}
		catch (const invalid_argument& ia)
		{
			cout << "If you actually want to designate the size of the priority queue, it has to be a positive integer. Please try again\n";
			return 0;
		}
	}
	else
		n = 10;
	JobList list(n);
	string command;
	cin >> command;
	while (command != "quit")
	{
		if (command == "submit")
			list.submit();
		else if (command == "execute")
			list.execute();
		else if (command == "random")
			list.random();
		else
			cout << "List of possible commands: submit; execute; random; quit\n";
		cin >> command;
	}
	list.quit();
	return 0;
}
