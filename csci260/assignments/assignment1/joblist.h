// Vasily Kontorer
// Assignment 1
// Declaration of JobList class

#include "pqueue.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

class JobList
{
	private:
		struct Data
		{
			string id;
			string com;
			string res;
		};
		PQueue <double, Data> list;
	public:
		JobList(int size);
		~JobList();
		void submit();
		void execute();
		void random();
		void quit();
};
