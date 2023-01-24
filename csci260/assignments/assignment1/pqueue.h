// Vasily Kontorer
// Assignment 1
// Declaration and methods for tmeplate class PQueue 

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename K, typename T> 
class PQueue
{
	private:
		struct Entry
		{
			K pos;
			T obj;
		};
		vector <Entry> queue;
		int Size;
	public:
		PQueue();
		void resize(int newSize);
		~PQueue();
		int size();
		bool insert(K & k, T & t);
		bool remove();
		pair <K, T> pop() throw (int);
		pair <K, T> removernd() throw (int);
};

template <typename K, typename T>
PQueue <K, T> :: PQueue()
{
	vector <Entry> queue (10);
	Size = 0;
}

template <typename K, typename T>
void PQueue <K, T> :: resize(int newSize)
{
	queue.resize(newSize);
}

template <typename K, typename T>
PQueue <K, T> :: ~PQueue()
{
}

template <typename K, typename T>
int PQueue <K, T> :: size()
{
	return Size;
}

template <typename K, typename T>
bool PQueue <K, T> :: insert(K & k, T & t)
{
	if (queue.size() == Size)
		return 0;
	Entry e;
	e.pos = k;
	e.obj = t;
	queue[Size] = e;
	int i = Size;
	while ((i != 0) && (queue[i].pos < queue[(i - 1) / 2].pos))
	{
		swap(queue[i], queue[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
	Size++;
	return 1;
}

template <typename K, typename T>
bool PQueue <K, T> :: remove()
{
	if (Size == 0)
		return 0;
	swap(queue[Size - 1], queue[0]);
	int i = 0;
	Size--;
	while (((2 * i + 1 < Size) && (queue[i].pos > queue[2 * i + 1].pos)) || ((2 * i + 2 < Size) && (queue[i] > queue[2 * i + 2].pos)))
	{
		if ((2 * i + 2 < Size) && (queue[2 * i + 1].pos <= queue[2 * i + 2].pos))
		{
			swap(queue[i], queue[2 * i + 1]);
			i = 2 * i + 1;
		}
		else
		{
			swap(queue[i], queue[2 * i + 2]);
			i = 2 * i + 2;
		}
	}
	return 1;
}

template <typename K, typename T>
pair <K, T> PQueue <K, T> :: pop() throw (int)
{
	if (Size == 0)
	{
		int error = 0;
		throw error;
	}
	swap(queue[Size - 1], queue[0]);
        int i = 0;
	Size--;
        while (((2 * i + 1 < Size) && (queue[i].pos > queue[2 * i + 1].pos)) || ((2 * i + 2 < Size) && (queue[i].pos > queue[2 * i + 2].pos)))
        {
                if ((2 * i + 2 < Size) && (queue[2 * i + 1].pos <= queue[2 * i + 2].pos))
                {
                        swap(queue[i], queue[2 * i + 1]);
                        i = 2 * i + 1;
                }
                else
                {
                        swap(queue[i], queue[2 * i + 2]);
                        i = 2 * i + 2;
                }
	}
	pair <K, T> answer;
	answer.first = queue[Size].pos;
	answer.second = queue[Size].obj;
	return answer;
}

template <typename K, typename T>
pair <K, T> PQueue <K, T> :: removernd() throw (int)
{
        if (Size == 0)
	{
		int error = 0;
		throw error;
	}
	int i = rand() % Size;
        swap(queue[Size - 1], queue[i]);
	Size--;
        while (((2 * i + 1 < Size) && (queue[i].pos > queue[2 * i + 1].pos)) || ((2 * i + 2 < Size) && (queue[i].pos > queue[2 * i + 2].pos)))
        {
                if ((2 * i + 2 < Size) && (queue[2 * i + 1].pos <= queue[2 * i + 2].pos))
                {
                        swap(queue[i], queue[2 * i + 1]);
                        i = 2 * i + 1;
                }
                else
                {
                        swap(queue[i], queue[2 * i + 2]);
                        i = 2 * i + 2;
                }
        }
	pair <K, T> answer;
        answer.first = queue[Size].pos;
	answer.second = queue[Size].obj;
	return answer;
}
