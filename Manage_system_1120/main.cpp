/*************************************************************************
    > File Name: main.cpp
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Sun 20 Nov 2016 04:22:28 AM PST
 ************************************************************************/
#include "man_sys.h"
int main()
{
    int  sign = 0; 
	man_sys *head = NULL;
	while( 1 )
	{
	    display();
		cin>>sign;
		switch( sign )
		{
		case 1 :
			head = head->creat_node( head );
			break;
		case 2 :
			head = head->delete_node( head );
			break;
		case 3 :
			head->display_node( head );
			break;
		case 4 :
			head = head->increase_node( head );
			break;
		case 5 :
			head = head->reverse( head );
			break;
		default :
			return 0;
			break;
		}

	}






	return 0;
}

