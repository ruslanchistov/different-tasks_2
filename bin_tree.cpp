#include<iostream>
using namespace std;

struct Node									   //Звенья дерева.
{
	int data;
	Node* left;
	Node* right;
	Node* prev;
};

struct Queue
{
	Queue* next;
	Node* node;
};

struct Stek
{
	int number;
	Stek* next;
	Stek* prev;
};

Node* root = nullptr;							//Корень дерева.

void Set_Tree(Node* &current, int num)
{
	if (current == nullptr)					   //Если дерева нет, то создаём корень.
	{
		current = new Node;
		current->data = num;
		current->left = nullptr;
		current->right = nullptr;
		current->prev = nullptr;
	}
	else
	{

		if (num < current->data)					//Если число меньше данного звена, то идём по левой ветке.
		{
			if (current->left != nullptr)			//Находим крайний узел.
			{
				Set_Tree(current->left, num);
			}
			else
			{
				current->left = new Node;			//Добавляем звено в левом поддереве.
				current->left->data = num;
				current->left->left = nullptr;
				current->left->right = nullptr;
				current->left->prev = current;
			}
		}
		else
		{

			if (num > current->data)					//Если число больше данного звена, то идём по правой ветке.
			{
				if (current->right != nullptr)			//Находим крайний узел.
				{
					Set_Tree(current->right, num);
				}
				else
				{
					current->right = new Node;			//Добавляем звено в правом поддереве.
					current->right->data = num;
					current->right->left = nullptr;
					current->right->right = nullptr;
					current->right->prev = current;
				}
			}
		
			else
			{
				num = num - 1;							//Иначе уменьшаем число и добавляем в левое поддерево.
				if (current->left != nullptr)
				{
					Set_Tree(current->left, num);
				}
				else
				{
					current->left = new Node;
					current->left->data = num;
					current->left->left = nullptr;
					current->left->right = nullptr;
					current->left->prev = current;
				}
			}
		}
	}
	
}

void Set_Rund_Tree(Node*& current)
{
	cout << "Введите количество узлов : ";
	int size = 0;
	cin >> size;
	cout << "Введите диапазон чисел от : ";
	int min = 0;
	cin >> min;
	cout << "Введите диапазон чисел до : ";
	int max = 0;
	cin >> max;
	int number = 0;
	for (int i = 0; i < size; i++)
	{
		number = rand() % max + min;
		Set_Tree(root, number);
	}
}

void Set_Hand_Tree(Node* &current)
{
	int number = 0;
	cout << "Введите количество узлов дерева : ";
	int size = 0;
	cin >> size;
	for(int i = 0; i < size; i ++)
	{
		cout << "Введите " << i + 1 <<" - е число :  ";
		cin >> number;
		Set_Tree(root,number);
	} 
}

void Get_Height_Direct_Tree(Node* &current)
{
	if (current != nullptr)								//Прохождение в глубину в прямом порядке.
	
	{
		cout << current->data << "\t";
		Get_Height_Direct_Tree(current->left);		
		Get_Height_Direct_Tree(current->right);
		
	}
}

void Get_Height_Reverse_Tree(Node* &current)
{
	if (current != nullptr)								//Прохождение в глубину в обратном порядке.

	{
		Get_Height_Reverse_Tree(current->left);
		Get_Height_Reverse_Tree(current->right);
		cout << current->data << "\t";
	}
}

void Get_Height_Symmetric_Tree(Node* &current)
{
	if (current != nullptr)								//Прохождение в глубину в симметричном порядке.

	{
		Get_Height_Symmetric_Tree(current->left);
		cout << current->data << "\t";
		Get_Height_Symmetric_Tree(current->right);
	}
}

void Get_Widht_Tree(Node* &current)
{
	Queue* Head = nullptr;
	Queue* Tile = nullptr;
	Queue* Del = nullptr;

	if (current != nullptr)
	{
		Head = new Queue;
		Head->next = nullptr;
		Head->node = current;
	}
	Tile = Head;
	
	while (Head != nullptr)
	{
		cout << Head->node->data << "\t";

		if (Head->node->left != nullptr)
		{
			Tile->next = new Queue;
			Tile = Tile->next;
			Tile->node = Head->node->left;
			Tile->next = nullptr;
		}
		if (Head->node->right != nullptr)
		{
			Tile->next = new Queue;
			Tile = Tile->next;
			Tile->node = Head->node->right;
			Tile->next = nullptr;
		}
		Del = Head;
		Head = Head->next;
		delete Del;
	}
}

