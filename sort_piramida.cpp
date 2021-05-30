#include<iostream>
using namespace std;

void piramida(int* arr, int k, int n)
{
	while (k <= n/2)										//���� � arr[k] ���� �������.
	{
		int child = 2 * k;									//���������� ��������� ������ ����.
		if ((child < n) && (arr[child] < arr[child + 1]))	//���� �� ������� �� ������� � ����� ��� ������ �������.
		{
			child++;
		}
		if (arr[k] >= arr[child])							//���� ���� ������ �������� ����.
		{
			break;
		}
			swap(arr[k], arr[child]);						//����� ������ �������.
		k = child;
	}
}

void sort(int* arr, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)					//������ ��������.
	{
		piramida( arr, i, size - 1);
	}

	for (int i = size - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);								//������ ������ ������� � ���������.
		piramida(arr, 0, i - 1 );							//��������������� ���������������.
	}
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

	sort(pmass, size);

	//-------------������� ��������������� ������ �� �����----------------------
	for (int i = 0; i < size; i++)
	{
		cout << pmass[i] << "\t";
	}

	delete[] pmass;
	pmass = nullptr;
	return 0;
}