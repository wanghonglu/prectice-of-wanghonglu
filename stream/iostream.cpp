/*************************************************************************
    > File Name: iostream.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Tue 13 Dec 2016 05:54:53 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
	int  a;
	int  b;
    cin>>a;
	cout<<cin.fail()<<endl;
	cout<<a<<endl;;
	a=cin.get();
	cout.put(( int ) a );
	cout<<endl;
	return 0;
}
