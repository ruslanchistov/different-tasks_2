//Сортировка методом вставки.


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
	// ------------------------------Сортируем массив----------------------------
	for (int i = 1; i < size; i++)
	{
		int cur = pmass[i];
		int j = i;
		while (j > 0 && pmass[j - 1] > cur)
		{
			pmass[j] = pmass[j - 1];
			pmass[j - 1] = cur;
			j--;

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
