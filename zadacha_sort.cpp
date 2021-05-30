//Найти седьмой элемент в порядке возрастания.


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