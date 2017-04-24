#include<stdlib.h>
#include<iostream>
#include<algorithm>
int compare( const void *a, const void *b )
{
	return *( int * )a - *( int * )b;
}
int compare_another( const void *a, const void *b )
{
	return *( int * )b - *( int * )a;
}
int compare_for_sort( int a, int b )
{
	if( a<b )
		return 1;
	else
		return 0;
}
int compare_for_sort_another( int a, int b )
{
	if( a>b )
		return 1;
	else 
		return 0;
}
int main( int argc, char ** argv )
{
    int num[]={1,90,-45,789,334,2,345,76,12,-987,0,56,2};
	int i = 0;
	for( i=0;i<sizeof( num )/sizeof( int );i++ )
		std::cout<<num[ i ]<<"  ";
    std::cout<<std::endl;
#if 0
	qsort( num, sizeof( num )/sizeof( int ), sizeof( int ), compare );

	for( i=0;i<sizeof( num )/sizeof( int );i++ )
		std::cout<<num[ i ]<<"  ";
    std::cout<<std::endl;

	qsort( num, sizeof( num )/sizeof( int ), sizeof( int ), compare_another );
	for( i=0;i<sizeof( num )/sizeof( int );i++ )
		std::cout<<num[ i ]<<"  ";
    std::cout<<std::endl;
#endif
	std::sort( num, num+( sizeof( num )/sizeof( int ) ) );

	for( i=0;i<sizeof( num )/sizeof( int );i++ )
		std::cout<<num[ i ]<<"  ";
    std::cout<<std::endl;

	std::sort( num, num+( sizeof( num )/sizeof( int ) ), compare_for_sort );

	for( i=0;i<sizeof( num )/sizeof( int );i++ )
		std::cout<<num[ i ]<<"  ";
    std::cout<<std::endl;

	std::sort( num, num+( sizeof( num )/sizeof( int ) ), compare_for_sort_another );

	for( i=0;i<sizeof( num )/sizeof( int );i++ )
		std::cout<<num[ i ]<<"  ";
    std::cout<<std::endl;
    


	return 0;
}

