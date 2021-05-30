#include<iostream>
using namespace std;

struct Bit
{
	unsigned short data : 5;
	unsigned short mont : 4;
	unsigned short year : 11;
	unsigned short hour : 5;
	unsigned short minutes : 6;
	
} A;

int main()
{
	A.data = 3;
	A.mont = 11;
	A.year = 2020;
	A.hour = 18;
	A.minutes = 5;
	cout << A.data << "." << A.mont << "." << A.year << "     " << A.hour << ":" << A.minutes << endl;
	cout << sizeof(Bit);
	return 0;
}