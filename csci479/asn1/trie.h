//I'm using this slightly modified trie structure to quickly store already checked sequences and check if the sequence has already been worked on
#include <string>
#include <utility>

using namespace std;

class PrevIndex
{
	public:
		int getFrom();
		int getTo();
		void newFrom(int);
		void newTo(int);
	private:
		int from;
		int to;
};

class Trie
{
	public:
		Trie();
		bool contains(string);
		void add(string, int, int);
		pair <int, int> givePrev(string);
	private:
		struct Node
		{
			Node* children[27];
			PrevIndex* prev;
		};
		Node* root;
};
