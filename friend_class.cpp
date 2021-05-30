#include<iostream>
#include<string>
using namespace std;
class A
{
	int data;
	friend class B;
public:
	A(int d)
	{
		data = d;
	}
	~A()
	{
	}

};
class B
{
	 int data;
public:
	 void show(A  ex)
	{
		cout << "aex1  "<< ex.data << endl;	
	}
	void show()
	{
		data = 20;
		cout << "bex1  "<< data << endl;
	}
};
int main()
{
	A aex1(10);
    B bex1;
	bex1.show(aex1);
	bex1.show();
	
	return 0;
}
