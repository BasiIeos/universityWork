#include "array.h"
#include <iostream>

// Implementation of methods for growing array class

using namespace std;

GArray :: GArray()
{
	A = new int[1];
	size = 1;
	elem = 0;
}

GArray :: GArray(int s)
{
	A = new int[s];
	size = s;
	elem = 0;
}

GArray :: ~GArray()
{
	delete [] A;
}

void GArray :: insert(double k)
{
	if (elem < size)
	{
		A[elem] = k;
		elem++;
	} else if (elem == size) {
		size *= 2;
		int *newA = new int[size];
		for (int i = 0; i < elem; i++)
			newA[i] = A[i];
		A = newA;
		delete [] newA;
		A[elem] = k;
		elem++;
	}
}

void GArray :: show()
{
	for (int i = 0; i < elem; i++)
		cout << A[i] << endl;
}

int GArray :: getSize()
{
	return elem;
}

bool GArray :: operator ==(const GArray &a)
{
	if (elem != a.elem)
		return false;
	for (int i = 0; i < elem; i++)
		if (A[i] != a.A[i])
			return false;
	return true;
}
