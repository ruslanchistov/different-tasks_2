#include<iostream>
using namespace std;

void piramida(int* arr, int k, int n)
{
	while (k <= n/2)										//Пока у arr[k] есть сыновья.
	{
		int child = 2 * k;									//Определяем положение левого сына.
		if ((child < n) && (arr[child] < arr[child + 1]))	//Если не выходим за границы и левый сын меньше правого.
		{
			child++;
		}
		if (arr[k] >= arr[child])							//Если отец больше большего сына.
		{
			break;
		}
			swap(arr[k], arr[child]);						//Иначе меняем местами.
		k = child;
	}
}

void sort(int* arr, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)					//Строим пирамиду.
	{
		piramida( arr, i, size - 1);
	}

	for (int i = size - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);								//Меняем первый элемент с последним.
		piramida(arr, 0, i - 1 );							//Восстанавливаем пирамидальность.
	}
}

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

	sort(pmass, size);

	//-------------Выводим отсортированный массив на экран----------------------
	for (int i = 0; i < size; i++)
	{
		cout << pmass[i] << "\t";
	}

	delete[] pmass;
	pmass = nullptr;
	return 0;
}