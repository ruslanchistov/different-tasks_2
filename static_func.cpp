#include<iostream>
using namespace std;

class Data
{
	 static int var;
public:
	
	 static void set(int n)
	{
		var = n;
		cout << var << endl;
	}
};
int Data::var;
int main()
{
	Data::set(55);
	return 0;

}