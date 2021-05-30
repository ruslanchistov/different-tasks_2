#include<iostream>
using namespace std;

struct Bit
{
	unsigned short a : 5;   
	unsigned short b : 4;
	unsigned short c : 5;
	unsigned short d : 4;
	unsigned short e : 4;
	unsigned short f : 4;
	unsigned short g : 5;
	
} A;

int main()
{
	cout << sizeof(Bit);
	return 0;
}