#include <iostream>

using namespace std;

int square(int x)
{
	return x*x;
}

int* map(int f(int), int a[], int size)
{
	int *result = a;
	for (int i = 0; i < size; i++)
		result[i] = f(result[i]);
	return result;
}

int main()
{
	int arr[3] = { 1, 2, 10 };
	int *result = map(square, arr, 3);
	for (int i = 0; i < 3; i++)
		cout << result[i] << ' ';
	cout << '\n';
	return 0;
}
