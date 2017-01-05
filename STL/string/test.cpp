/*************************************************************************
    > File Name: test.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Sat 26 Nov 2016 06:37:48 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<string>
#include<vector>
int main()
{
	vector<char>v1 = {'a','b','c','d'};
	char  a[]="adfbc";
	string s2 ( a, 3 );
	vector<char>::iterator it;
	cout<<s2<<endl;
	string s3( v1.begin(),v1.end());
	cout<<s3<<endl;



	return 0;
}
