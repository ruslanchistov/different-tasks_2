#include<iostream>
using namespace std;
class Example
{
	static int Value;
public:
	static void setValue(int theValue)
	{
		Value = theValue;
	}
	static int getValue()
	{
		return Value;
	}
} exExam;


int Example::Value;// ���� ������ ��� ������, �� ����� ������ � ��������� �� 1 ������(������������� ������� ������).

//-------------------------------------------
int main ()
{
	exExam.setValue(10);
	int OldValue = Example::getValue();
	cout << OldValue << endl;
	return 0;
}