#include<iostream>
using namespace std;

struct Advertising
{
	int counter;
	float persons;
	int price;
} result;

void func(Advertising res)
{
	cout << "�� �������� " << res.counter << "  ����������." << endl;
	cout << "�� ���������� ������  " << res.persons << "  ��������� �����������." << endl;
	cout << "�� ���� ������� �� ����������  " << res.price << "  ������." << endl;
	float summa = res.counter * res.persons / 100 * res.price ;
	cout << "�� ����������  " <<summa << "������." << endl;
 }



int main()
{
	setlocale(LC_ALL, "rus");
	cout << endl << "������� ���������� �� �������� :  ";
	cin >> result.counter;
	cout << endl << "������� ��������� ����������� ������ �� ���������� : ";
	cin >> result.persons;
	cout << endl << "������� ���������� �� ���� ������� : ";
	cin >> result.price;
	func(result);
	return 0;
}



		
		
