#include<iostream>

using namespace std;

class Data
{
	int namber;
	string name;
	friend void func(Data& ex);
	friend void func(Data* ex);
public:
	Data():namber(0),name("00")
	{}
	Data(Data& ex, int n, string str) 
	{
		ex.namber = n;
		ex.name = str;
	}
	Data(Data* ex, int n, string str)
	{
		ex->namber = n;
		(*ex).name = str;
	}
	~Data()
	{}

};

void func(Data& ex)
{
	cout << ex.namber << "   " << ex.name << endl;
}

void func(Data* ex)
{
	cout << ex->namber << "   " << (*ex).name << endl;
}


int main()
{
	
	Data d1 = Data(d1,1,"one");
	Data d2 = Data();
	Data d3;
	Data* pd3 = &d3;
	Data(pd3, 3, "three");
	func(d1);
	func(d2);
	func(pd3);
	pd3 = 0;
	return 0;
}


