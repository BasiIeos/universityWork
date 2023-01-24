#include <iostream>
#include <vector>
#include <string>
#include "image.h"

using namespace std;

// Implementation of constructors, destructor, operators and methods of Image class

// Constructor without parameters
Image :: Image()
{
	name = "";
	noOfRows = 0;
	noOfColumns = 0;
	picture.resize(1024);
	for (int i = 0; i < 1024; i++)
		picture[i].resize(1024);
}

// Constructor with parameters
Image :: Image (string newName, int n, int m, vector <vector <int> >  &content)
{
	name = newName;
	noOfRows = n;
	noOfColumns = m;
	picture.resize(1024);
	for (int i = 0; i < 1024; i++)
		picture[i].resize(1024);
	for (int j = 0; j < n; j++)
		for (int k = 0; k < m; k++)
			picture[j][k] = content[j][k];
}

// Access to number of rows
int Image :: rows()
{
	return noOfRows;
}

// Access to number of columns
int Image :: columns()
{
	return noOfColumns;
}

// Access to name
string Image :: imageName()
{
	return name;
}

// Access to picture
vector <vector <int> > Image :: pixels()
{
	return picture;
}

// Copy overload
void Image :: operator = (const Image &i)
{
	noOfRows = i.noOfRows;
	noOfColumns = i.noOfColumns;
	name = i.name;
	for (int j = 0; j < noOfRows; j++)
		for (int k = 0; k < noOfColumns; k++)
			picture[j][k] = i.picture[j][k];
}

// Destructor - not needed with vectors
Image :: ~Image()
{
}

// + overload
Image Image :: operator + (const Image &i) throw (string)
{
	if ((noOfRows != i.noOfRows) || (noOfColumns != i.noOfColumns))
		throw string("Incompatible size");
	
	string newName = name + " + " + i.name;
	int n = noOfRows, m = noOfColumns;
	vector <vector <int> > newPicture (1024, vector <int> (1024));
	
	for (int j = 0; j < n; j++)
		for (int k = 0; k < m; k++)
			newPicture[j][k] = (picture[j][k] + i.picture[j][k]) / 2;
	
	return Image(newName, n, m, newPicture);
}

// Comparing overload
bool Image :: operator == (const Image &i)
{
	if ((noOfRows != i.noOfRows) || (noOfColumns != i.noOfColumns))
		return false;
	
	bool c = true;
	
	for (int j = 0; ((j < noOfRows) && (c)); j++)
		for (int k = 0; ((k < noOfColumns) && (c)); k++)
			if (picture[j][k] != i.picture[j][k])
				c = false;
	
	return c;
}

// Histogram method
void Image :: histogram(int n)
{
	vector <int> count (n);
	
	for (int j = 0; j < noOfRows; j++)
		for (int k = 0; k < noOfColumns; k++)
		{
			int l = 0;
			while ((l < n) && (picture[j][k] >= l * (256 / n)))
				l++;
			l--;
			count[l]++;
		}

	cout << "HISTOGRAM: \n";
	for (int l = 0; l < n; l++)
		cout << l * (256 / n) << " to " << (l + 1) * (256 / n) - 1 << ": " << count[l] << "\n";
}

// Input overload
istream & operator >> (istream &in, Image &i)
{
	getline(in, i.name);
	in >> i.noOfRows >> i.noOfColumns;
	for (int j = 0; j < i.noOfRows; j++)
		for (int k = 0; k < i.noOfColumns; k++)
			in >> i.picture[j][k];

	// Getline to get rid of \n symbol
	string s;
	getline(in, s);

	return in;
}

// Output overload
ostream & operator << (ostream &out, const Image &i)
{
	out << "TITLE: " << i.name << "\n";
	out << "SIZE: " << i.noOfRows << " by " << i.noOfColumns << "\n";
	out << "CONTENT: " << "\n";
	for (int j = 0; j < i.noOfRows; j++)
	{
		for (int k = 0; k < i.noOfColumns; k++)
			out << i.picture[j][k] << ' ';
		out << "\n";
	}
	return out;
}
