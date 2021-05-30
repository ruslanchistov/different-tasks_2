//Сортировка слиянием


#include<iostream>
using namespace std;

void merge( int*pmass,int left, int right)
{
	if (left == right)              //Если границы сомкнулись
		return;
	//--------------------------------Если осталось два элемента, меняем их местами и выходим
	if ((right - left) == 1)                   
	{  
		if (pmass[right] < pmass[left]) 
			swap(pmass[left], pmass[right]);
		return;
	}
	//-------------------Определяем середину массива и рекурсивно вызываем функцию деления массива 
		int middle = (left + right) / 2;
		merge(pmass,left, middle);
		merge(pmass,middle + 1, right);
	//--------------------------------------------------------------------------------------------
		int first = left;          //Начало первой части подмассива
		int second = middle + 1;   //Начало второй части подмассива
		int result = 0;            //Текущая позиция в результирующем массиве
		int* pmass1;               //Выделяем память под дополнительный массив, 	                        
		pmass1 = new int[right - left + 1];   //куда будем сливать отсортированные элементы.
	//---------------------Записываем (соединяем ) в результирующий массив два подмассива,
	//---------------------	пока хотя бы в одном подмассиве есть элементы-------------------------- 
		while ((first <= middle) && (second <= right))
		{
			pmass1[result ++] = (pmass[first] < pmass[second]) ? pmass[first ++] : pmass[second ++];
		}
	//-----------Если первый подмассив закончился, переписываем остатки второго--------------------
		while (second <= right)
		{
			pmass1[result++] = pmass[second++];
		}
	//-----------Если второй подмассив закончился, переписываем остатки первого---------------------
		while (first <= middle)
		{
			pmass1[result++] = pmass[first++];
		}
	//-----------Копируем результирующий массив в исходный------------------------------------------
		for (result = 0; result < (right - left + 1); result++)
		{
			pmass[left + result] = pmass1[result];
		}
		
		delete[] pmass1;
		pmass1 = nullptr;
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
		cout << pmass[i] << "   ";
	}
	cout << endl << endl;

	merge(pmass, 0, size - 1);



	//-------------Выводим отсортированный массив на экран----------------------
	for (int i = 0; i < size; i++)
	{
		cout << pmass[i] << "   ";
	}

	delete[] pmass;
	pmass = nullptr;
	return 0;
}