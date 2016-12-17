/*************************************************************************
    > File Name: test.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Sat 17 Dec 2016 01:46:11 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<vector>
int main()
{
	vector<int> temp={1,2,3,4,5,6,7,8 };
	vector<int>::iterator it;
	for( it=temp.begin();it!=temp.end();it++ )
		cout<<*it<<"   ";
	cout<<endl;
	cout<<*(it+1 )<<endl;

	return 0;
}
