#include<iostream>
using namespace std;


int main()
{
	int a = 2;
	int b = 3;
	int c = 4;	
	int*** p = 0;
//_______________________________Выделяем память____________________
	p =	new int** [a];

	for (int i = 0; i < a; i++)
	{
		p[i] = new int*[b];

		for (int j = 0; j < b; j++)
		{
			p[i][j] = new int[c];
		}
	}
//_______________________________Заполняем массив,выводим результат___
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			for (int k = 0; k < c; k++)
			{
				p[i][j][k] = i + j + k;
				cout << "p  " << i << "\t" << "  " << j << "\t" << k << "\t" << " = " << "\t" << p[i][j][k] << "\n";
			}
		}
		cout << "\n\n";
	}
//________________________________Освобождаем память_____________________
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			delete[]p[i][j];
		}
		delete[]p[i];
	}
	delete[] p;

	p = 0;
	return 0;
}


	