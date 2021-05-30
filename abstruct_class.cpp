#include<iostream>
using namespace std;

class Motion
{
public:
	virtual void show() = 0;
};

class Left :public Motion
{
public:
	void show() override
	{
		cout << "left" << endl;
	}
};

class Right :public Motion
{
public:
	void show() override
	{
		cout << "right" << endl;
	}
};

class Up :public Motion
{
public:
	void show() override
	{
		cout << "up" << endl;
	}
};

class Down :public Motion
{
public:
	void show() override
	{
		cout << "down" << endl;
	}
};

class Player
{
public:
	void motion(Motion& ptr)
	{
		ptr.show();
	}
}player;

int main()
{
	Left left;
	Right right;
	Up up;
	Down down;

	int hod = 0;
	cin >> hod;

	switch (hod)
	{
	case 4:
		player.motion(left);
		break;
	case 6:
		player.motion(right);
		break;
	case 8:
		player.motion(up);
		break;
	case 2:
		player.motion(down);
		break;
	default:
		break;
	}
	
	
	return 0;
}