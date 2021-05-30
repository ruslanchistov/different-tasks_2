//---------Сортировка символов


# include<iostream>
using namespace std;

void print(char mass[10])
{
	for (int i = 0; i < 10; i++)
	{
		cout << mass[i]<<"  " ;
	}
	cout << endl<<endl ;
}





int main ()
{
	setlocale(LC_ALL, "Russian");

	char mass[10] = "doasbecru";
	print(mass);
	int counter;
	do
	{
	    counter = 0;
		for (int i = 0; i < 8; i++)
		{
			if (mass[i] > mass[i + 1])
			{
				swap(mass[i], mass[i + 1]);
				counter++;
			}
		}
	}
		while (counter != 0);
		print(mass);
	return 0;
}
		