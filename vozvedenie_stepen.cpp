#include<iostream>
using namespace std;
int func(int, int);

int main()
{
	setlocale(LC_ALL, "rus");

	int n = 0;
	int m = 0;
	cout << "¬ведите число : ";
	cin >> n;
	cout << "¬ведите степень : ";
	cin >> m;
	cout << func(n, m);
	return 0;
}

int func(int n, int m)
{
	if (m  == 0)
		return 1;
	if (m % 2 == 0)
	{
		return func(n * n , m / 2);
	}
	return func(n * n , m / 2) * n;
}