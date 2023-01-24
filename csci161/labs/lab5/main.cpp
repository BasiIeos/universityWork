#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
	ComplexNumber n1(3.5, 7.0);
	ComplexNumber n2;

	cout << "Two complex numbers: \n" << "number 1: " << n1 << endl << "number 2: " << n2 << endl;
	cout << "Enter a complex number\n";
	cin >> n1;
	cout << "Enter another complex number\n";
	cin >> n2;
	
	ComplexNumber n3 = (++n2);
	ComplexNumber n4 = -n1;
	cout << '(' << n3 << ')' << " + " << '(' << n4 << ')' << " = " << n3+n4 << endl;
	cout << '(' << n3 << ')' << " - " << '(' << n4 << ')' << " = " << n3-n4 << endl;
	cout << '(' << n3 << ')' << " * " << '(' << n4 << ')' << " = " << n3*n4 << endl;

	if (n1 == n2)
		cout << "number 1 and number 2 are the same.\n";
	else
		cout << "number 1 and number 2 are NOT the same.\n";
	
	n3[0] = 10.5;
	n3[1] = n3[0];
	cout << "Now the number becomes: " << n3 << endl;
	
	return 0;
}
