#include<iostream>
using namespace std;

class Array
{
	int* Content;
public:
	const int Length;
	//------------------------------------------
	Array(int* theMass, int theNum) : Length(theNum)
	{
		if (theMass == nullptr)
		{
			throw "Undefined pointer";
		}
		Content = theMass;
		
	}
	// ------------------------------------------
		Array(const Array & theArray) : Length(theArray.Length)
	{
		Content = new int[Length];
		for (int Iter = 0; Iter < Length; Iter++)
		{
			Content[Iter] = theArray.Content[Iter];
			cout << theArray.Content[Iter] << "\t";
		}
		cout << endl << "Length  " << Length << endl;
	}

	//------------------------------------------
	~Array()
	{
		delete[]Content;
	}
};                     
int main()
{
	int mass[6] = { 1,2,3,4,5,6 };
	
	int* pmass = mass;
	Array Ar1(pmass,6);
	Array Ar2 = Array(Ar1);
	
	return 0;

}