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
	in_file.open( "/home/wanghonglu/Tx200501_20161214.xml" );
    if( !in_file.good() )
	{
		cerr<<"err!"<<endl;
	    return -1;
	}
	long  len =0;
	in_file.seekg( 0,ios::end );
	len =in_file.tellg();
	cout<<len<<endl;
	char *p=new char[ len+1 ];
	in_file.read( p, len );
	cout<<p<<endl;

    in_file.close();

	return 0;
}

