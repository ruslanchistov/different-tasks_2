//����������� ����� ������� ���� � ������ � ������� ���������



int Even_Height(Node*& current)

																//���������� ������ ����� ������� ������ �������.
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
	if (current->data % 2 == 0)									//���� ���� ������ ������ ���������� ������ 
																//� ������� ��� � ������.
	{

		Head = new Stek;
		count++;
		Head->number = current->data;
		Head->next = nullptr;
		Head->prev = nullptr;
		Tile = Head;
		current = current->prev;
		while ((current != nullptr) && (current->data % 2 == 0)) //���������� � ������ ���� ,���� �� ����� �� �����
															     //	��� ��������� �����.
		{
			Tile->next = new Stek;
			count++;
			Tile->next->prev = Tile;
			Tile = Tile->next;
			Tile->number = current->data;
			Tile->next = nullptr;
			current = current->prev;
		}
		if (count == heigh)										//��������� �������� �� ������ ������� ����� �������.
		{
			while (Tile != nullptr)
			{
				cout << Tile->number << "\t";				    //���� ��, �� ������������� � �������.
				Tile = Tile->prev;
			}
			cout << "\n\n";

		}
		while (Head != nullptr)									//���� ���, ������ �������.
		{
			Del = Head;
			Head = Head->next;
			delete Del;
		}
	}
}

void Even_Transit(Node*& current, int height, int heigh)
{																//���������� ���� ������� � ������,��� �������������
																//����� ������� ������ �������.
	if ((current->left != nullptr) && (height > 1))
	{
		Even_Transit(current->left, height - 1, heigh);
	}
	if ((current->right != nullptr) && (height > 1))
	{
		Even_Transit(current->right, height - 1, heigh);
	}
	Even_Long_Print(current, heigh);
	return;
}
