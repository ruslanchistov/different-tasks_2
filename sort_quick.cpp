//---Быстрая сортировка-----

#include<iostream>
using namespace std;

void Quick_Sort(int* arr, int left, int right)
{
	if (left < right)									//Пока границы не сошлись.
	{
		int control = left;								//Объявляем контрольным элементом начальный элемент.
		int i = left;									//Текущая левая граница.
		int j = right;									//Текущая правая граница.

		while (i < j)									//Пока границы не сошлись.
		{
			
			while ((arr[j] >= arr[control]) && (i < j)) //Двигаем правую границу влево,пока не найдём элемент меньше
			{											//контрольного или не упрёмся в левую границу.
				j--;
			}
			while ((arr[i] <= arr[control]) && (i < j)) //Двигаем левую границу вправо,пока не найдём элемент больше 
			{											//контрольного или не упрёмся в правую границу.
				i++;
			}

			if (i < j)									//Если границы не сошлись, меняем найденные элементы местами.
			{
				swap(arr[i], arr[j]);				
			}
		}
		swap(arr[control], arr[i]);						//Меняем контрольный элемент и элемент левой границы местами.

		if (((i - 1) - left) < (right - (i + 1)))
		{
			Quick_Sort(arr, left, i - 1);				//Вызываем рекурсивно функцию для левого подмассива.
			Quick_Sort(arr, i + 1, right);				//Вызываем рекурсивно функцию для правого подмассива.
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

	Quick_Sort(pmass, 0, size - 1);							//Вызываем функцию сортировки.

	//-------------Выводим отсортированный массив на экран----------------------
	for (int i = 0; i < size; i++)
	{
		cout << pmass[i] << "\t";
	}
	
	delete[] pmass;
	pmass = nullptr;
	return 0;
}