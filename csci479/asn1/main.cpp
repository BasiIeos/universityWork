#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include "trie.h"

using namespace std;

int countCompletedTubes(string state, int nOTubes)
{
	int count = 0;
	for (int i = 0; i < nOTubes; i++)
	{
		if ((state[i * 4 + 0] == state[i * 4 + 1]) && (state[i * 4 + 0] == state[i * 4 + 2]) && (state[i * 4 + 0] == state[i * 4 + 3]))
			count++;
	}
	return count;
}

string magic(string start, int nOTubes)
{
	cout << "Solving...\n";
	
	queue<string>* priorityQueue = new queue<string>[nOTubes + 1];
	priorityQueue[countCompletedTubes(start, nOTubes)].push(start);

	Trie visited;
	visited.add(start, -1, -1);

	bool empty = false;
	while (!empty) {
		int k = nOTubes;
		// find max number of solved tubes
		while ((priorityQueue[k].empty()) && (k >= 0))
			k--;
		// check if the magic worked
		if (k == nOTubes)
		{
			// magic worked, compile moves
			string curState = priorityQueue[k].front(), toPrint = "";
			pair <int, int> fromTo = visited.givePrev(curState);
			while (fromTo.first != -1)
			{
				toPrint = "Move ball from tube " + to_string(fromTo.first / 4 + 1) + " to tube " + to_string(fromTo.second / 4 + 1) + "\n" + toPrint;
				curState[fromTo.first] = curState[fromTo.second];
				curState[fromTo.second] = ' ';
				fromTo = visited.givePrev(curState);
			}
			toPrint = "Solution found! Here's the algorithm:\n" + toPrint;
			return toPrint;
		}
		else if (k == -1)
		{
			// no magic can help here
			empty = true;
		}
		else
		{
			// make moves from the "best" state
			string stateToMoveFrom = priorityQueue[k].front();
			priorityQueue[k].pop();
			for (int i = 0; i < nOTubes; i++)
			{
				// check every tube if there is a ball in it to move
				int from = i * 4 + 3;
				while ((from > i * 4 - 1) && (stateToMoveFrom[from] == ' '))
					from--;
				if (from > i * 4 - 1)
				{
					//there is a ball here, check where it can be dropped and queue in the new states
					for (int j = 0; j < nOTubes; j++)
						if (j != i)
						{
							int to = j * 4 + 4;
							while ((to > j * 4) && (stateToMoveFrom[to - 1] == ' '))
								to--;
							if (to < j * 4 + 4)
							{
								// there is space in this tube, make a state, check if it has already existed and if not queue it in
								string newState = stateToMoveFrom;
								newState[to] = newState[from];
								newState[from] = ' ';
								if (!visited.contains(newState))
								{
									visited.add(newState, from, to);
									priorityQueue[countCompletedTubes(newState, nOTubes)].push(newState);
								}
							}
						}
				}
			}
		}
	}
	string toPrint = "No solution found!\n";
	return toPrint;
}

int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);
	int nOFull, nOEmpty;
	if (!fin.is_open())
	{
		cout << "The name of the test file is entered incorrectly, please try again";
		return 0;
	}
	fin >> nOFull >> nOEmpty;
	string input, start = "";
	for (int i = 0; i < nOFull; i++)
	{
		fin >> input;
		start += input;
	}
	for (int i = 0; i < nOEmpty; i++)
	{
		start += "    "; //a space for each empty spot
	}
	cout << magic(start, nOFull + nOEmpty);
	return 0;
}
