//---������� ����������-----

#include<iostream>
using namespace std;

void Quick_Sort(int* arr, int left, int right)
{
	if (left < right)									//���� ������� �� �������.
	{
		int control = left;								//��������� ����������� ��������� ��������� �������.
		int i = left;									//������� ����� �������.
		int j = right;									//������� ������ �������.

		while (i < j)									//���� ������� �� �������.
		{
			
			while ((arr[j] >= arr[control]) && (i < j)) //������� ������ ������� �����,���� �� ����� ������� ������
			{											//������������ ��� �� ������ � ����� �������.
				j--;
			}
			while ((arr[i] <= arr[control]) && (i < j)) //������� ����� ������� ������,���� �� ����� ������� ������ 
			{											//������������ ��� �� ������ � ������ �������.
				i++;
			}

			if (i < j)									//���� ������� �� �������, ������ ��������� �������� �������.
			{
				swap(arr[i], arr[j]);				
			}
		}
		swap(arr[control], arr[i]);						//������ ����������� ������� � ������� ����� ������� �������.

		if (((i - 1) - left) < (right - (i + 1)))
		{
			Quick_Sort(arr, left, i - 1);				//�������� ���������� ������� ��� ������ ����������.
			Quick_Sort(arr, i + 1, right);				//�������� ���������� ������� ��� ������� ����������.
		}
		else
		{
			Quick_Sort(arr, i + 1, right);
			Quick_Sort(arr, left, i - 1);
		}
	}
	return;
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
		cout << pmass[i] << "\t";
	}
	cout << endl << endl;

	Quick_Sort(pmass, 0, size - 1);							//�������� ������� ����������.

	//-------------������� ��������������� ������ �� �����----------------------
	for (int i = 0; i < size; i++)
	{
		cout << pmass[i] << "\t";
	}
	
	delete[] pmass;
	pmass = nullptr;
	return 0;
}