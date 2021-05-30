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
List* fin = nullptr;
List* cur2 = nullptr;
int counterMamory = 0;

void createList()
{	
	int data = 0;
	int key = 1;
	cout << "������� ������ ������� :  ";
	cin >> data;
	List* cur = new List;
	counterMamory++;
	cur->data = data;
	cur->next = nullptr;
	head = cur;
	do
	{
		system("cls");
		cout << "������� ��������� ������� : ";
		cin >> data;
		cur->next = new List;
		counterMamory++;
		cur = cur->next;
		cur->data = data;
		cur->next = nullptr;
		cout << "����� ��� �������� ?  (1 - �� , 0 - ���)";
		cin >> key;
	} while (key != 0);
	system("cls");
	cout << "������ ������ !" << endl;
}

void printList()
{
	if (head != nullptr)
	{
		List* cur = head;
		while (cur != nullptr)
		{
			cout << "data - " << cur->data << endl;
			cur = cur->next;
		}
		system("pause");
	}
	else
	{
		cout << "� ��� ������ ������ !!!\n";
		system("pause");
	}
}

void insertEndList()
{
	if (head != nullptr)
	{
		int data = 0;
		cur = head;
		while (cur != 0)
		{
			fin = cur;
			cur = cur->next;
		}
		fin->next = new List;
		counterMamory++;
		cur = fin->next;
		cout << "������� ������� : ";
		cin >> data;
		cur->data = data;
		cur->next = nullptr;
		cout << "������� ��������\n";
		system("pause");
	}
	else
	{
		cout << "� ��� ������ ������ !!!\n";
		system("pause");
	}
}

void insertHeadList()
{
	int data = 0;
	cur = head;
	head = new List;
	counterMamory++;
	cout << "������� ������� : ";
	cin >> data;
	head->data = data;
	head->next = cur;
	cout << "������� ��������\n";
	system("pause");
}

void insertSpecificElement()
{
	if (head != nullptr)
	{
		int index = 0;
		int data = 0;
		printList();

		cout << "������� ����� ��������, ����� �������� ������ �������� ������� : ";
		cin >> index;
		cur = head;
		for (int i = 1; i < index; i++)
		{
			cur = cur->next;
		}
		temp = cur->next;
		cur->next = new List;
		counterMamory++;
		cur2 = cur->next;
		cur2->next = temp;
		cout << "������� ������� : ";
		cin >> data;
		cur2->data = data;
		cout << "������� ��������\n";
		system("pause");
	}
	else
	{
		cout << "� ��� ������ ������ !!!\n";
		system("pause");
	}
}

void deletEndList()
{
	if (head != nullptr)
	{
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			cout << "��������� ������� ����� \n";
			system("pause");
		}
		else
		{
			cur = head;
			while (cur->next->next != nullptr)
			{

				cur = cur->next;
			}
			delete cur->next;
			counterMamory--;
			cur->next = nullptr;
			cout << "��������� ������� ����� \n";
			system("pause");
		}
	}
	else
	{
		cout << "� ��� ������ ������ !!!\n";
		system("pause");
	}	
}

void deletHeadList()
{
	if (head != nullptr)
	{
		cur = head->next;
		delete head;
		counterMamory--;
		head = cur;
		cout << "������ ������� �����\n";
		system("pause");
	}
	else
	{
		cout << "� ��� ������ ������ !!!\n";
		system("pause");
	}
}

void deletSpecificElement()
{
	if (head != nullptr)
	{
		printList();
		int index = 0;
		cout << "������� ����� �������� ��� �������� :";
		cin >> index;
		if (index == 1)
		{
			deletHeadList();
		}
		else
		{
			cur = head;
			if (head->next != nullptr)
			{
				for (int i = 1; i < index; i++)
				{
					temp = cur;
					cur = cur->next;
				}
				temp->next = cur->next;
				delete cur;
				counterMamory--;
				cout << index << " - � " << "������� �����\n";
				system("pause");
			}
			else
			{
				delete head;
				counterMamory--;
				head = nullptr;
				cout << index << " - � " << "������� �����\n";
				system("pause");
			}
		}
	}
	else
	{
		cout << "� ��� ������ ������ !!!\n";
		system("pause");
	}
}

void deletWholeList()
{
	if (head != nullptr)
	{
		cur = head;
		while (cur != nullptr)
		{
			temp = cur->next;
			if (temp == nullptr)
			{
				delete temp;
				counterMamory--;
				break;
			}
			else
			{
				delete cur;
				counterMamory--;
				cur = temp;
			}
		}
		head = nullptr;
		cur = nullptr;
		temp = nullptr;
		cout << "������ �����\n";
		cout << "counterMamory = " << counterMamory << endl;
		system("pause");
	}
	else
	{
		cout << "� ��� ������ ������ !!!\n";
		system("pause");
	}
}

