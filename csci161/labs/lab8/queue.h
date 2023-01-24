// Vasily Kontorer
// lab 8
// Implementation of template queue class and of it's methods

#include <iostream>

using namespace std;

template <typename T>
class Queue
{
	public:
		Queue(int cap);
		~Queue();
		bool empty();
		int size();
		T front();
		T back();
		void push(T & obj);
		T pop();
	private:
		struct Node
		{
			T * data;
			Node * next;
		};
		Node * head;
		int Size;
		int Cap;
};

template <typename T>
Queue <T> :: Queue(int cap)
{
	head = new Node;
	head = 0;
	Cap = cap;
	Size = 0;
}

template <typename T>
Queue <T> :: ~Queue()
{
	while (head != 0)
	{
		Node * victim = head;
		head = head->next;
		delete victim->data;
		delete victim;
	}
	delete head;
}

template <typename T>
bool Queue <T> :: empty()
{
	return (Size == 0);
}

template <typename T>
int Queue <T> :: size()
{
	return Size;
}

template <typename T>
T Queue <T> :: front()
{
	if (Size > 0)
		return head->data;
	else
	{
		T rnd;
		return rnd;
	}
}

template <typename T>
T Queue <T> :: back()
{
	if (Size == 0)
	{
		T rnd;
		return rnd;
	}
	Node * ptr = head;
	while (ptr->next != 0)
		ptr = ptr->next;
	return ptr->data;
}

template <typename T>
void Queue <T> :: push(T & obj)
{
	if (Size < Cap)
	{
		Node * ptr = head;
		while (ptr != 0)
			ptr = ptr->next;
		ptr->data = new T;
		*(ptr->data) = obj;
		ptr->next = 0;
		Size++;
	}
	else
		cout << "Max size reached. Can't push anything in this queue\n";
}

template <typename T>
T Queue <T> :: pop()
{
	if (Size == 0)
	{
		T rnd;
		return rnd;
	}
	Size--;
	Node * victim = head;
	head = head->next;
	T value = *(victim->data);
	delete victim->data;
	delete victim;
	return value;
}
