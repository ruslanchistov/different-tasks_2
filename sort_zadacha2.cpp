/*Некоторое число содержится в каждом из трех
целочисленных неубывающих массивов
x[1] <= ... <= x[p],
y[1] <= ... <= y[q],
z[1] <= ... <= z[r].
Найти это число*/





#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int mass_x[15] = { 1,3,5,7,9,11,13,15,17,19,21,23,24,26,27 };
	int mass_y[20] = { 1,4,6,8,10,12,14,16,18,20,22,24,25,28,30,31,32,33,34,35 };
	int mass_z[10] = { 1,11,12,13,14,15,16,17,18,25 };
	
	int namber = 0;

	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			if (mass_x[x] == mass_y[y])
			{
				for (int z = 0; z < 10; z++)
				{
					if (mass_x[x] == mass_z[z])
					{
						namber = mass_z[z];
						cout << "Искомое число : " << namber << endl;
						break;
					}
				}
			}
		}
	}
	if (namber == 0)
	{
		cout << "Одинакового числа нет!!!" << endl;
	}
	return 0;
}