#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Implementation of class Image

class Image
{
	public:
		Image();
		Image(string, int, int, vector <vector <int> > &);
		int rows();
		int columns();
		string imageName();
		vector <vector <int> > pixels();
		void operator = (const Image &i);
		~Image();
		Image operator + (const Image &i) throw (string);
		bool operator == (const Image &i);
		void histogram(int n);
		friend istream & operator >> (istream &in, Image &i);
		friend ostream & operator << (ostream &out, const Image &i);
	private:
		string name;
		int noOfRows, noOfColumns;
		vector <vector <int> > picture;
};
