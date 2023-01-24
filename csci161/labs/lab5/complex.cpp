#include "complex.h"

// Implementation of methods of ComplexNumber class

ComplexNumber :: ComplexNumber()
{
	real = 0;
	imag = 0;
}

ComplexNumber :: ComplexNumber(double a, double b)
{
	real = a;
	imag = b;
}

ComplexNumber :: ~ComplexNumber()
{
}

ComplexNumber ComplexNumber :: operator +(const ComplexNumber &c)
{
	double a = real + c.real;
	double b = imag + c.imag;
	return ComplexNumber(a, b);
}

ComplexNumber ComplexNumber :: operator -(const ComplexNumber &c)
{
	double a = real - c.real;
	double b = imag - c.imag;
	return ComplexNumber(a, b);
}

ComplexNumber ComplexNumber :: operator -()
{
	return ComplexNumber(-1*real, -1*imag);
}

ComplexNumber ComplexNumber :: operator *(const ComplexNumber &c)
{
	double a = real * c.real - imag * c.imag;
	double b = real * c.imag + imag * c.real;
	return ComplexNumber(a, b);
}

bool ComplexNumber :: operator ==(const ComplexNumber &c)
{
	return ((real == c.real) && (imag == c.imag));
}

void ComplexNumber :: operator =(const ComplexNumber &c)
{
	real = c.real;
	imag = c.imag;
}

ComplexNumber ComplexNumber :: operator ++()
{
	return ComplexNumber(real + 1, imag + 1);
}

double& ComplexNumber :: operator [](const int index)
{
	if (index == 0)
		return real;
	else if (index == 1)
		return imag;
}

istream & operator >>(istream &in, ComplexNumber &c)
{
	char ch;
	in >> c.real >> ch >> c.imag >> ch;
}

ostream & operator <<(ostream &out, const ComplexNumber &c)
{
	out << c.real << " + " << c.imag << 'i';
}
