#include<iostream>
using namespace std;

template<class A,class B>
void func(A a, B b)
{
	if (a > b)
		cout<<"max = "<< a << endl;
	else
		cout << "max = " << b << endl;
}

int main()
{
	int a = 10;
	float b = 19.5;
	func(a, b);
	return 0;
}


