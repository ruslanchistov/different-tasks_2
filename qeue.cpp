#include<iostream>
#include<string>
using namespace std;

struct List
{
	 char simbol ;
	List* next;
};

List* head = nullptr;
List* current = nullptr;
List* currentNext = nullptr;

int countMamory = 0;


void printList ()
{
	if (head != nullptr)
	{
		List* current = head;
		while (current != nullptr)
		{
			cout << current->simbol;
			current = current->next;
		}
	}
	else
	{
		cout << "У Вас пустой список !!!\n";
	}
	cout << endl<<endl;
}

void setList()
{
	cout << "Введите текст (не более 100 символов)" << endl;
	char simb[101] = {};
	cin.getline(simb, 100);

	current = new List;
	countMamory++;
	current->simbol = simb[0];
	current->next = nullptr;
	head = current;
	int i = 1;
	while (simb[i] != '\0')
	{
		current->next = new List;
		countMamory++;
		current = current->next;
		current->simbol = simb[i];
		current->next = nullptr;
		i++;
	}
}

void delList ()
{
	List* prev = nullptr;
	if (head != nullptr)
	{
		current = head;
		while (current != nullptr)
		{
			prev = current->next;
			if (prev == nullptr)
			{
				delete prev;
				countMamory--;
				break;
			}
			else
			{
				delete current;
				countMamory--;
				current = prev;
			}
		}
		head = nullptr;
		current = nullptr;
		prev = nullptr;
		cout << "Список удалён\n\n";
		cout << "counterMamory = " << countMamory << endl<<endl;
	}
	else
	{
		cout << "У Вас пустой список !!!\n";
	}
}

void debugList()
{
	if (head == nullptr)
	{
		cout << "Текст отсутствует !!!\n";
	}
	List* prev = nullptr;
	int i = 0;
	
	current = head;
	while (current->next != nullptr)
	{
		
		if (current->simbol == ' ' & current->next->simbol == ' ')
		{
			prev->next = current->next;
			delete current;
			countMamory--;
			current = prev->next;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

int main()
{
	
	setlocale(LC_ALL, "rus");
	setList();
	printList();
	debugList();
	printList();
	delList();	
	return 0;
}
