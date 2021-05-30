#include<iostream>
using namespace std;

struct Param
{
	int Data;
	Param* Next;
};
Param* tbl[15];

void Insert(int size)
{
	int data;
	cout << "������� ������� ��� ������� : " << endl;
	cin >> data;
	int h;
	Param* current;
	h = data % size;
	for (current = tbl[h]; current; current = current->Next)
	{
		if (current->Data == data)
		{
			cout << "��� ��� ��� ����" << endl;
			return;
		}
	}
		current = new Param;
		current->Data = data;
		current->Next = tbl[h];
		tbl[h] = current;
		cout << "������� ��������" << endl;
		return;
}

void Search(int size)
{
	int data;
	cout << "������� ������� ��� ������ : " << endl;
	cin >> data;
	int h = data % size;
	Param* current;
	for (current = tbl[h]; current; current = current->Next)
	{
		if (current->Data == data)
		{
			cout << "����� ������� ����." << endl;
			return;
		}
	}
	cout << "������ �������� ���!!!" << endl;
	return;
}

void Print(int size)
{
	Param* current;
	for (int h = 0; h < size; h++)
	{
		current = tbl[h];
		cout << h  << " --- ";
		while (current != nullptr)
		{
			cout << current->Data << "\t";
			current = current->Next;
		}
		cout << "\n";
	}
	return;
}

void Del(int size)
{
	int data;
	cout << "������� ������� ��� �������� : " << endl;
	cin >> data;
	int h = data % size;
	Param* current = nullptr;
	Param* Prev = nullptr;
	for (current = tbl[h]; current; current = current->Next)
	{
		
		if (current->Data == data)
		{
			if (current == tbl[h]) 
			{				
				tbl[h] = current->Next;
				delete current;
			}
			else
			{
				Prev->Next = current->Next;
				delete current;
			}
			return;
		}
		Prev = current;
	}
	cout << "������ �������� ���!!!" << endl;
	return;
}

void Menu(int size)
{
	int menu = 5;
	while (menu != 0)
	{
		cout << "  ����:" << endl;
		cout << "  1 - ������� ��������." << endl;
		cout << "  2 - ����� ��������." << endl;
		cout << "  3 - �������� ��������." << endl;
		cout << "  4 - ���������� �������." << endl;
		cout << "  0 - �����." << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			Insert(size);
			break;
		case 2:
			Search(size);
			break;
		case 3:
			Del(size);
			break;
		case 4:
			Print(size);
			break;
		case 0:
			break;
		default:
			cout << "������������ ����!!!" << endl;
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int size;
	cout << "������� ������ ������� : ";
	cin >> size;
	Menu(size);
	return 0;
}