/*Образовать массив структур. Используя структуру в структуре.*/


#include<iostream>
#include<Windows.h>
using namespace std;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct Parameter
{
	int age;
	float height;                       
	float weight;
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct Data
{
	string surname;
	Parameter persone;
};


Data* memory_func(Data*, const int);   //Выделение памяти
void set_func(Data*, const int);       //Внесение данных
void show_func(Data*, const int);      //Вывод результата


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main()
{
	setlocale(LC_ALL, "rus");
	Data* pData = 0;
	int counter = 0;
	bool otvet = 0;

	do
	{
		
		pData = memory_func(pData, counter);
		set_func(pData, counter);

		counter++;
		cout << "Будете продолжать ввод данных ? (1 - да , 0 - нет)  ";
		cin >> otvet;
	}
	while (otvet != 0);

	show_func(pData, counter);

	delete[] pData;
	pData = 0;
	return 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Data* memory_func(Data* data, const int counter)
{
	if (counter == 0)
	{
		data = new Data[counter + 1];	      //Выделяем память для первой структуры массива
	}
	else
	{
		Data* cur_data = new Data[counter + 1];   //Выделяем временную память
		for (int i = 0; i < counter; i++)
		{
			cur_data[i] = data[i];
		}
		delete[]data;
		data = cur_data;
	}
	
	return data;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void set_func(Data*data,const int counter)
{	
	cout << "Фамилия : ";
	cin >> data[counter].surname;
	cin.sync();
	cout << "Возраст : ";
	cin >> data[counter].persone.age;
	cout << "Рост : ";
	cin >> data[counter].persone.height;
	cout << "Вес : ";
	cin >> data[counter].persone.weight;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void show_func(Data*data, const int counter)
{
	system("cls");
	
	for (int i = 0; i < counter; i++)
	{
		cout << "Фамилия : "<< data[i].surname << "\n";
		cout << "Возраст : "<< data[i].persone.age  << "  лет (года)"<< "\n";
		cout << "Рост : " << data[i].persone.height << "  см" << "\n";
		cout << "Вес : "<< data[i].persone.weight << "  кг"<< "\n";
		cout << "---------------------------" << "\n";
	}
}

