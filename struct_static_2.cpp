#include<iostream>
using namespace std;

struct Data
{
	int chislitel;
	int znamenatel;
};

void func(Data a, Data b)
{
	float result = (float)a.chislitel / a.znamenatel * b.chislitel / b.znamenatel;
	cout << a.chislitel << "/" << a.znamenatel << " * " << b.chislitel << "/" << b.znamenatel << " = " << result << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Data drob1, drob2;
	cout << "������� ��������� ������ �����  ";
	cin >> drob1.chislitel;
	cout << "������� ����������� ������ �����  ";
	cin >> drob1.znamenatel;
	cout << "������� ��������� ������ �����  ";
	cin >> drob2.chislitel;
	cout << "������� ����������� ������ �����  ";
	cin >> drob2.znamenatel;
	func(drob1, drob2);
	return 0;
}