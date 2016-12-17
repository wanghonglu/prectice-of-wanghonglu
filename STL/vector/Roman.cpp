/*************************************************************************
    > File Name: Roman.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Sat 17 Dec 2016 12:50:47 AM PST
 ************************************************************************/
#include<iostream>
using namespace std;
#include<vector>
#include<string>
//　　I=1；X=10；C=100；M=1000；
//　　V=5；L=50；D=500；
int main( int argc, char **argv )
{
    struct R_I{
		char roman ;
		int integer;
	};
	R_I num[7]={{ 'I',1},{ 'V',5},{ 'X',10},{ 'L',50},{ 'C',100},{ 'D',500},{ 'M',1000} };
    string s("XCVIII");
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
		temp.push_back( num[ j ].integer );
		i++;
	}
    vector<int>::iterator it;
	int interger =0;
	for( it=temp.begin();it!=temp.end();it++ )
	{
//		cout<<*it<<"    "<<interger<<endl;
		if( *it < *(it+1 ) )
			interger -= *it;
		else
		{
			while( it!=temp.end() )
			{
				interger+=*it;
				it++;
			}
			break;
		}

	}
	cout<<interger<<endl;
	cout<<endl;

	return 0;
}
