#include<iostream>
#include"Data.h"
int main()
{
	Data ex;
	int c;
	std::cout << "enter code  ";
	std::cin >> c;
	ex.set_show(c);
	return 0;
}