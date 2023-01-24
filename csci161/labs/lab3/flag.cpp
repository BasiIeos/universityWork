#include <iostream>
#include "flag.h"

// implementation of Flag class methods

Flag :: Flag(int width, int height, char symbol)
{
	fwidth = width;
	fheight = height;
	fsymbol = symbol;
}

Flag :: Flag()
{
	fwidth = 1;
	fheight = 1;
	fsymbol= '*';
}

Flag :: ~Flag()
{
}

int Flag ::getWidth()
{
	return fwidth;
}

int Flag :: getHeight()
{
	return fheight;
}

char Flag :: getSymbol()
{
	return fsymbol;
}

void Flag :: resize(int newWidth, int newHeight)
{
	fwidth = newWidth;
	fheight = newHeight;
}

void Flag :: changeSymbol(char newSymbol)
{
	fsymbol = newSymbol;
}

int Flag :: calculate()
{
	return fwidth * fheight;
}

void Flag :: draw()
{
	for (int i = 0; i < fwidth; i++)
	{
		for (int j = 0; j < fheight; j++)
			std::cout << fsymbol;
		std::cout << std::endl;
	}
}

bool Flag :: bigFlag()
{
	return (fwidth * fheight > 25);
}
