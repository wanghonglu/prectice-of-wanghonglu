/*************************************************************************
    > File Name: test.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Sun 18 Dec 2016 02:59:49 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;
class DE
{
    public:
		DE( int x ):a(x){}
		~DE(){}
		void test()
		{
			a+=2;
		}
		void test() const
		{
		    cout<<a<<endl;	
		}
		const void const display()
		{
			cout<<a<<endl;
		}
	private:
		int a;
};
class ME:public DE
{
	public :
		ME( int x, int y ): DE( 4 ),m(x),n(y){}
	private:
		int m;
		int n;

};
int main()
{
	DE a(9);
	a.display();

	ME b( 4, 5 );
	b.display();

	return 0;
}
