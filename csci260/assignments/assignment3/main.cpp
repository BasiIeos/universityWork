// Vasily Kontorer
// Assignment 3
// Main file

#include "graph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

int main(int argc, char * argv[])
{
	map <string, int> users;
	bool end;
	const string fname = string(argv[1]);
	Graph web(fname, end, users);
	if (end)
		return 0;
	string command;
	cin >> command;
	while (command != "quit")
	{
		if (command == "influence")
			web.influence(users);
		else if (command == "controversial")
			web.controversial(users);
		else if (command == "outreach")
		{
			string user;
			cin >> user;
			web.outreach(users[user], users);
		}
		else if (command == "link")
		{
			string user1, user2;
			cin >> user1 >> user2;
			web.link(users[user1], users[user2], users);
		}
		else if (command == "update")
		{
			string user1, user2;
			int dist;
			cin >> user1 >> user2 >> dist;
			web.update(users[user1], users[user2], dist, users);
		}
		else
		{
			cout << "Wrong command, list of possible commands:\n";
			cout << "influence\n";
			cout << "controversial\n";
			cout << "outreach ~user\n";
			cout << "link ~user1 ~user2\n";
			cout << "update ~user1 ~user2 ~distance\n";
		}
		cin >> command;
	}
	web.quit(fname, users);
	return 0;
}
