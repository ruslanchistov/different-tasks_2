// ���������� ����������� �������



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
		cout << pmass[i] <<"   ";
	}
	cout << endl;
//-------------��������� �������� ������� � ������� �����������------------
	int counter;
	do
	{
	    counter = 0;
		for (int i = 0; i < size - 1 ; i++)
		{
			if (pmass[i] > pmass[i + 1])
			{
				pmass[i] = pmass[i] ^ pmass[i + 1];
				pmass[i + 1] = pmass[i] ^ pmass[i + 1];
				pmass[i] = pmass[i] ^ pmass[i + 1];
				counter++;
			}
		}	
	}
		while (counter != 0);
//-------------������� ��������������� ������ �� �����----------------------
	for (int i = 0; i < size; i++)
	{
		cout << pmass[i] << "   ";
	}
	
	delete[] pmass;
	return 0;
}
