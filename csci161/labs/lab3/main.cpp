#include "flag.h"
#include <iostream>

using namespace std;

// main procedure
// for business logic
// or for testing classes

int main()
{
	Flag starFlag(5, 3, '*');
	Flag *flagPtr = new Flag();

	cout << "info of star flag" << endl;
	cout << "width: " << starFlag.getWidth() << endl;
	cout << "height: " << starFlag.getHeight() << endl;

	starFlag.draw();

	if (starFlag.bigFlag()) 
	        cout << "star flag is a big flag." << endl;
	else
		cout << "star flag is a small flag." << endl;

	cout << "info of dynamically created flag:" << endl;
	cout << "width: " << flagPtr->getWidth() << endl;
	cout << "height: " << flagPtr->getHeight() << endl;

	flagPtr->draw();

	flagPtr->resize(7, 5);
	flagPtr->changeSymbol('^');
	flagPtr->draw();

	if (flagPtr->bigFlag())
		cout << "the dynamically created flag is a big flag." << endl;
	else
		cout << "the dynamically created flag is a small flag." << endl;

	delete flagPtr;

	return 0;
}
