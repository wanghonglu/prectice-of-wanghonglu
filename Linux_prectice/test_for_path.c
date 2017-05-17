#include<errno.h>
#include<dirent.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main( int argc, char** argv )
{
	DIR   *dp = NULL;
	struct dirent *dir = NULL;

	if( argc != 2 )
	{
		fprintf( stdout, "user : a.out filepath" );
		return -1;
    }

	if( NULL == ( dp = opendir( argv[1] ) ) )
	{
		fprintf( stderr, "opendir error: %s\n", strerror( errno ) );
		return -1;
	} 
	while( NULL!= ( dir = readdir( dp ) ) )
	{
		fprintf( stdout, "%s\n", dir->d_name );
	}
	closedir( dp );
	free( dir );

	return 0 ;
}
