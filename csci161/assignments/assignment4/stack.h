// Vasily Kontorer
// Assignment 4
// Implementation of class Stack

#include <string>

using namespace std;

class Stack
{
	public:
		Stack();
		~Stack();
		int size();
		string top();
		void push(string s);
		void pop();
		void clear();
	private:
		struct Node
		{
			string url;
			Node * next;
		};
		Node * head;
		int Size;
};
