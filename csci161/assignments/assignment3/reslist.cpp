#include "reslist.h"
#include <iostream>
#include <fstream>
#include <string>

// Implementation of methods for classes ReservationList and Reservation

using namespace std;

int Res :: hour()
{
	return Hour;
}

int Res :: minute()
{
	return Minute;
}

string Res :: address()
{
	return Address;
}

string Res :: name()
{
	return Name;
}

bool Res :: date()
{
	return Date;
}

void Res :: newHour(int h)
{
	Hour = h;
}

void Res :: newMinute(int m)
{
	Minute = m;
}

void Res :: newAddress(string a)
{
	Address = a;
}

void Res :: newName(string n)
{
	Name = n;
}

void Res :: newDate(bool t)
{
	Date = t;
}

int ResList :: count = 0;
int ResList :: countt = 0;

ResList :: ~ResList()
{
	head = head->next;
	Node* ptr;
	while (head != 0)
	{
		ptr = head;
		head = head->next;
		delete ptr->data;
		delete ptr;
	}
	delete head;
}

void ResList :: submit()
{
	cout << "Please enter the hour of the pick up time.\n";
	int h;
	cin >> h;
	while ((h < 0) || (h > 59))
	{
		cout << "The number must be in the range of 0 and 23. Enter again.\n";
		cin >> h;
	}
	cout << "Please enter the minute of the pick up time.\n";
	int m;
	cin >> m;
	while ((m < 0) || (m > 59))
	{
		cout << "The number must be in the range of 0 and 59. Enter again.\n";
		cin >> m;
	}
	cout << "Please enter the pick up location\n";
	string a;
	getline(cin, a);
	getline(cin, a);
	while (a == "")
	{
		cout << "The string must NOT be an empty one. Enter again.\n";
		getline(cin, a);
	}
	cout << "Please enter the name of the contact\n";
	string n;
	getline(cin, n);
	while (n == "")
	{
		cout << "The string must NOT be an empty one. Enter again.\n";
		getline(cin, n);
	}
	bool t;
	cout << "Is the reservation for today (Y) or tomorrow (N)?\n";
	char t1;
	cin >> t1;
	while ((t1 != 'Y') && (t1 != 'y') && (t1 != 'N') && (t1 != 'n'))
	{
		cout << "Is the reservation for today (Y) or tomorrow (N)?\n";
		cin >> t1;
	}
	if ((t1 == 'Y') || (t1 == 'y'))
		t = true;
	else
		t = false;
	
	Node* ptr = head;
	if (!t)
	{
		countt++;
		while ((ptr->next != 0) && (ptr->next->data->date()))
			ptr = ptr->next;
		cout << "Reservation successfully added to tomorrow's list.\n";
	}
	else
	{
		count++;
		cout << "Reservation successfully added to today's list.\n";
	}
	
	while ((ptr->next != 0) && (ptr->next->data->date()) && 
	       (ptr->next->data->hour() * 60 + ptr->next->data->minute() < h * 60 + m))
		ptr = ptr->next;

	Node* newN = new Node;
	newN->data = new Res;
	newN->data->newHour(h);
	newN->data->newMinute(m);
	newN->data->newAddress(a);
	newN->data->newName(n);
	newN->data->newDate(t);
	newN->next = ptr->next;
	ptr->next = newN;
}

void ResList :: pickup()
{
	if ((head->next == 0) || (!head->next->data->date()))
		cout << "There is currently no reservation in the reservation list.\n";
	else
	{
		Node* victim = head->next;
		head->next = head->next->next;
		cout << "    pick up time: " << victim->data->hour() << ':';
	        cout << victim->data->minute() << "\n";
		cout << "pick up location: " << victim->data->address() << "\n";
		cout << "    contact name: " << victim->data->name() << "\n";
		cout << "The information of this reservation has passed to a taxi driver.\n";
		delete victim->data;
		delete victim;
	}
}

void ResList :: list()
{
	if ((head->next == 0) || (!head->next->data->date()))
		cout << "There is currently no reservation in the reservation list.\n";
	else
	{
		Node* ptr = head;
		while ((ptr->next != 0) && (ptr->next->data->date()))
		{
			ptr = ptr->next;
			cout << "    pick up time: " << ptr->data->hour() << ':';
			cout << ptr->data->minute() << "\n";
			cout << "pick up location: " << ptr->data->address() << "\n";
			cout << "    contact name: " << ptr->data->name() << "\n";
			cout << "------------\n";
		}
	}
}

void ResList :: help()
{
	cout << "Enter S to submit a new reservation\n";
	cout << "   or P to pick up the passenger(s)\n";
	cout << "   or L to list all reservations\n";
	cout << "   or H for help (displays this menu)\n";
	cout << "   or T to terminate this program\n";
}

bool ResList :: term()
{
	if ((head->next == 0) || (!head->next->data->date()))
	{
		cout << "The total number of reservations processed is " << count << ".\n";
		ofstream fout;
		fout.open("reservations.txt", ios::trunc);
		fout << countt << "\n";
		Node* ptr = head;
		while (ptr->next != 0)
		{
			fout << ptr->next->data->hour() << ' ' << ptr->next->data->minute() << "\n";
			fout << ptr->next->data->address() << "\n";
			fout << ptr->next->data->name() << "\n";
			ptr = ptr->next;
		}
		fout.close();
		return true;
	}
	cout << "Program can not terminate.\n";
	cout << "There are still reservations in the reservations list.\n";
	return false;
}


ResList :: ResList()
{
	cout << "*** Welcome to Taxi Reservation Management System ***\n\n";
	head = new Node;
	head->next = 0;
	ifstream fin;
	fin.open("reservations.txt");
	if (!fin.is_open())
	{
		cout << "Can't open reservations.txt to read data.\n";
		cout << "Assuming that there is no reservation made yesterday.\n";
	}
	else
	{
		int n;
		fin >> n;
		count += n;
		for (int i = 0; i < n; i++)
		{
			int h, m;
			fin >> h >> m;
			string a, n;
			getline(fin, a);
			getline(fin, a);
			getline(fin, n);
			bool t = true;
			Node* ptr = head;
			while ((ptr->next != 0) && (ptr->next->data->hour() * 60 + ptr->next->data->minute() < h * 60 + m))
				ptr = ptr->next;
			Node* newN = new Node;
			newN->data = new Res;
			newN->data->newHour(h);
			newN->data->newMinute(m);
			newN->data->newAddress(a);
			newN->data->newName(n);
			newN->data->newDate(t);
			newN->next = ptr->next;
			ptr->next = newN;
		}
		fin.close();
	}
	cout << "\n";
	cout << "Enter S to submit a new reservation\n";
	cout << "   or P to pick up the passenger(s)\n";
	cout << "   or L to list all reservations\n";
	cout << "   or H for help (displays this menu)\n";
	cout << "   or T to terminate this program\n\n";
}
