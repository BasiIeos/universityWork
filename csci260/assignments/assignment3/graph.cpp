// Vasily Kontorer
// Assignment 3
// Implementation of methods for graph class

#include "graph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

string username(int k, map <string, int> &users)
{
	map <string, int> :: iterator it = users.begin();
	while (it->second != k)
                *it++;
	return it->first;
}

Graph :: Graph(const string &fname, bool &end, map <string, int> &users)
{
	ifstream fin;
	fin.open(fname);
	if (fin.is_open())
	{
		fin >> size;
		v.resize(size);
		for (int i = 0; i < size; i++)
			v[i].resize(size);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				v[i][j] = 0;
		vector <string> u(size);
		for (int i = 0; i < size; i++)
			fin >> u[i];
		sort(u.begin(), u.end());
		for (int i = 0; i < size; i++)
			users[u[i]] = i;
		while (!fin.eof())
		{
			string u1, u2;
			int d;
			fin >> u1;
		        if (!fin.eof())
			{
				fin >> u2 >> d;
				v[users[u1]][users[u2]] = d;
			}
		}
		fin.close();
		end = 0;
	}
	else
	{
		cout << "Couldn't find named file, please try again\n";
		end = 1;
	}
}

Graph :: ~Graph()
{
}

void Graph :: influence(map <string, int> &users)
{
	pair <int, int> maxinf = make_pair(0, -1);
	for (int i = 0; i < size; i++)
	{
		int curinf = 0;
		for (int j = 0; j < size; j++)
			if (v[i][j] == 1)
				curinf++;
		if (curinf >= maxinf.first)
		{
			maxinf.first = curinf;
			maxinf.second = i;
		}
	}
	cout << "User who can directly and positively influence the most number of the users is " << username(maxinf.second, users) << '\n';
}

void Graph :: controversial(map <string, int> &users)
{
	pair <int, int> maxinf = make_pair(0, -1);
        for (int i = 0; i < size; i++)
        {
                int curinf = 0;
                for (int j = 0; j < size; j++)
                        if ((v[i][j] == 1) || (v[i][j] == -1))
                                curinf++;
                if (curinf >= maxinf.first)
                {
                        maxinf.first = curinf;
                        maxinf.second = i;
                }
        }
	cout << "User who can directly and influence the most number of the users, either positively or negatively, is " << username(maxinf.second, users) << '\n';
}

void Graph :: outreach(int u, map <string, int> &users)
{
	vector <bool> reachable(size, 0);
	reachable[u] = true;
	for (int i = 0; i < size; i++)
		if ((!reachable[i]) && (v[u][i] != 0))
			outreach2(i, reachable);
	int ans = 0;
	for (int i = 0; i < size; i++)
		if (reachable[i])
			ans++;
	cout << "The number of the users ";
        cout << username(u, users) << "	can influence, whether directly or indirectly, positively or negatively, is " << ans - 1 << '\n';
}

void Graph :: outreach2(int u, vector <bool> &reachable)
{
	reachable[u] = true;
	for (int i = 0; i < size; i++)
		if ((!reachable[i]) && (v[u][i] != 0))
			outreach2(i, reachable);
}

void Graph :: link(int u1, int u2, map <string, int> &users)
{
	vector <pair <int, int> > dist(size, make_pair(-1, size));
	vector <bool> visited(size, 0);
	dist[u1] = make_pair(-1, 0);
	int cur = u1;
	while ((cur != u2) && (cur != -1))
	{
		for (int i = 0; i < size; i++)
			if ((v[cur][i] == 1) && (!visited[i]))
				if (dist[i].second > dist[cur].second + v[cur][i])
					dist[i] = make_pair(cur, dist[cur].second + v[cur][i]);
		visited[cur] = 1;
		pair <int, int> mindist = make_pair(size, -1);
		for (int i = 0; i < size; i++)
			if ((mindist.first > dist[i].second) && (!visited[i]))
				mindist = make_pair(dist[i].second, i);
		cur = mindist.second;
	}
	if (cur == -1)
		cout << "No link found\n";
	else
	{
		vector <int> thelink;
		cur = u2;
		while (cur != u1)
		{
			thelink.push_back(cur);
			cur = dist[cur].first;
		}
		thelink.push_back(u1);
		cout << "The shortest positive influence link from ";
		cout << username(u1, users) << " to " << username(u2, users) << ":\n";
		for (int i = thelink.size() - 1; i >= 0; i--)
			cout << username(thelink[i], users) << ' ';
		cout << '\n';
	}
}

void Graph :: update(int u1, int u2, int d, map <string, int> &users)
{
	v[u1][u2] = d;
	cout << "Updated influence from " << username(u1, users) << " to " << username(u2, users) << " to " << d << '\n';
}

void Graph :: quit(string fname, map <string, int> &users)
{
	ofstream fout;
	fout.open(fname, ios::trunc);
	fout << size << '\n';
	for (int i = 0; i < size; i++)
		fout << username(i, users) << '\n';
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (v[i][j] != 0)
				fout << username(i, users) << ' ' << username(j, users) << ' ' << v[i][j] << '\n';
	fout.close();
}
