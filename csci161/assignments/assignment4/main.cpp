// Vasily Kontorer
// Assignment 4
// Main part of program

#include <iostream>
#include <string>
#include "browser.h"

using namespace std;

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		cout << "usage: ./pex4 starting_url\n";
		return 0;
	}
	string url1 = (string)(argv[1]);
	Browser curSession(url1);
	cout << "command$ ";
	string com;
	cin >> com;
	while (com != (string)("exit"))
	{
		if (com == (string)("click"))
		{
			string newUrl;
			cin >> newUrl;
			curSession.click(newUrl);
		}
		else if (com == (string)("back"))
			curSession.back();
		else if (com == (string)("forward"))
			curSession.forward();
		else
			cout << "No such command. Please try again\n";
		cout << "command$ ";
		cin >> com;
	}
	return 0;
}
