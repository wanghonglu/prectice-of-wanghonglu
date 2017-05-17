#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
int main()
{
	char   a[1024];
	int    n = 0;

	memset( a, 0x00, sizeof( a ) );
	while( ( n = read( STDIN_FILENO, a, sizeof( a ) ) ) >0 )
			if( n!= write( STDOUT_FILENO, a, n ) )
				fprintf( stderr, "write error:%s\n", strerror( errno ) );
	if( n<0 )
		fprintf( stderr, "read error:%s\n", strerror( errno ) );

	return 0;
}
