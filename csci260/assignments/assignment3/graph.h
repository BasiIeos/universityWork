// Vasily Kontorer
// Assignment 3
// Implementation of graph class

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

class Graph
{
	private:
		vector <vector <int> > v;
		int size;
	public:
		Graph(const string &fname, bool &end, map <string, int> &users);
		~Graph();
		void influence(map <string, int> &users);
		void controversial(map <string, int> &users);
		void outreach(int u, map <string, int> &users);
		void outreach2(int u, vector <bool> &reachable);
		void link(int u1, int u2, map <string, int> &users);
		void update(int u1, int u2, int d, map <string, int> &users);
		void quit(string fname, map <string, int> &users);
};
