//Сортировка выбором


#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите число элементов массива :";
	int size;
	cin >> size;
	int* pmass;
	pmass = new int[size];
	//-------------Заполняем массив случайными числами и выводим на экран------
	for (int i = 0; i < size; i++)
	{
		pmass[i] = 1 + rand() % 50;
		cout << pmass[i] << "   ";
	}
	cout << endl;
	//------------Сортируем массив----------------------------------------------
	for (int i = 0; i < size-1 ; i++)
	{
		int min = pmass[i];
		int k = 0;
		for (int j = i + 1; j < size; j++)
		{
			if (pmass[j] < min)
			{
				min = pmass[j];
				k = j;
			}
		}
		if (k != 0)
		{
			pmass[k] = pmass[k] ^ pmass[i];
			pmass[i] = pmass[k] ^ pmass[i];
			pmass[k] = pmass[k] ^ pmass[i];
		}
		
	}

				
	
	//-------------Выводим отсортированный массив на экран----------------------
	for (int i = 0; i < size; i++)
	{
		cout << pmass[i] << "   ";
	}

	delete[] pmass;
	return 0;
}