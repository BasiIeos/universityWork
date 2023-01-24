// Vasily Kontorer
// Assignment 5
// Methods of class CountryList (Clist)

#include <iostream>
#include <string>
#include <fstream>
#include "countrylist.h"

string tolowercase(string s)
{
	for (int i = 0; i < s.size(); i++)
		if ((s[i] >= 'A') && (s[i] <= 'Z'))
			s[i] += 'a' - 'A';
	return s;
}

Clist :: Clist()
{
	cout << "Please enter list to show all countries' names\n";
	cout << "       enter show to show a country's info\n";
	cout << "       enter add to add a new country\n";
	cout << "       enter remove to remove an existing country\n";
	cout << "       enter update to update a country's info\n";
	cout << "       enter help to see this menu\n";
	cout << "       enter exit to terminate this program\n";
	ifstream fin;
	fin.open("wikiCountry.txt");
	if (fin.is_open())
	{
		int n;
		fin >> n;
		string cName;
		Info cInfo;
		getline(fin, cName);
		for (int i = 0; i < n; i++)
		{
			string cName;
			getline(fin, cName);
			Info cInfo;
			getline(fin, cInfo.capital);
			getline(fin, cInfo.language);
			fin >> cInfo.area;
			fin >> cInfo.population;
			getline(fin, cInfo.description);
			getline(fin, cInfo.description);
			a.insert(cName, cInfo);
		}
		fin.close();
	}
}

Clist :: ~Clist()
{
}

void Clist :: list()
{
	a.listKeys();
}

void Clist :: show()
{
	string cName;
	cout << "Please enter a country's full name: ";
	cin >> cName;
	try {
		Info cInfo = a.find(cName);
		cout << "--------------------\n";
		cout << "       Name:" << cName << '\n';
		cout << "    capital:" << cInfo.capital << '\n';
		cout << "   language:" << cInfo.language << '\n';
		cout << "       area:" << cInfo.area << '\n';
		cout << " population:" << cInfo.population << '\n';
		cout << "description:" << cInfo.description << '\n';
	} catch (bool & e) {
		cout << "Country " << cName << " doesn't exist in the Wiki.\n";
	}
}

void Clist :: remove()
{
	cout << "Please enter a country's full name: ";
	string cName;
	cin >> cName;
	bool succRemoval = a.erase(cName);
	if (succRemoval)
		cout << "Country " << cName << " removed from the Wiki.\n";
	else
		cout << "Country " << cName << " doesn't exist in the Wiki.\n";
}

void Clist :: add()
{
	cout << "Please enter a country's full name: ";
	string cName;
	cin >> cName;
	try {
		Info cInfo = a.find(cName);
		cout << "This country is already in the Wiki.\n";
	} catch (bool & e) {
		Info cInfo;
		cout << "capital: ";
		getline(cin, cInfo.capital);
		getline(cin, cInfo.capital);
		cout << "language: ";
		getline(cin, cInfo.language);
		cout << "area: ";
		cin >> cInfo.area;
		cout << "population: ";
		cin >> cInfo.population;
		cout << "description: ";
		getline(cin, cInfo.description);
		getline(cin, cInfo.description);
		a.insert(cName, cInfo);
		cout << "New country added into the Wiki.\n";
	}
}

void Clist :: update()
{
	cout << "Please enter a country's full name: ";
	string cName;
	getline(cin, cName);
	getline(cin, cName);
	try {
		Info cInfo = a.find(cName);
		cout << "0: capital\n";
		cout << "1: language\n";
		cout << "2: area\n";
		cout << "3: population\n";
		cout << "4: description\n";
		cout << "Which field do you want to update: ";
		string s;
		getline(cin, s);
		if ((tolowercase(s) == "capital") || (s == "0"))
		{
			cout << "capital's old value: " << cInfo.capital << '\n';
			cout << "Your new value: ";
			getline(cin, cInfo.capital);
			bool c = a.erase(cName);
	                a.insert(cName, cInfo);
	                cout << "Thank you. Update completed.\n";
		}
		else if ((tolowercase(s) == "language") || (s == "1"))
		{
                        cout << "language's old value: " << cInfo.language << '\n';
			cout << "Your new value: ";
			getline(cin, cInfo.language);
			bool c = a.erase(cName);
	                a.insert(cName, cInfo);
	                cout << "Thank you. Update completed.\n";
		}
		else if ((tolowercase(s) == "area") || (s == "2"))
                {
                        cout << "area's old value: " << cInfo.area << '\n';     
                        cout << "Your new value: ";
                        cin >> cInfo.area;
			bool c = a.erase(cName);
			a.insert(cName, cInfo);
	                cout << "Thank you. Update completed.\n";
		}
		else if ((tolowercase(s) == "population") || (s == "3"))
                {
                        cout << "population's old value: " << cInfo.population << '\n';
                        cout << "Your new value: ";
                        cin >> cInfo.population;
			bool c = a.erase(cName);
	                a.insert(cName, cInfo);
	                cout << "Thank you. Update completed.\n";
		} 
		else if ((tolowercase(s) == "description") || (s == "4"))
                {
                        cout << "description's old value: " << cInfo.description << '\n';
			cout << "Your new value: ";
                        getline(cin, cInfo.description);
			bool c = a.erase(cName);
	                a.insert(cName, cInfo);
	                cout << "Thank you. Update completed.\n";
                }
		else
			cout << "You didn't choose a valid field. Make up your mind and come back again.\n";
	} catch (bool & e) {
		cout << "Country " << cName << " doesn't exist in the Wiki.\n";
	}
}

void Clist :: help()
{
	cout << "Please enter list to show all countries' names\n";
	cout << "       enter show to show a country's info\n";
        cout << "       enter add to add a new country\n";
        cout << "       enter remove to remove an existing country\n";
        cout << "       enter update to update a country's info\n";
	cout << "       enter help to see this menu\n";
        cout << "       enter exit to terminate this program\n";
}

void Clist :: exit()
{
	ofstream fout;
	fout.open("wikiCountry.txt", ios::trunc);
	int n = a.size();
	fout << a.size() << '\n';
	for (int i = 0; i < n; i++)
	{
		string cName = a.returnKey(i);
		Info cInfo = a.find(cName);
		fout << cName << '\n';
		fout << cInfo.capital << '\n';
		fout << cInfo.language << '\n';
		fout << cInfo.area << '\n';
		fout << cInfo.population << '\n';
		fout << cInfo.description << '\n';
	}
	fout.close();
}
