#include<iostream>
using namespace std;

struct Data
{
	const char* name;
	int namber;
	float drob;
};

int main()
{
	Data a, b, c, d;

	Data* pc = 0;
	pc = &c;

	Data* pd = &d;

	a.name = "abcd";
	a.namber = 1;
	(&a) -> drob = 1.1;

	b = { "xyz",2,2.2 };

	pc -> name = "iklmn";
	(*pc).namber = 3;
	pc->drob = 3.3;

	(*pd) = {"oprst", 4, 4.4};

	cout << a.name << "\t" << a.namber << "\t" << a.drob << "\t" << "\n";
	cout << b.name << "\t" << b.namber << "\t" << b.drob << "\t" << "\n";
	cout << c.name << "\t" << c.namber << "\t" << c.drob << "\t" << "\n";
	cout << d.name << "\t" << d.namber << "\t" << d.drob << "\t" << "\n";

	pc = 0;
	pd = 0;
	return 0;
}