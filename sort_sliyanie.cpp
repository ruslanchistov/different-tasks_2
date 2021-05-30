//���������� ��������


#include<iostream>
using namespace std;

void merge( int*pmass,int left, int right)
{
	if (left == right)              //���� ������� ����������
		return;
	//--------------------------------���� �������� ��� ��������, ������ �� ������� � �������
	if ((right - left) == 1)                   
	{  
		if (pmass[right] < pmass[left]) 
			swap(pmass[left], pmass[right]);
		return;
	}
	//-------------------���������� �������� ������� � ���������� �������� ������� ������� ������� 
		int middle = (left + right) / 2;
		merge(pmass,left, middle);
		merge(pmass,middle + 1, right);
	//--------------------------------------------------------------------------------------------
		int first = left;          //������ ������ ����� ����������
		int second = middle + 1;   //������ ������ ����� ����������
		int result = 0;            //������� ������� � �������������� �������
		int* pmass1;               //�������� ������ ��� �������������� ������, 	                        
		pmass1 = new int[right - left + 1];   //���� ����� ������� ��������������� ��������.
	//---------------------���������� (��������� ) � �������������� ������ ��� ����������,
	//---------------------	���� ���� �� � ����� ���������� ���� ��������-------------------------- 
		while ((first <= middle) && (second <= right))
		{
			pmass1[result ++] = (pmass[first] < pmass[second]) ? pmass[first ++] : pmass[second ++];
		}
	//-----------���� ������ ��������� ����������, ������������ ������� �������--------------------
		while (second <= right)
		{
			pmass1[result++] = pmass[second++];
		}
	//-----------���� ������ ��������� ����������, ������������ ������� �������---------------------
		while (first <= middle)
		{
			pmass1[result++] = pmass[first++];
		}
	//-----------�������� �������������� ������ � ��������------------------------------------------
		for (result = 0; result < (right - left + 1); result++)
		{
			pmass[left + result] = pmass1[result];
		}
		
		delete[] pmass1;
		pmass1 = nullptr;
}


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
		cout << pmass[i] << "   ";
	}
	cout << endl << endl;

	merge(pmass, 0, size - 1);



	//-------------������� ��������������� ������ �� �����----------------------
	for (int i = 0; i < size; i++)
	{
		cout << pmass[i] << "   ";
	}

	delete[] pmass;
	pmass = nullptr;
	return 0;
}