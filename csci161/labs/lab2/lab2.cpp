#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Record
{
	string keyword;
	string explain;
};

struct Node
{
	Record * data;
	Node * next;
};

Node * createEmptyList()
{
	Node * list = new Node;
	list->next = 0;
	return list;
}

void insert(Node * list, Record * data)
{
	Node * ptr = new Node;
	ptr->data = data;
	ptr->next = list->next;
	list->next = ptr;
}

void deleteList (Node * list)
{
	list = list->next;
	Node * ptr;
	while (list != 0)
	{
		ptr = list;
		list = list->next;
		delete ptr->data;
		delete ptr;
	}
}

string lookup (Node * head, string key)
{
	Node * ptr = head;
	while (ptr->next != 0 && ptr->next->data->keyword != key)
		ptr = ptr->next;
	if (ptr->next == 0)
		return "No such Keyword";
	else
		return ptr->next->data->explain;
}

void loadData (Node * list, const char filename[])
{
	ifstream fin;
	fin.open(filename);
	int numEntries;
	fin >> numEntries;
	for (int i = 0; i < numEntries; i++)
	{
		Record * ptr = new Record;
		fin >> ptr->keyword;
        char c;
        fin >> c;
		getline(fin, ptr->explain);
		insert(list, ptr);
	}
	fin.close();
}

int main()
{
	Node * list = createEmptyList();
	loadData(list, "TechDictionary.txt");
	string keyword;
	cin >> keyword;
	while (keyword != "shutdown")
	{
		cout << lookup(list, keyword) << endl;
		cin >> keyword;
	}
	deleteList(list);
}
