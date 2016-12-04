/*************************************************************************
    > File Name: test.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Sat 26 Nov 2016 06:37:48 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<string>
template <typename T>
T fun( T a, T b )
{
    T c;
	try( c=a/b )
		if( b==0 )
			throw "chushu can not be 0!";
	return c;
}
void Creat_objects()
{
	string s1(10,'c');
	cout<<s1<<endl;
	string s2( s1 );
	cout<<s2<<endl;
	string s3( "ddddddddddddddddd");
	cout<<s3<<endl;

	string s4 = "abccccddfjdkfdjkfl";
	cout<<s4<<endl;

}
void Property_Of_String( string& str )
{
	cout<<str.capacity();
}
int main()
{
//	Creat_objects();
	string   str1("addddddbcccc");
	Property_Of_String( str1 );
	float  a,b,c;
	while( 1 )
	{
    cout<<"input some number"<<endl;
	cin>>a>>b;
	c = fun();
    catch( char * e )
	{
		cout<<e<<endl;
		cout<<"input error!";
	}
	}


	return 0;
}
