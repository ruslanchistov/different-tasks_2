/*Объявить и заполнить двумерный динамический массив случайными числами от 10 до 50.
Показать его на экран.Для заполнения и показа на экран написать отдельные функции. 
(подсказка: функции должны принимать три параметра – указатель на динамический массив,
количество строк, количество столбцов).Количество строк и столбцов выбирает пользователь.*/


#include<iostream>
using namespace std;

void inicializator(int** , int, int);
void show(int** , int, int);

int main()
{
	setlocale(LC_ALL, "rus");
	int stroka = 0;
	int stolbec = 0;
	cout << "Введите количество строк : ";
	cin >> stroka;
	cout << "Введите количество столбцов : ";
	cin >> stolbec;

	//Объявляем указатель на массив указателей  и выделяем под него память
	int **ppmass = 0;
	ppmass = new int* [stroka];
	for (int i = 0; i < stroka; i++)
	{
		ppmass[i] = new int[stolbec];
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	inicializator(ppmass, stroka, stolbec);//Заполнение массива
	show(ppmass, stroka, stolbec);//Вывод на экран

	//Освовождаем выделенную память~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

