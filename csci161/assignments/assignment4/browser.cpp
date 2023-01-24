// Vasily Kontorer
// Assignment 4
// Methods of class Browser

#include <string>
#include <iostream>
#include "browser.h"

using namespace std;

Browser :: Browser(string s)
{
	curUrl = s;
	cout << "You are viewing " << s << "\n";
}

Browser :: ~Browser()
{
}

void Browser :: click(string s)
{
	flist.clear();
	blist.push(curUrl);
	curUrl = s;
	cout << "You are viewing " << s << "\n";
}

void Browser :: back()
{
	if (blist.size() == 0)
		cout << "Can't move back any more.\n";
	else
	{
		string s = blist.top();
		cout << "You are viewing " << s << "\n";
		flist.push(curUrl);
		curUrl = s;
		blist.pop();
	}
}

void Browser :: forward()
{
	if (flist.size() == 0)
		cout << "Can't move forward any more.\n";
	else
	{
		string s = flist.top();
		cout << "You are viewing " << s << "\n";
		blist.push(curUrl);
		curUrl = s;
		flist.pop();
	}
}
