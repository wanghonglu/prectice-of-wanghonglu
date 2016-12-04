#include<iostream>
using namespace std;
int main( int argc, char * argv[])
{
	int a[ 2 ]={	1,2 };
    int *p = a;
//	cout<<p<<static_cast(void*)(p)<<endl;
    cout<<p<<endl; 
    cout<<p+1<<endl; 
    cout<<p+2<<endl; 
    cout<<p+3<<endl; 
	return 0;   
}
