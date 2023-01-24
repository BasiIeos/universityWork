// Vasily Kontorer
// Student No: 654975481

#include <iostream>
#include <stack>

using namespace std;

void calculateSpan(double x[], int size, int s[])
{
	stack <int> ind;
	for (int i = 0; i < size; i++)
	{
		while ((!ind.empty()) && (x[i] > x[ind.top()]))
			ind.pop();
		if (ind.empty())
			s[i] = i + 1;
		else
			s[i] = i - ind.top();
		ind.push(i);
	}
}

int main()
{
	int n;
	cin >> n;
	double x[n];
	for (int i = 0; i < n; i++)
		cin >> x[i];
	int s[n];
	calculateSpan(x, n, s);
	for (int i = 0; i < n; i++)
		cout << s[i] << ' ';
	cout << endl;
	return 0;
}
