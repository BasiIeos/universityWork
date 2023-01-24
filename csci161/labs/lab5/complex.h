#include <iostream>

// Implementation of class ComplexNumber

using namespace std;

class ComplexNumber
{
	public:
		double real;
		double imag;

		ComplexNumber();
		ComplexNumber(double, double);
		~ComplexNumber();
		ComplexNumber operator +(const ComplexNumber &c);
		ComplexNumber operator -(const ComplexNumber &c);
		ComplexNumber operator -();
		ComplexNumber operator *(const ComplexNumber &c);
		bool operator ==(const ComplexNumber &c);
		void operator =(const ComplexNumber &c);
		ComplexNumber operator ++();
		double& operator[] (const int index);
		friend istream & operator >> (istream &in, ComplexNumber &c);
		friend ostream & operator << (ostream &out, const ComplexNumber &c);
};
