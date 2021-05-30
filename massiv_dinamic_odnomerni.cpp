/*�������� ��������� �� ������ ���� double � ���������� ������������ ������� ��� ������.
����� �������� ������ ������� : ������ ������ �������� ������ ��� �������, ������  � ��������� ������ �������,
������ � �������� ������ �� �����, ��������� � ���������� ���������� ������.
��������� ������ ���������� ������������ ���������� ������(��������� ����� ������������ �������) ��� ����� �� ���������.*/




#include<iostream>
using namespace std;

double* mamory(double*, int );
void data(double*, int);
void show(double*, int);
double* free(double*);

int main()
{
	setlocale(LC_ALL, "rus");
	bool otvet = 1;
	do {
		system("cls");
		double* pmass = 0;
		int size_mass = 0;
		cout << "������� ������ �������  ";
		cin >> size_mass;
		cout << endl << endl;

		pmass = mamory(pmass, size_mass);
		data(pmass, size_mass);
		show(pmass, size_mass);
		pmass = free(pmass);
		cout << "������ ��� ��������� ������� (1 - �� , 0 - ���) ?";
		cin >> otvet;
	} while (otvet != 0);

	return 0;
}


double* mamory(double* p, int size)
{
	 p = new double[size];
	 return p;
}

void data(double* mass, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(mass + i) = 1 + rand() % 50;
	}
}

void show(double* mass, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(mass + i) << "  ";
	}
	cout << "\n\n\n";
}

double* free(double* p)
{
	delete[] p;
	p = 0;
	return p;
}
