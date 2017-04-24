/*************************************************************************
    > File Name: fstream.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Wed 14 Dec 2016 06:50:37 AM PST
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream in_file;
	char a[ 3 ];
	char b[ 2 ];
	char c[ 2 ];
	in_file.open( "/home/wanghonglu/prectice/fstream/testfile.txt" );
    if( !in_file.good() )
	{
		cerr<<"err!"<<endl;
	    return -1;
	}
	in_file>>a;
	cout<<a<<endl;
	in_file.read( b, sizeof( b ) );
	cout<<b<<'\n';
	in_file>>c;
	cout<<c<<'\n';
#if 0
	//in_file.seekg( 35, ios::beg );
	long  len =0;
	in_file.seekg( 0,ios::end );
	len =in_file.tellg();
	cout<<len<<endl;
	char *p=new char[ len+1 ];
	in_file.read( p, len );
	//cout<<p<<endl;

    in_file.close();
#endif
	return 0;
}

