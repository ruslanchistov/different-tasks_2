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
	cout << "Введите элемент для вставки : " << endl;
	cin >> data;
	int h;
	Param* current;
	h = data % size;
	for (current = tbl[h]; current; current = current->Next)
	{
		if (current->Data == data)
		{
			cout << "Это имя уже есть" << endl;
			return;
		}
	}
		current = new Param;
		current->Data = data;
		current->Next = tbl[h];
		tbl[h] = current;
		cout << "Элемент вставлен" << endl;
		return;
}

void Search(int size)
{
	int data;
	cout << "Введите элемент для поиска : " << endl;
	cin >> data;
	int h = data % size;
	Param* current;
	for (current = tbl[h]; current; current = current->Next)
	{
		if (current->Data == data)
		{
			cout << "Такой элемент есть." << endl;
			return;
		}
	}
	cout << "Такого элемента нет!!!" << endl;
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
	cout << "Введите элемент для удаления : " << endl;
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
	cout << "Такого элемента нет!!!" << endl;
	return;
}

void Menu(int size)
{
	int menu = 5;
	while (menu != 0)
	{
		cout << "  Меню:" << endl;
		cout << "  1 - Вставка элемента." << endl;
		cout << "  2 - Поиск элемента." << endl;
		cout << "  3 - Удаление элемента." << endl;
		cout << "  4 - Распечатка таблицы." << endl;
		cout << "  0 - Выход." << endl;
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
			cout << "Некорректный ввод!!!" << endl;
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int size;
	cout << "Введите размер таблицы : ";
	cin >> size;
	Menu(size);
	return 0;
}