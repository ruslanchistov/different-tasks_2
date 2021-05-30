#include<iostream>
using namespace std;
#include<string>
class A
{
	string name;
public:
	A(string name)
	{
		this->name = name;
	}
	string get_name()
	{
		return this->name;
	}

	friend A operator + (A& A1, A& A2);
	~A()
	{}
};


A operator + (A& A1, A& A2)
{
	return A(A1.get_name() + A2.get_name());
}

int main()
{
	A A1("abcd");
	A A2("EFGHI");
	A A3 = A1 + A2;
	cout << A3.get_name()<<endl;
	
	return 0;
}

