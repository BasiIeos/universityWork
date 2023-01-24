#include <iostream>
#include <cmath>

using namespace std;

char toLowerCase(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
		c += 'a' - 'A';
	return c;
}

int main(int argc, char *argv[])
{
	bool d = false;
	int i = 0, size1 = 0, size2 = 0;
	
	while (argv[1][size1] != '\0')
		size1++;
	while (argv[2][size2] != '\0')
		size2++;

	while ((i < min(size1, size2)) && (!d))
	{
		if ((argv[1][i] != argv[2][i]) && (toLowerCase(argv[1][i]) != toLowerCase(argv[2][i])))
			d = true;
		i++;
	}
	if (d)
		cout << "The two strings become different at position " << i - 1 << ".\n";
	else if (size1 != size2)
		cout << "The two strings become different at position " << i << ".\n";
	else
		cout << "The two strings are the same.\n";
}
