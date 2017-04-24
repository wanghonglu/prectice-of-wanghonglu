#include<stdio.h>
int main()
{
	char   buf[ 1024 ];
	int    d;
	fprintf( stdout, "input msg\n" );
	scanf( "%d", &d );
	fgets( buf, sizeof( buf ), stdin );
	printf( "%s\n", buf );

	return 0;
}
