/*���������� ������ ��������. ��������� ��������� � ���������.*/


#include<iostream>
#include<Windows.h>
using namespace std;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct Parameter
{
	int age;
	float height;                       
	float weight;
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct Data
{
	string surname;
	Parameter persone;
};


Data* memory_func(Data*, const int);   //��������� ������
void set_func(Data*, const int);       //�������� ������
void show_func(Data*, const int);      //����� ����������


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main()
{
	setlocale(LC_ALL, "rus");
	Data* pData = 0;
	int counter = 0;
	bool otvet = 0;

	do
	{
		
		pData = memory_func(pData, counter);
		set_func(pData, counter);

		counter++;
		cout << "������ ���������� ���� ������ ? (1 - �� , 0 - ���)  ";
		cin >> otvet;
	}
	while (otvet != 0);

	show_func(pData, counter);

	delete[] pData;
	pData = 0;
	return 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Data* memory_func(Data* data, const int counter)
{
	if (counter == 0)
	{
		data = new Data[counter + 1];	      //�������� ������ ��� ������ ��������� �������
	}
	else
	{
		Data* cur_data = new Data[counter + 1];   //�������� ��������� ������
		for (int i = 0; i < counter; i++)
		{
			cur_data[i] = data[i];
		}
		delete[]data;
		data = cur_data;
	}
	
	return data;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void set_func(Data*data,const int counter)
{	
	cout << "������� : ";
	cin >> data[counter].surname;
	cin.sync();
	cout << "������� : ";
	cin >> data[counter].persone.age;
	cout << "���� : ";
	cin >> data[counter].persone.height;
	cout << "��� : ";
	cin >> data[counter].persone.weight;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void show_func(Data*data, const int counter)
{
	system("cls");
	
	for (int i = 0; i < counter; i++)
	{
		cout << "������� : "<< data[i].surname << "\n";
		cout << "������� : "<< data[i].persone.age  << "  ��� (����)"<< "\n";
		cout << "���� : " << data[i].persone.height << "  ��" << "\n";
		cout << "��� : "<< data[i].persone.weight << "  ��"<< "\n";
		cout << "---------------------------" << "\n";
	}
}

