#include<iostream>
using namespace std;

class Array
{
	int Content [6];
public:
	 const int Length;
	 
	 //------------------------------------------
	 Array(int theMass [], int theNum) : Length(theNum)
	 {
		
		 for (int i = 0; i < Length; i++)
			 Content[i] = theMass[i];

	 }
	 //------------------------------------------
	 Array(const Array& theArray) : Length(theArray.Length)
	 {
		
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
	}
};                     
int main()
{
	int mass[6] = { 1,2,3,4,5,6 };
	
	
	Array Ar1(mass,6);
	Array Ar2 = Array(Ar1);
	
	return 0;

}