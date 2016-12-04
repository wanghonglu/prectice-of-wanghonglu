/*************************************************************************
    > File Name: Man_sys.h
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Sun 20 Nov 2016 03:26:31 AM PST
 ************************************************************************/
#ifndef MAN_SYS_H
#define MAN_SYS_H
#include<iomanip>
#include<string.h>
#include<iostream>
using namespace std;
class man_sys
{
	public :
	man_sys()
	{

	}
	~man_sys()
	{
        if( ptr != NULL )
		    delete ptr;
	}
	man_sys * creat_node( man_sys *head );
	man_sys * delete_node( man_sys *head );
	man_sys * increase_node( man_sys *head );
	man_sys * reverse( man_sys *head );
    int  display_node( man_sys *head );
	private :
		char  name[ 60 ];
		int   score;
		int   num;
		man_sys * ptr;
};
int display();
#endif;
