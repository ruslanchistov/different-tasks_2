#include<iostream>
using namespace std;

struct Advertising
{
	int counter;
	float persons;
	int price;
} result;

void func(Advertising res)
{
	cout << "Вы показали " << res.counter << "  объявлений." << endl;
	cout << "На объявления нажало  " << res.persons << "  процентов посетителей." << endl;
	cout << "За одно нажатие Вы заработали  " << res.price << "  рублей." << endl;
	float summa = res.counter * res.persons / 100 * res.price ;
	cout << "Вы заработали  " <<summa << "рублей." << endl;
 }



int main()
{
	setlocale(LC_ALL, "rus");
	cout << endl << "Сколько объявлений Вы показали :  ";
	cin >> result.counter;
	cout << endl << "Сколько процентов посетителей нажали на объявления : ";
	cin >> result.persons;
	cout << endl << "Сколько заработали за одно нажатие : ";
	cin >> result.price;
	func(result);
	return 0;
}



		
		
