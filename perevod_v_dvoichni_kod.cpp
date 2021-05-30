#include<iostream>
#include<cstring>
#include <Windows.h>
using namespace std;
void fanc(int);

int main()
{
	SetConsoleCP(1251);
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "rus");
	cout << "Enter namber : ";
	int n = 0;
	cin >> n;
	if (n == 0)	
		cout << n;
	else
	fanc(static_cast<unsigned int> (n));
	return 0;
}

 void fanc(int n)
{
	 if (n != 0)
	 {
		 fanc(n / 2);
		 cout << n % 2;
	 }
	 else
		 return ;
}