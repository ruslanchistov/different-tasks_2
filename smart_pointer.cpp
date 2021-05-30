#include<iostream>
using namespace std;

template<typename T>
class SmartPointer
{
	T* ptr;
public:
	SmartPointer(T*ptr)
	{
		this->ptr = ptr;
	}
	~SmartPointer()
	{
		delete ptr;
		ptr = nullptr;
	}

	T& operator*()//~~~~~~~���������� ��������� *
	{
		return *ptr;
	}
};

int main()
{
	SmartPointer<int>point = new int(10);
	*point = 1000;
	cout << *point << endl;
	return 0;
}