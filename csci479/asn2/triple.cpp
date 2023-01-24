//Implementation of functions for class triple
#include "triple.h"

using namespace std;

Triple :: Triple()
{
	a = 0;
	b = 0;
	c = 0;
}

Triple :: Triple(int newA, int newB, int newC)
{
	a = newA;
	b = newB;
	c = newC;
}

int Triple :: first()
{
	return a;
}

int Triple :: second()
{       
        return b;
}

int Triple :: third()
{       
        return c;
}
