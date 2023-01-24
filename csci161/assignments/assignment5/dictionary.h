// Vasily Kontorer
// Assignment 5
// Implementation of Dictionary

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename K, typename T>
class Dictionary
{
	public:
		Dictionary();
		~Dictionary();
		bool empty();
		int size();
		int max_size();
		void insert(K & k, T & t);
		bool erase(K & k);
		T find(K & k) throw (bool);
		void listKeys();
		K returnKey(int i);
	private:
		struct Entry
		{
			K key;
			T obj;
		};
		Entry * data;
		const int Cap = 200;
		int Size;
};

template <typename K, typename T>
Dictionary <K, T> :: Dictionary()
{
	data = new Entry[Cap];
	Size = 0;
}

template <typename K, typename T>
Dictionary <K, T> :: ~Dictionary()
{
	delete [] data;
}

template <typename K, typename T>
bool Dictionary <K, T> :: empty()
{
	return (Size == 0);
}

template <typename K, typename T>
int Dictionary <K, T> :: size()
{
	return Size;
}

template <typename K, typename T>
int Dictionary <K, T> :: max_size()
{
	return Cap;
}

template <typename K, typename T>
void Dictionary <K, T> :: insert(K & k, T & t)
{
	bool diff = true;
	for (int i = 0; ((i < Size) && (diff)); i++)
		if (data[i].key == k)
			diff = false;
	if ((diff) && (Size < Cap))
	{
		data[Size].key = k;
		data[Size].obj = t;
		Size++;
	}
}

template <typename K, typename T>
bool Dictionary <K, T> :: erase(K & k)
{
	bool exists = false;
	int i = 0;
	while ((i < Size) && (!exists))
	{
		if (data[i].key == k)
			exists = true;
		else
			i++;
	}
	if (!exists)
		return false;
	for (int j = i; j < Size - 1; j++)
	{
		data[j].key = data[j + 1].key;
		data[j].obj = data[j + 1].obj;
	}
	Size--;
	return true;
}

template <typename K, typename T>
T Dictionary <K, T> :: find(K & k) throw (bool)
{
	bool found = false;
	int i = 0;
	while ((i < Size) && (!found))
	{
		if (data[i].key == k)
			found = true;
		else
			i++;
	}
	if (!found)
		throw false;
	return data[i].obj;
}

template <typename K, typename T>
void Dictionary <K, T> :: listKeys()
{
	for (int i = 0; i < Size; i++)
		cout << data[i].key << '\n';
}

template <typename K, typename T>
K Dictionary <K, T> :: returnKey(int i)
{
	return data[i].key;
}
