// Vasily Kontorer
// Assignment 4
// Implementation of class Browser

#include "stack.h"
#include <string>

using namespace std;

class Browser
{
	public:
		Browser(string);
		~Browser();
		void click(string s);
		void back();
		void forward();
	private:
		Stack blist;
		Stack flist;
		string curUrl;
};