void swapEdgeElement()
{
	if (head == nullptr)
	{
		cout << "� ��� ������ ������ !!!\n";
		system("pause");
	}
	else
	{
		if (head->next == nullptr)
		{
			cout << "� ��� ���� ������� � ������ !!!\n";
			system("pause");
		}
		else
		{
			if (head->next->next == nullptr)
			{
				fin = head->next;
				fin->next = head;
				head->next = nullptr;
				head = fin;
				cout << "�������� �������� \n";
				system("pause");
			}

			else
			{
				cur = head;
				while (cur->next->next != nullptr)
				{
					cur = cur->next;
				}
				fin = cur->next;
				fin->next = head->next;
				cur->next = head;
				head->next = nullptr;
				head = fin;
				cout << "�������� �������� \n";
				system("pause");
			}
		}
	}
}

void makeHeadElement()
{
	if (head == nullptr)
	{
		cout << "� ��� ������ ������ !!!\n";
		system("pause");
	}
	else
	{
		if (head->next == nullptr)
		{
			cout << "� ��� ���� ������� � ������ !!!\n";
			system("pause");
		}
		else
		{
				printList();
				cout << "����� ������� ������ ������� ������ : ";
				int index = 0;
				cin >> index;
				if (index == 1)
				{
					cout << "���� ������� � ��� ������ !!!\n";
					system("pause");
				}
				else
				{
					int i = 0 ;
					cur = head;
					while (cur != nullptr)
					{
						cur = cur->next;
						i++;
					}
					if (i < index)
					{
						cout << "������ �������� ��� !!!\n";
						system("pause");
					}
					else
					{
						cur = head;
						for (int i = 1; i < index; i++)
						{
							temp = cur;
							cur = cur->next;
						}
						temp->next = cur->next;
						cur->next = head;
						head = cur;
						cout << index << "  -� ������� ���� ������\n";
						system("pause");
					}
				}
		}
	}
}

void makeEndElement()
{
	if (head == nullptr)
	{
		cout << "� ��� ������ ������ !!!\n";
		system("pause");
	}
	else
	{
		if (head->next == nullptr)
		{
			cout << "� ��� ���� ������� � ������ !!!\n";
			system("pause");
		}
		else
		{
			printList();
			cout << "����� ������� ������ ������� ��������� : ";
			int index = 0;
			cin >> index;
			if (index == 1)
			{
				cur = temp = head;
				while (cur->next != nullptr)
				{
					cur = cur->next;
				}
				cur->next = head;
				head = head->next;
				temp->next = nullptr;
				cout << index << "  -� ������� ���� ���������\n";
				system("pause");
			}
			else
			{
			int i = 0;
			cur = head;
			while (cur != nullptr)
			{
				cur = cur->next;
				i++;
			}
			if (i < index)
			{
				cout << "������ �������� ��� !!!\n";
				system("pause");
			}
			else
			{
				if (i == index)
				{
					cout << "���� ������� � ��� ��������� !!!\n";
					system("pause");
				}

				else
				{
					cur = head;
					for (int i = 1; i < index; i++)
					{
						temp = cur;
						cur = cur->next;
					}
					cur2 = cur;
					while (cur2 != nullptr)
					{
						fin = cur2;
						cur2 = cur2->next;
					}
					fin->next = cur;
					temp->next = cur->next;
					cur->next = nullptr;
					cout << index << "  -� ������� ���� ���������\n";
					system("pause");
				}
			}
			}
		}
	}
}

void Menu()
{
	int menu;
	do
	{
		system("cls");
		cout << "0 - ����:\n";
		cout << "1 - ������� ������ -\n";
		cout << "2 - ����������� ������ - \n";
		cout << "3 - �������� ������� � ����� ������ - \n";
		cout << "4 - �������� ������� � ������ ������ - \n";
		cout << "5 - �������� ������� � ����� ������������� �������� ������ - \n";
		cout << "6 - ������� ������� �� ����� ������ - \n";
		cout << "7 - ������� ������� �� ������ ������ - \n";
		cout << "8 - ������� ������������ ������� ������ - \n";
		cout << "9 - ������� ���� ������ - \n";
		cout << "10 - �������� � ������ ������� �������� - \n";
		cout << "11 - ������� ������������ ������� ������ ������ - \n";
		cout << "12 - ������� ������������ ������� ������ ��������� - \n";
		cout << "0 - ����� -\n";
		
		cin >> menu;
		switch (menu)
		{
		case 1:
			createList();
			break;
		case 2:
			printList();
			break;
		case 3:
			insertEndList();
			break;
		case 4:
			insertHeadList();
			break;
		case 5:
			insertSpecificElement();
			break;
		case 6:
			deletEndList();
			break;
		case 7:
			deletHeadList();
			break;
		case 8:
			deletSpecificElement();
			break;
		case 9:
			deletWholeList();
			break;
		case 10:
			swapEdgeElement();
			break;
		case 11:
			makeHeadElement();
			break;
		case 12:
			makeEndElement();
			break;
		case 0:
			break;
		default:
			cout << "�� ���������� ���� !!! \n";
			break;
		}
		
	} while (menu != 0);
} 





int main()
{
	setlocale(LC_ALL, "rus");	
	Menu();	
	return 0;
}