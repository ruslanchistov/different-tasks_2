#include<iostream>
using namespace std;

class A
{
	int a_priv_data;
public:
	int a_public_data;
		class B
		{
			int b_priv_data;
			friend class A;
		public:

			void set(A ex, int d)
			{
				ex.a_priv_data = d;
				cout << ex.a_priv_data << endl;
			}
		};
		
		void set1(A::B ex, int e)
		{
			ex.b_priv_data = e;
			cout << ex.b_priv_data << endl;
		}
}data1;

int main()
{	
	A::B data2;
	data2.set(data1, 10);
	data1.set1(data2, 20);
	return 0;
}