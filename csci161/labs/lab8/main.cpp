#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
	Queue <int> q(10);
	int x = 1;
	q.push(x);
	//x = q.pop();
	cout << x;
	return 0;
}

