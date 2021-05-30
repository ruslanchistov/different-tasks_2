/*Создать структуру. Выделить память под массив этих структур.
Написать функцию для инициализации и функцию для вывода результата.*/




#include<iostream>
using namespace std;

struct Fasteners
{
	string name;
	int longe;
	int diameter;
};

 void inicializator(Fasteners*,const int);
 void show(Fasteners*,const int);


int main()
{
	setlocale(LC_ALL, "rus");
	const int amount = 3;
	Fasteners kind[amount];
	Fasteners* pFast_kind = new Fasteners[amount];
	inicializator(pFast_kind,amount);	
	show(pFast_kind, amount);
	delete[]pFast_kind;

	return 0;
}

void inicializator(Fasteners* kind,const int amount)
{
	for (int i = 0; i < amount; i++)
	{
		cout << "Введите наименование   " << i + 1 << " детали  ";
		cin >> kind[i].name;	
		cin.sync();
		cout << "Введите длинну   " << kind[i].name << " :  ";
		cin >> kind[i].longe;
		cout << "Введите диаметр   " << kind[i].name << " :  ";
		cin >> kind[i].diameter;
	}	
}

void show(Fasteners* kind, const int amount)
{
	for (int i = 0; i < amount; i++)
	{
		cout << kind[i].name <<"\t"<< kind[i].longe <<"\t"<< kind[i].diameter <<"\t"<<"\n"<< endl;
	}
}