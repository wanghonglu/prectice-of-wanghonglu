#include<stdio.h>
int func( int _num )
{
	if( _num == 1 )
		return 1;

	return _num*func( _num-1 );
}
int main()
{
	int m, n;
	int i = 0;
	long sum = 0;
	while( 1 )
	{
		printf( "please input 'n' and 'm' (n<m),end with -1 \n" );
		scanf( "%d %d", &n, &m );
		if( n==-1 )
			break;
		if( n>m )
		{
			printf( "input error\n" );
			return -1;
		}
		for( i=n;i<=m; i++ )
		{
			sum = sum+func( i );
			if( i == m )
				printf( "%d!=%ld\n", i, sum );
			else
				printf( "%d!+", i );
		}
	}
	return 0;
}
