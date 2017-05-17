#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
struct NameList{
	char  name[60];
	struct NameList *next;
};
int main( )
{
	char    tmp[60]={0};
	struct NameList * head = NULL, *p1, *p2;
	while( 1 )
	{
		memset( tmp, 0x00, sizeof( tmp ) );
	    printf( "请输入名字， 结束请输入end !\n" );
		scanf( "%s", tmp );
		if( strcmp( tmp, "end" ) == 0 )
			break;
		if( NULL == ( p1 = ( struct NameList* )malloc( sizeof( struct NameList ) ) ) )
		{
			printf( "malloc error:%s\n", strerror( errno ) );
			return -1;
		}
		memset( p1, 0x00, sizeof( struct NameList ) );
		strcpy( p1->name, tmp );
		if( head == NULL )
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
	}
	p2->next = NULL;
	while( head != NULL )
	{
		printf( "\t%s\n", head->name );
		head = head->next;
	}

	return 0;
}
