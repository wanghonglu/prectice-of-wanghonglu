/*************************************************************************
    > File Name: file.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: Wed 14 Dec 2016 04:55:19 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main( int argc, char ** argv )
{
	FILE     *fp = NULL;
	long     len = 0;
	char     *ptr = NULL;

	fp = fopen( "/home/wanghonglu/Tx200501_20161214.xml", "r" );
	fseek( fp, 0, SEEK_END );
	len = ftell( fp );
	rewind( fp );
	ptr = ( char * )malloc( len+1 );
	fread( ptr, len, 1, fp );
	
	printf( "%s\n", ptr );

	free( ptr );

	fseek( fp, 0, SEEK_SET );
	char    c;
	int     num =0;
	while( 1 )
	{
		c = fgetc( fp );
		if( c== EOF )
			break;
		if( c == 's' )
			num++;
	}
	printf( "%d\n", num );
	fclose( fp );

	return 0;

}
