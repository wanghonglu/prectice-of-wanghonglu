/*************************************************************************
    > File Name: leetcode.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Sat 17 Dec 2016 02:32:15 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<string>
#include<vector>
class Solution {
public:
    int romanToInt(string s) {
    struct R_I{
		          char roman ;
		          int  int_num;
	           };
	R_I num[7]={{ 'I',1},{ 'V',5},{ 'X',10},{ 'L',50},{ 'C',100},{ 'D',500},{ 'M',1000} };
    int i = 0;
	int j=0;
	vector<int> temp;
	while( i<s.size())
	{
		j = 0;
		while( j!=7 )
		{
			if( s[i] == num[ j ].roman )
				break;
			j++;
		}
		if( j==7 )
		{
			cerr<<"input err"<<endl;
			return -1;
		}
		temp.push_back( num[ j ].int_num );
		i++;
	}
    vector<int>::iterator it;
	int interger =0;
	for( it=temp.begin();it!=temp.end();it++ )
	{
		if( *it < *(it+1 ) )
			interger -= *it;
		else
		{
			interger+=*it;
		}

	}   
	return interger;
	}
};
int main()
{
    Solution b;
    string s( "MCDLXXVI" );
    cout<<b.romanToInt( s )<<endl;   
	return 0;
     
}
