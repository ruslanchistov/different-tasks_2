//����� ������� ������� � ������� �����������.


#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� ����� ��������� ������� :";
	int size;
	cin >> size;
	int* pmass;
	pmass = new int[size];
	//-------------��������� ������ ���������� ������� � ������� �� �����------
	for (int i = 0; i < size; i++)
	{
		pmass[i] = 1 + rand() % 50;
		cout << pmass[i] << "\t";
	}
	cout << endl << endl;
	for (int j = 0; j < 7; j++)
	{
		int min = pmass[j];
		for (int k = 0, i = 0; i < size; i++)
		{
			if (pmass[i] < min)
			{
				min = pmass[i];
				k++;
			}
			swap(pmass[j], pmass[k]);
		}
	}
		cout << pmass[6];
		delete pmass;
		return 0;
}