void Del_Tree(Node* &current)
{
		if (current != nullptr)
		{
			Del_Tree(current->left);
			Del_Tree(current->right);
			delete current;
			current = nullptr;
		}
}

int Meter_Height_Tree(Node* &current)
{
	int Left_Height = 0;
	int Right_Height = 0;
	if (current->left != nullptr)
	{
		Left_Height = Meter_Height_Tree(current->left);
	}
	if (current->right != nullptr)
	{
		Right_Height = Meter_Height_Tree(current->right);
	}
	if (Left_Height > Right_Height)
	{
		return Left_Height + 1;
	}
		return Right_Height + 1;
}

int Meter_Height_Tree_2(Node*& current)
{
	int left_height = 0;
	int right_height = 0;
	if (current->left != nullptr)
	{
		left_height = Meter_Height_Tree_2(current->left);
	}
	if (current->right != nullptr)
	{
		right_height = Meter_Height_Tree_2(current->right);
	}
	if (left_height <= right_height)
	{
		return left_height + 1;
	}
	else
	{
		return right_height + 1;
	}
}

int Meter_Widht_Tree(Node* &current)
{
	int Left_Widht = 0;
	int Right_Widht = 0;
	if (current->left != nullptr)
	{
		Left_Widht = Meter_Widht_Tree(current->left);
	}
	if (current->right != nullptr)
	{
		Right_Widht = Meter_Widht_Tree(current->right);
	}
	return Left_Widht + Right_Widht + 1;
}

void  FullArray(int** Array_PRN, Node*& root, int Left_Border, int Right_Border, int Cur_Height)
{
	int i;
	int Medium = (Right_Border + Left_Border) / 2;
	if (root->left != NULL)
	{
		for (i = (Left_Border + Medium) / 2; i < Medium; i++)
		{
			Array_PRN[Cur_Height][i] = -1;
		}
		Array_PRN[Cur_Height][(Left_Border + Medium) / 2] = -2;

		FullArray(Array_PRN, root->left, Left_Border, Medium, Cur_Height + 1);
	}
	if (root->right != NULL)
	{
		for (i = Medium; i < (Right_Border + Medium) / 2; i++)

		{
			Array_PRN[Cur_Height][i] = -1;
		}
		Array_PRN[Cur_Height][(Right_Border + Medium) / 2] = -3;
		FullArray(Array_PRN, root->right, Medium, Right_Border, Cur_Height + 1);
	}

	Array_PRN[Cur_Height][(Right_Border + Left_Border) / 2] = root->data;
	return;
}

void Print_Tree(Node*& current)
{
	int Height_Tree = Meter_Height_Tree(root);
	int Weight_Tree = Meter_Widht_Tree(root);
	int** Array_PRN;
	int i, j;
	printf("\n");
	printf("tree_Height = %d\n", Height_Tree);
	printf("tree_Widht = %d\n", Weight_Tree);
	Array_PRN = new int* [Height_Tree];

	for (i = 0; i < Height_Tree; i++)
	{
		Array_PRN[i] = new int[Weight_Tree * 4];
	}
	for (i = 0; i < Height_Tree; i++)
	{
		for (j = 0; j < Weight_Tree * 4; j++)
		{
			Array_PRN[i][j] = 0;

		}


	}
	FullArray(Array_PRN, root, 0, Weight_Tree * 4, 0);
	printf("\n");
	for (i = 0; i < Height_Tree; i++)

	{
		printf("\n");
		for (j = 0; j < Weight_Tree * 4; j++)
		{
			if (Array_PRN[i][j] > 0)
			{
				printf("%d", Array_PRN[i][j]);
			}
			else if (Array_PRN[i][j] == -1)
			{
				printf("-");
			}
			else if (Array_PRN[i][j] == -2)
			{
				printf("/");
			}
			else if (Array_PRN[i][j] == -3)

			{
				printf("\\");
			}
			else printf(" ");
		}
	}
	printf("\n");
	for (i = 0; i < Height_Tree; i++)
	{
		delete[] Array_PRN[i];
	}
	delete[] Array_PRN;


}

