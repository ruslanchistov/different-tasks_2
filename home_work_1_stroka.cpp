//Дана строка символов.Необходимо получить инверсию этой строки

#include<iostream>
#include<string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	string str = {};
	cout << "Введите строку : \n";
	cin >> str;
	int size = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
		size++;
	}
	for (int i = 0; i < size/2; i++)
	{
		swap(str[i], str[size - 1 - i]);
	}
	cout << str << endl;
	return 0;
}