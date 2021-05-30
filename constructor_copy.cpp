#include<iostream>
using namespace std;

class Data
{
	string name;
	int namber;
	friend void func(Data&);
public:
	Data():name("0"),namber(0)
	{
	}
	Data(Data& ex, string str, int n)
	{
		ex.name = str;
		ex.namber = n;
	}
	Data( const Data& ex)
	{
		name = ex.name;
		namber = ex.namber;
	}
	~Data()
	{
	}
};

void func(Data& ex)
{
	cout << ex.namber << "   " << ex.name << endl;
}

int main()
{
	Data a ;
	Data b = Data(b, "abc", 5);	
	Data c = Data(b); 
	
	func(a);
	func(b);
	func(c);
	return 0;
}


