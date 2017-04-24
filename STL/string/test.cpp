/*************************************************************************
    > File Name: test.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Sat 26 Nov 2016 06:37:48 AM PST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#include<string>
#include<vector>
//template <typename T>
int compare( int a, int b )
{
	return a>b?1:0;
}
int main()
{
#if 0
	vector<char>v1 = {'a','b','c','d'};
	char  a[]="adfbc";
	string s2 ( a, 3 );
	vector<char>::iterator it;
	cout<<s2<<endl;
	string s3( v1.begin(),v1.end());
	cout<<s3<<endl;

    string s4( "abc" ),s5 = s4;
	s4.insert( s4.size(), "efg" );
	cout<<s4<<endl;
	s5.append( "efg" );
	cout<<s5<<endl;

	s4.erase( 4, 2 );
	s4.insert( 4, "kk" );
	cout<<s4<<endl;

	s5.replace( 4, 2, "kk" );
	cout<<s5<<endl;
#endif
	vector<int>v1;
	int temp = 0;
	while( cin>>temp  )
		v1.push_back( temp );
	std::sort( v1.begin(), v1.end() );
//	sort( v1, v1.end() );

	vector<int>::iterator it = v1.begin();
	cout<<*it<<endl;
	while( it != v1.end() )
	{
	    cout<<*it<<"  ";
		it++;
	}

	cout<<endl;

	std::sort( v1.begin(), v1.end(), compare );
	it = v1.begin();
	while( it != v1.end() )
	{
	    cout<<*it<<"  ";
		it++;
	}

	cout<<endl;


	return 0;
}
