/*************************************************************************
    > File Name: test.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Sun 18 Dec 2016 02:59:49 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;
void reference( const char* &a )
{
//	cout<<a<<endl;
}
int main()
{
	char  a[]="abc";
	reference( a );

	return 0;
}
