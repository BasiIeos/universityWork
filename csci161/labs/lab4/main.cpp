#include <iostream>
#include "array.h"

using namespace std;

int main()
{
	GArray a;
	GArray b(10);
	a.insert(1);
	a.insert(2);
	cout << "number of elements in growing array a is " << a.getSize() << "\n";
	cout << "growing array a:\n";
	a.show();
	cout << "number of elements in growing array b is " << b.getSize() << "\n";
	cout << "growing array b:\n";
	b.show();
	if (a == b)
		cout << "growing arrays a and b are equal\n";
	else
		cout << "growing arrays a and b aren't equal\n";
	return 0;
}
