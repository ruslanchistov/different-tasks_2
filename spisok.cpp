#include<iostream>
using namespace std;


struct List
{
	int data;
	List* next;
};

List* head = nullptr;
List* cur = nullptr;
List* temp = nullptr;

void setData()
{
	int data = 0;
	int key = 1;
	cout << "¬ведите первый элемент :  ";
	cin >> data;
	             
	List* cur = new List;
	cur->data = data;
	cur->next = nullptr;
	head = cur;
		                 
	do
	{
		system("cls");
		cout << "¬ведите следующий элемент : ";
		cin >> data;
		
		cur->next = new List;
		cur = cur->next;
		cur->data = data;
		cur->next = nullptr;
		cout << "Ѕудут ещЄ элементы ?  (1 - да , 0 - нет)";
		cin >> key;
	} while (key != 0);
	system("cls");
	cout << "—писок создан !" << endl;
}

void getData()
{
	List* cur = head;
	while (cur != nullptr)
	{
		cout << "data - " << cur->data << endl;
		cur = cur->next;
	}
}

void delData()
{
	cur = head;
	while (cur != nullptr)
	{
		temp = cur->next;
		if(temp == nullptr)
		{
		delete temp;
		break;
		}
		else
		{
		delete cur;
		cur = temp;
		}
	}
	head = nullptr;
	cur = nullptr;
	temp = nullptr;
}

int main()
{
	setlocale(LC_ALL, "rus");
	setData();
	getData();
	delData();
	
	return 0;
}