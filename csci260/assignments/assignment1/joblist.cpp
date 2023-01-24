// Vasily Kontorer
// Assignment 1
// Methods for JobList class

#include "joblist.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

JobList :: JobList(int size)
{
	list.resize(size);
	cout << "Welcome to computer job queue!\n";
	cout << "Enter submit to submit a new job: enter positive floating pointnumber as job's estimated execution time, a user id, a command name and a line to describe the resorses the job requires on separated lines after submit command\n";
	cout << "Enter execute to execute a job with the shortest estimated time\n";
	cout << "Enter random to execute a random job\n";
	ifstream fin;
	fin.open("batch.txt");
	if (fin.is_open())
	{
		int n;
		fin >> n;
		for (int i = 0; i < n; i++)
		{
			double t;
			fin >> t;
			Data newData;
			// 2 times getline for 1 variable to make it work, after reading with a normal cin getline reads \n after number as a line
			getline(fin, newData.id);
			getline(fin, newData.id);
			getline(fin, newData.com);
			getline(fin, newData.res);
			list.insert(t, newData);
		}
		fin.close();
	}
	else
		cout << "Didn't find a file batch.txt, starting with empty list\n";
}

JobList :: ~JobList()
{
}

void JobList :: submit()
{
	double Time;
	cout << "Please provide a positive floating point number as the job's estimated execution time\n";
	cin >> Time;
	while (Time <= 0)
	{
		cout << "Estimated time should be a positive floating point number, please try again\n";
		cin >> Time;
	}
	Data newData;
	getline(cin, newData.id);
	cout << "Please provide a user id\n";
	getline(cin, newData.id);
	cout << "Please provide a command name\n";
	getline(cin, newData.com);
	cout << "Please provide a line to describe the resources the job requires\n";
	getline(cin, newData.res);
	bool t = list.insert(Time, newData);
	if (t)
		cout << "Successfully submitted a new job\n";
	else
		cout << "Can't submit a new job, queue is full\n";
}

void JobList :: execute()
{
	try 
	{
		pair <double, Data> someJob;
		someJob = list.pop();
		cout << "Successfully executed a job\n";
		cout << "Time: " << someJob.first << '\n';
		cout << "ID: " << someJob.second.id << '\n';
		cout << "Command name: " << someJob.second.com << '\n';
		cout << "Resources: " << someJob.second.res << '\n';
	}
	catch (int error)
	{
		cout << "Can't execute a job, queue is empty\n";
	}
}

void JobList :: random()
{
	try 
        {
                pair <double, Data> someJob;
                someJob = list.removernd();
                cout << "Successfully executed a random job\n";
                cout << "Time: " << someJob.first << '\n';
                cout << "ID: " << someJob.second.id << '\n';
                cout << "Command name: " << someJob.second.com << '\n';
                cout << "Resources: " << someJob.second.res << '\n';
	}
	catch (int error)
	{
	       cout << "Can't execute a job, queue is empty\n";
	}
}

void JobList :: quit()
{
	ofstream fout;
	fout.open("batch.txt", ios::trunc);
	int n = list.size();
	fout << n << '\n';
	for (int i = 0; i < n; i++)
	{
		pair <double, Data> someJob;
		someJob = list.pop();
		fout << someJob.first << '\n';
		fout << someJob.second.id << '\n';
		fout << someJob.second.com << '\n';
		fout << someJob.second.res << '\n';
	}
	fout.close();
}
