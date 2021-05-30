/*���� �������� ������������������, ��������� �� ����� � ������ ������
��������� �������� �����(�(� �{ � �[��)� � }� �]�).����������, ����� �� �������� �
��� ����� � ����� �������������� �������� ���, ����� ���������� ����������
�������������� ���������.*/



#include<iostream>
using namespace std;

struct List
{
	char simbol;
	List* next;
};

List* head = nullptr;
List* current = nullptr;

int countMamorry = 0;
void setList()
{
	cout << "������� ����� �� ������ (�� ����� 100 ��������)" << endl;
	char simb[101] = {};
	cin.getline(simb, 100);

	if (simb[0] == '\0')
	{
		cout << "����� ����������� !!!\n";
		return;
	}
	else
	{
		current = new List;     //������ ������ ������, ����� ��� �� ��������� � �������� ���������.
		countMamorry++;
		current->simbol = ' ';
		current->next = nullptr;
		head = current;
		int i = 0;
		while (simb[i] != '\0')  //�������� � ���������� �� ��������� ������ ������ ������.
		{
			if (simb[i] == '(' || simb[i] == ')' || simb[i] == '[' || simb[i] == ']' || simb[i] == '{' || simb[i] == '}')
			{
				current->next = new List;
				countMamorry++;
				current = current->next;
				current->simbol = simb[i];
				current->next = nullptr;
				i++;
			}
			else
			{
				i++;
			}
		}
		if (head->next == nullptr)  //��������� ���� �� � ������ ������.
		{
			cout << "� ������ ��� ������ !!!\n";
			return;
		}
	}
}

void printList()
{
	if (head != nullptr)
	{
		List* current = head->next;
		while (current != nullptr)
		{
			cout << current->simbol;
			current = current->next;
		}
	}
	else
	{
		cout << "����� ����������� !!!\n";
	}
	cout << endl << endl;
}

void debugList()
{
	if (head == nullptr)
	{
		cout << "����� ����������� !!!\n";
		return;
	}
	if (head->next == nullptr)  //��������� ���� �� � ������ ������.
	{
		return;
	}

	List* prev = nullptr;
	current = head;
	while (current->next != nullptr)
	{
		//���������� �������� �������.
		//���� ��� ���������� ����: �������� - �������� , �� ������� ��� ����.

		if ((current->simbol == '(' & current->next->simbol == ')') ||
			(current->simbol == '[' & current->next->simbol == ']') ||
			(current->simbol == '{' & current->next->simbol == '}'))
		{

			prev->next = current->next->next;
			delete current->next;
			countMamorry--;
			delete current;
			countMamorry--;
			current = head;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}

	
		//���������, �������� �� ���� �� ���� ������.
		//���� ��, �� head ����� ��������� �� ����� ������ ������, �� �� �� null, ������ ������ ����������. 
	
		if(head->next != nullptr)
		{
			cout << "��������� ���� ������ ,  �������� �������������� ��������� ���������� !!!\n";
			return;
		}
		else
		{
			cout << "��������� ���� ������ ,  �������� �������������� ��������� ����� .\n";
		}
}

void delList()
{
	List* prev = nullptr;
	if (head != nullptr)
	{
		current = head;
		while (current->next != nullptr)
		{
			prev = current;
			current = current->next;
			delete prev;
			countMamorry--;
		}
		delete current;
		countMamorry--;
		head = nullptr;
		current = nullptr;
		prev = nullptr;
		//cout << "����� �����\n\n";
		cout << "counterMamorry = " << countMamorry << endl << endl;
	}
	else
	{
		cout << "����� ����������� !!!\n";
	}
}


int main()
{

	setlocale(LC_ALL, "rus");
	setList();
	printList();
	debugList();
	delList();
	return 0;
}