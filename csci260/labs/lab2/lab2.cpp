#include <iostream>

using namespace std;

struct Node
{
	int * data;
	Node * next;
};

class LL
{
	private:
		Node * f;
	public:
		LL()
		{
			f = 0;
		}
		~LL()
		{
			while (f != 0)
			{
				Node * ptr = f;
				f = f->next;
				delete ptr->data;
				delete ptr;
			}
			delete f;
		}
		int add(int d)
		{
			Node * ptr = f;
			while (ptr != 0)
				ptr = ptr->next;
			ptr->data = &d;
			ptr->next = 0;
		}
		void display()
		{
			Node * ptr = f;
			while (ptr != 0)
			{
				cout << ptr->data;
				ptr = ptr->next;
			}
		}
		void traverse();
};

void LL :: traverse()
{
	Node * r = f;
	Node * p = 0;
	while (r != 0)
	{
		Node * tmp = p;
		p = r;
		r = r->next;
		p->next = tmp;
	}
	display();
	while (p != 0)
	{
		Node * tmp = r;
		r = p;
		p = p->next;
		r->next = tmp;
	}
	display();
}

int main()
{
	int n = 2;
	LL list;
	list.traverse();
	return 0;
}
