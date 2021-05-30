#include<iostream>
using namespace std;


class AClass
{
public:
	int iVar;
	AClass(int theVar)
	{
		iVar = theVar;
	}
	AClass(const AClass& theParam)
	{
		iVar =  theParam.iVar;
	}
};


int main()
{
	AClass ex(10);
	cout << ex.iVar << endl;
	return 0;
}