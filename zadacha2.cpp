#include<iostream>
using namespace std;

class Array
{
	int* Content;
public:
	int size;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Array(int*pmass, int size)
	{
		this->size = size;
		this-> Content = new int[size];
		for (int i = 0; i < size; i++)
		{
			Content[i] = pmass[i];
		}
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Array(Array& ex)
	{
		this->size = ex.size;
		this->Content = new int[ex.size];
		for(int i = 0; i < ex.size; i ++)
		{
			this->Content[i] = ex.Content[i];
			cout << ex.Content[i] << "\t";
		}
		cout << endl << "size  : " << ex.size << endl;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~Array()
	{
		delete[]Content;
		Content = 0;
	}
};

int main()
{
	int mass[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* pmass = mass;
	Array Ar1(pmass, 10);
	Array Ar2(Ar1);
	pmass = 0;
	return 0;

}
		
		