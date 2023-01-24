//Main file for Assignment 2 program
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include "triple.h"

using namespace std;

// function to check if all the values in the compiled answer comply with the constraints
bool check(vector <unsigned long long> &answer, vector <Triple> &constraints)
{
	for (int i = 0; i < constraints.size(); i++)
		if ((answer[constraints[i].first()] != 0) && (answer[constraints[i].second()] != 0) && (answer[constraints[i].third()] != 0)) // if any of them are not touched yet these values comply
			if (((answer[constraints[i].first()] > answer[constraints[i].second()]) || (answer[constraints[i].second()] > answer[constraints[i].third()])) 
					&& ((answer[constraints[i].second()] > answer[constraints[i].third()]) || (answer[constraints[i].third()] > answer[constraints[i].first()])) 
					&& ((answer[constraints[i].third()] > answer[constraints[i].first()]) || (answer[constraints[i].first()] > answer[constraints[i].second()])))
				return false;
	return true;
}

bool magic(vector <unsigned long long> &answer, vector <Triple> &constraints, int &nOUsed, const vector <int> &sortedFrequency, vector <int> &used, const int &nOSymbols)
{
	// end case, we sorted it all so we can return true
	if (nOUsed == nOSymbols)
		return true;
	
	// find which variable to use: the most constrained variable is the one that is used the most in the constraints that we have not used in the solution yet
	int usingVariable = sortedFrequency[nOUsed];
	// the start value; 2^((nOSymbols - (nOUsed + 1)) is the value we can use or add this value to the ones already used to not limit any further values (kind of using LCV principle)
	int startValue = 1<<(nOSymbols - (nOUsed + 1));
	//check the start value first
	answer[usingVariable] = startValue;
	if (check(answer, constraints))
	{
		// we can use this variable with this value, store it as used, add 1 to number of used, go down a branch and check
		used[nOUsed] = usingVariable;
		nOUsed++;
		bool possible = magic(answer, constraints, nOUsed, sortedFrequency, used, nOSymbols);
		if (possible)
			return true;
		// if this branch is a dead end, reduce number of used
		nOUsed--;
	}
	// now check start value added to all other used values
	for (int i = 0; i < nOUsed; i++) 
	{
		// similar work to just the start value, but we add one of the already used values
		answer[usingVariable] = startValue + answer[used[i]];
		if (check(answer, constraints))
		{
			used[nOUsed] = usingVariable;
			nOUsed++;
			bool possible = magic(answer, constraints, nOUsed, sortedFrequency, used, nOSymbols);
			if (possible)
				return true;
			nOUsed--;
		}
	}
	// none of the branches worked, so we erase the value we tried to use for this variable, say that it is not used and say that this branch is a dead end
	answer[usingVariable] = 0;
	used[nOUsed] = -1;
	return false;
}

int main(int argc, char* argv[])
{
	// read the file
	ifstream fin(argv[1]);
	if (!fin.is_open())
	{
		cout << "The name of the test file is entered incorrectly, please try again\n";
		return 0;
	}
	int nOSymbols, nOTriples;
	fin >> nOSymbols;
	if (nOSymbols > 64)
	{
		cout << "Sorry, too many variables! Try an easier test :)\n";
		fin.close();
		return 0;
	}
	vector <string> symbols(nOSymbols);
	for (int i = 0; i < nOSymbols; i++)
		fin >> symbols[i];
	fin >> nOTriples;
	vector <Triple> constraints(nOTriples);
	// start saving frequency for each variable
	vector <int> frequency(nOSymbols, 0);
	for (int i = 0; i < nOTriples; i++)
	{
		string input[3];
		int sortedInput[3];
		for (int k = 0; k < 3; k++)
		{
			fin >> input[k];
			for (int j = 0; j < nOSymbols; j++)
				if (symbols[j] == input[k])
					sortedInput[k] = j;
			frequency[sortedInput[k]]++;
		}
		Triple newT = Triple(sortedInput[0], sortedInput[1], sortedInput[2]);
		constraints[i] = newT;
	}
	fin.close();
	
	// sort symbols by frequency (use of MCV, most frequent variable is most constrained one)
	vector < pair <int, int> > sortingFrequencies(nOSymbols);
	for (int i = 0; i < nOSymbols; i++)
		sortingFrequencies[i] = make_pair(frequency[i], i);
	sort(sortingFrequencies.rbegin(), sortingFrequencies.rend());
	vector <int> sortedFrequency(nOSymbols);
	for (int i = 0; i < nOSymbols; i++)
		sortedFrequency[i] = sortingFrequencies[i].second;
	
	//make the variables to be referenced
	vector<unsigned long long> answer(nOSymbols, 0);
	int nOUsedVariables = 0;
	vector <int> used(nOSymbols, -1);
	bool possible = magic(answer, constraints, nOUsedVariables, sortedFrequency, used, nOSymbols);
	if (!possible)
		cout << "The problem has no solutions :(\n";
	else
	{
		cout << "Found a solution to the problem!\n";

		// make a good answer from the one we got by reducing all the values to [1;nOSymbols]
		vector < pair <unsigned long long, int> > sorting(nOSymbols);
		for (int i = 0; i < nOSymbols; i++)
			sorting[i] = make_pair(answer[i], i);
		sort(sorting.begin(), sorting.end());
		vector <int> goodAnswer(nOSymbols);
		for (int i = 0; i < nOSymbols; i++)
			goodAnswer[sorting[i].second] = i + 1;
		
		for (int i = 0; i < nOSymbols; i++)
			cout << symbols[i] << '=' << goodAnswer[i] << '\n';
	}
	return 0;
}
