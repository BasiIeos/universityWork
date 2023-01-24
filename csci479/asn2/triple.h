//Implementation of class triple used to store constraints
using namespace std;

class Triple
{
	public:
		Triple();
		Triple(int, int, int);
		int first();
		int second();
		int third();
	private:
		int a;
		int b;
		int c;
};
