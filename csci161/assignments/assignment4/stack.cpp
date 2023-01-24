// Vasily Kontorer
// Assignment 4
// Methods of class Stack

#include <string>
#include <iostream>
#include "stack.h"

using namespace std;

Stack :: Stack()
{
	head = new Node;
	head = 0;
	Size = 0;
}

Stack :: ~Stack()
{
	Node * ptr = head;
	while (ptr != 0)
	{
		Node * victim = ptr;
		ptr = ptr->next;
		delete victim;
	}
	delete ptr;
}

int Stack :: size()
{
	return Size;
}

string Stack :: top()
{
	return head->url;
}

void Stack :: push(string s)
{
	Node * ptr = new Node;
	ptr->url = s;
	ptr->next = head;
	head = ptr;
	Size++;
}

void Stack :: pop()
{
	Node * ptr = head;
	head = head->next;
	delete ptr;
	Size--;
}

void Stack :: clear()
{
	while (head != 0)
	{
		Node * ptr = head;
		head = head->next;
		delete ptr;
	}
	Size = 0;
}