int Print_Height_Direct_2_Tree(Node*& current, int flag)
{
	if (flag != 0)
	{
		cout << current->data <<"  ";
	}
	flag = 1 - flag;
	if (current->left != nullptr)
	{
		 flag = Print_Height_Direct_2_Tree(current->left, flag);
	}
	if (current->right != nullptr)
	{
		Print_Height_Direct_2_Tree(current->right, flag);
		flag = 1 - flag;
	}
	return flag;
}

void Get_Height_Reverse_No_Even(Node*& current)
{
	if (current->left != nullptr)
	{
		Get_Height_Reverse_No_Even(current->left);
	}
	if (current->right != nullptr)
	{
		Get_Height_Reverse_No_Even(current->right);
	}
	if (current->data % 2 != 0)
	{
		cout << current->data << "\t";
	}
}

void Get_Height_Even_Level(Node*& current,int flag)
{
	if (flag % 2 == 0)
	{
		cout << current->data<< "\t";
	}
	if (current->left != nullptr)
	{
		Get_Height_Even_Level(current->left, flag + 1);
	}
	if (current->right != nullptr)
	{
		Get_Height_Even_Level(current->right, flag + 1);
	}
}

void Get_Lowest_Sheet(Node*& current,int Height)
{
	if (Height == 1)
	{
		cout << current->data << "\t";
	}
	if (current->left != nullptr)
	{
		Get_Lowest_Sheet(current->left, Height - 1);
	}
	if (current->right != nullptr)
	{
		Get_Lowest_Sheet(current->right, Height - 1);
	}
}

void Get_Lowest_Sheet_1(Node*& current)
{
	int Height = Meter_Height_Tree(root);
	Get_Lowest_Sheet(root, Height);
}

void Get_Tallest_Sheet_1(Node*& current, int Height)
{
	if ((1 == Height) && (current->left == NULL) && (current->right == NULL))
	{
		cout << current->data << "\t";
	}
	if (current->left != NULL)
	{
		Get_Tallest_Sheet_1(current->left, Height - 1);
	}
	if (current->right != NULL)
	{
		Get_Tallest_Sheet_1(current->right, Height - 1);
	}
}

void Get_Tallest_Sheet(Node*& current)
{
	int height = Meter_Height_Tree_2(root);
	Get_Tallest_Sheet_1(root, height);
}

int Even_Height(Node*& current)

//Определяем длинну самой длинной чётной цепочки
{
	int Left_Height = 0;
	int Right_Height = 0;
	if (current->data % 2 == 0)
	{
		if (current->left != nullptr)
		{
			Left_Height = Even_Height(current->left);
		}
		if (current->right != nullptr)
		{
			Right_Height = Even_Height(current->right);
		}
		if (Left_Height > Right_Height)
		{
			return Left_Height + 1;
		}
		return Right_Height + 1;
	}
	return 0;
}

void Even_Long_Print(Node*& current, int heigh)
{
	Stek* Head = nullptr;
	Stek* Tile = nullptr;
	Stek* Del = nullptr;
	int count = 0;
	if (current->data % 2 == 0)       //Если узел чётный создаём двусвязный список и заносим его в голову.
	{

		Head = new Stek;
		count++;
		Head->number = current->data;
		Head->next = nullptr;
		Head->prev = nullptr;
		Tile = Head;
		current = current->prev;
		while ((current != nullptr)&&(current->data % 2 == 0)) //Записываем в список узлы ,пока не дойдём до корня
															   //	или нечётного числа.
		{
			Tile->next = new Stek;
			count++;
			Tile->next->prev = Tile;
			Tile = Tile->next;
			Tile->number = current->data;
			Tile->next = nullptr;
			current = current->prev;			
		}
		if (count == heigh)										//Проверяем является ли данная цепочка самой длинной.
			{
				while (Tile != nullptr)
				{
					cout << Tile->number << "\t";				//Если да, то распечатываем и удаляем.
					Tile = Tile->prev;
				}
					cout << "\n\n";
			
			}
		while (Head != nullptr)									//Если нет, просто удаляем.
		{
			Del = Head;
			Head = Head->next;
			delete Del;
		}
	}
}

