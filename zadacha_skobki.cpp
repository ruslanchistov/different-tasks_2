/*Дана конечная последовательность, состоящая из левых и правых скобок
различных заданных типов(«(» «{ » «[»«)» « }» «]»).Определить, можно ли добавить в
нее цифры и знаки арифметических действий так, чтобы получилось правильное
арифметическое выражение.*/



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
	cout << "Введите текст из скобок (не более 100 символов)" << endl;
	char simb[101] = {};
	cin.getline(simb, 100);

	if (simb[0] == '\0')
	{
		cout << "Текст отсутствует !!!\n";
		return;
	}
	else
	{
		current = new List;     //Создаём пустую ячейку, чтобы она не удалились в процессе обработки.
		countMamorry++;
		current->simbol = ' ';
		current->next = nullptr;
		head = current;
		int i = 0;
		while (simb[i] != '\0')  //Выбираем и записываем из введённого текста только скобки.
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
		if (head->next == nullptr)  //Проверяем были ли в тексте скобки.
		{
			cout << "В тексте нет скобок !!!\n";
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
		cout << "Текст отсутствует !!!\n";
	}
	cout << endl << endl;
}

void debugList()
{
	if (head == nullptr)
	{
		cout << "Текст отсутствует !!!\n";
		return;
	}
	if (head->next == nullptr)  //Проверяем были ли в тексте скобки.
	{
		return;
	}

	List* prev = nullptr;
	current = head;
	while (current->next != nullptr)
	{
		//Сравниваем соседние символы.
		//Если они составляют пару: открытая - закрытая , то удаляем эту пару.

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

	
		//Проверяем, осталась ли хотя бы одна скобка.
		//Если да, то head будет указывать на какую нибудь ячейку, но не на null, значит запись невозможна. 
	
		if(head->next != nullptr)
		{
			cout << "Используя Ваши скобки ,  записать математическое выражение невозможно !!!\n";
			return;
		}
		else
		{
			cout << "Используя Ваши скобки ,  записать математическое выражение можно .\n";
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
		//cout << "Текст удалён\n\n";
		cout << "counterMamorry = " << countMamorry << endl << endl;
	}
	else
	{
		cout << "Текст отсутствует !!!\n";
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