/*************************************************************************
    > File Name: test.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Wed 21 Dec 2016 04:53:46 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct NODE 
{
	char  c;
	struct NODE  *next;
}NODE;
int main()
{
	NODE  *head = NULL, *p1 = NULL, *p2 = NULL ;
	char  temp;
	while( 1 )
	{
		scanf( "%c", &temp );
		if( temp == '.' )
			break;
		p1 = ( NODE * )malloc( sizeof( NODE ) );
		p1->c = temp;
		if( head == NULL )
			head = p1;
		else 
			p2->next = p1;
		p2 = p1;
	}
	p2->next = NULL;
	int  num = 0;
	while( head != NULL )
	{
		if( head->c ==' ' )
		{
			printf( "%d ", num );
			num = -1;
		}
		num++;
		head = head->next;
		if( head == NULL )
			printf( "%d\n", num );
	}
	return 0;
}
