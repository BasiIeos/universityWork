// functions for the slightly modified Trie structure
#include <string>
#include <utility>
#include <iostream>
#include "trie.h"

using namespace std;

int PrevIndex :: getFrom()
{
	return from;
}

int PrevIndex :: getTo()
{
	return to;
}

void PrevIndex :: newFrom(int newF)
{
	from = newF;
}

void PrevIndex :: newTo(int newT)
{
	to = newT;
}

Trie :: Trie()
{
	root = new Node;
	for (int i = 0; i < 27; i++)
	{
	       root->children[i] = NULL;
	}
	root->prev = NULL;
}

void Trie :: add(string s, int prevFrom, int prevTo)
{
	Node* ptr = root;	
	for (int i = 0; i < s.length(); i++)
	{
		int way;
		if (s[i] != ' ')
			way = s[i] - 'A';
		else
			way = 26; 
		if (!ptr->children[way])
		{
			ptr->children[way] = new Node;
			for (int i = 0; i < 27; i++)
			{
				ptr->children[way]->children[i] = NULL;
			}
			ptr->children[way]->prev = NULL;
		}
		ptr = ptr->children[way];
	}
	ptr->prev = new PrevIndex;
	ptr->prev->newFrom(prevFrom);
	ptr->prev->newTo(prevTo);

}

bool Trie :: contains(string s)
{
	Node* ptr = root;
	for (int i = 0; i < s.length(); i++)
	{
		int way;
		if (s[i] != ' ')
			way = s[i] - 'A';
		else
			way = 26; 
		if (!ptr->children[way])
			return false;
		ptr = ptr->children[way];
	}
	return true;
}

pair <int, int> Trie :: givePrev(string s)
{	
	Node* ptr = root;
	for (int i = 0; i < s.length(); i++)
	{
		int way;
		if (s[i] != ' ')
			way = s[i] - 'A';
		else
			way = 26; 
		ptr = ptr->children[way];
	}
	return make_pair(ptr->prev->getFrom(), ptr->prev->getTo());
}
