#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct{
     char     name[100];
	 int      num;
}PRE;
int order_by_name( const void *a, const void *b )
{
	return strcmp( ( (  PRE * )a)->name,((  PRE * )b)->name );
}
int order_by_num( const void *a, const void *b )
{
	return (( PRE* )a)->num - (( PRE* )b)->num;
}
void display( PRE*  a , int n )
{
	int   i =0;
	for( i=0;i<n;i++ )
		printf( "%s   %5d\n", a[i].name, a[i].num);
	printf( "\n" );
}
int main( int argc, char **argv )
{
PRE exp[]={
     { "wang", 98 },
     { "zhaoxi", 79 },
     { "ifjj", 34 },
     { "aaad", 76 },
     { "fjdk", 123 },
     { "fjdk", 876 },
     { "ikjj", -12 },
     { "eeee", 0 },
     { "olll", 97 }
};
	display( exp, sizeof( exp )/sizeof( PRE ) );
	qsort( exp, sizeof( exp )/sizeof( PRE ), sizeof( PRE ), order_by_name );
	display( exp, sizeof( exp )/sizeof( PRE ) );

#if 0
	qsort( exp, sizeof( exp )/sizeof( PRE ), sizeof( PRE ), order_by_name );
	display( exp, sizeof( exp )/sizeof( PRE ) );
#endif
	if( argc != 2 )
    {
		fprintf( stderr, "file[%s]line[%d] input err \n ", __FILE__, __LINE__ );
		return -1;
	}
	char *ptr = ( char * )bsearch( argv[1], exp, sizeof( exp )/sizeof( PRE ), sizeof( PRE ), order_by_name );
	if( ptr == NULL )
	    fprintf( stderr, "%s not fund\n ", argv[1]);
	else
	    fprintf( stderr, "the num of %s is %d \n ", argv[1], *( int* )( ptr+100 ) );

	return 0;
}

