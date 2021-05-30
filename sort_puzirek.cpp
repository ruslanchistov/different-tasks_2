// Сортировка пузырьковым методом



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
		cout << pmass[i] <<"   ";
	}
	cout << endl;
//-------------Сортируем элементы массива в порядке возрастания------------
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
//-------------Выводим отсортированный массив на экран----------------------
	for (int i = 0; i < size; i++)
	{
		cout << pmass[i] << "   ";
	}
	
	delete[] pmass;
	return 0;
}