void Even_Transit(Node*& current, int height,int heigh)
{

	if ((current->left != nullptr) && (height > 1))
	{
		Even_Transit(current->left, height - 1,heigh);
	}
	if ((current->right != nullptr) && (height > 1))
	{
		Even_Transit(current->right, height - 1,heigh);
	}
	Even_Long_Print(current, heigh);
	return;
}

void Get_Long_Road_Even_Node(Node*& current)
{
	int height = Even_Height(root);
	int heigh = height;
	Even_Transit(root, height,heigh);
	
}

int Pull_Down_No_Even_Node_2(Node*& current,int count)
{
	
	if (current->data % 2 != 0)
	{
		if ((current->left != nullptr)&&(current->left->data % 2 == 0))
		{
			swap(current->data, current->left->data);
			count++;
		}
		if ((current->right != nullptr) && (current->right->data % 2 == 0))
		{
			swap(current->data,current->right->data);
			count++;
		}
	}
	if (current->left != nullptr)
	{
		Pull_Down_No_Even_Node_2(current->left,count);
	}
	if (current->right != nullptr)
	{
		Pull_Down_No_Even_Node_2(current->right,count);
	}
	return count;
}

void Pull_Down_No_Even_Node(Node*& current)
{
	int count = 0;
	do
	{
		count = 0;
		count = Pull_Down_No_Even_Node_2(root,count);
		
	} while ( count != 0);
}

void Menu()
{
	int menu;
	
	do
	{
		cout << "\n\n\n\n";
		cout << " МЕНЮ:\n";
		cout << "1 - Создать дерево с помощью генератора -\n";
		cout << "2 - Создать дерево вручную -\n";
		cout << "3 - Распечатать дерево в высоту в прямом порядке - \n";
		cout << "4 - Распечатать дерево в высоту в обратном порядке - \n";
		cout << "5 - Распечатать дерево в высоту в симметричном порядке - \n";
		cout << "6 - Распечатать дерево в ширину - \n";
		cout << "7 - Измерить высоту дерева - \n";
		cout << "8 - Измерить ширину дерева - \n";
		cout << "9 - Прямой обход дерева(вершины через одну) - \n";
		cout << "10 - Обратный обход дерева в глубину (вершины нечётные) -\n";
		cout << "11 - Прямой обход дерева ( чётные уровни) - \n";
		cout << "12 - Распечатать самый низкий лист(листья) в дереве -\n";
		cout << "13 - Распечатать самый высокий лист(листья) в дереве - \n";
		cout << "14 - Распечатать самые длинные пути в дереве с чётными вершинами - \n";
		cout << "15 - Сместить нечётные вершины вниз - \n";
		cout << "16 - Распечатать дерево - \n";
		cout << "17 - Удалить дерево - \n";
		cout << "0 - Выход -\n";

		cin >> menu;
		switch (menu)
		{
		case 1:
			Set_Rund_Tree(root);
			break;
		case 2:
			Set_Hand_Tree(root);
			break;
		case 3:
			Get_Height_Direct_Tree(root);
			break;
		case 4:
			Get_Height_Reverse_Tree(root);
			break;
		case 5:
			Get_Height_Symmetric_Tree(root);
			break;
		case 6:
			Get_Widht_Tree(root);
			break;
		case 7:
			cout << "Высота дерева =  " << Meter_Height_Tree(root) << endl;
			break;
		case 8:
			cout << "Ширина дерева =  " << Meter_Widht_Tree(root) << endl;
			break;
		case 9:
			Print_Height_Direct_2_Tree(root,1);
			break;
		case 10:
			Get_Height_Reverse_No_Even(root);
			break;
		case 11:
			Get_Height_Even_Level(root, 1);
			break;
		case 12:		
			Get_Lowest_Sheet_1(root);
			break;
		case 13:
			Get_Tallest_Sheet(root);
			break;
		case 14:
			Get_Long_Road_Even_Node(root);
			break;
		case 15:
			Pull_Down_No_Even_Node(root);
			break;
		case 16:
			Print_Tree(root);
			break;
		case 17:
			Del_Tree(root);
			break;
		case 0:
			break;
		default:
			cout << "Не корректный ввод !!! \n";
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


