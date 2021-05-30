/*�������� � ��������� ��������� ������������ ������ ���������� ������� �� 10 �� 50.
�������� ��� �� �����.��� ���������� � ������ �� ����� �������� ��������� �������. 
(���������: ������� ������ ��������� ��� ��������� � ��������� �� ������������ ������,
���������� �����, ���������� ��������).���������� ����� � �������� �������� ������������.*/


#include<iostream>
using namespace std;

void inicializator(int** , int, int);
void show(int** , int, int);

int main()
{
	setlocale(LC_ALL, "rus");
	int stroka = 0;
	int stolbec = 0;
	cout << "������� ���������� ����� : ";
	cin >> stroka;
	cout << "������� ���������� �������� : ";
	cin >> stolbec;

	//��������� ��������� �� ������ ����������  � �������� ��� ���� ������
	int **ppmass = 0;
	ppmass = new int* [stroka];
	for (int i = 0; i < stroka; i++)
	{
		ppmass[i] = new int[stolbec];
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	inicializator(ppmass, stroka, stolbec);//���������� �������
	show(ppmass, stroka, stolbec);//����� �� �����

	//����������� ���������� ������~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	for (int i = 0; i < stroka; i++)
	{
		delete [] ppmass[i];
	}
	delete[] ppmass;
	ppmass = 0;
	return 0;
}

void inicializator(int** mass, int str, int stlb)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stlb; j++)
		{
			mass[i][j] = 10 + rand() % 40;
		}
	}
}

void show(int** mass, int str, int stlb)
{
	system("cls");
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stlb; j++)
		{
			cout << mass[i][j] << "   ";
		}
		cout << "\n\n\n";
	}
}

