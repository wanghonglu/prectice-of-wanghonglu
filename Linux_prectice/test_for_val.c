#include<stdarg.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<errno.h>
char *val_str( char*format, ...)
{
	static  char str[1024]={0};
	va_list   ap;

	va_start( ap, format );
	vsnprintf( str, sizeof( str ), format, ap );
	va_end( ap );

	return str;
}
int val_int( int _num, ... )
{
	va_list   ap;
	int       i = 0;

	va_start( ap, _num );
	for( ;i<_num;i++ )
		fprintf( stdout, "%d  ", va_arg( ap, int ) );
	printf( "\n" );

	return 0;
}
int main( int argc, char**argv )
{
	time_t  sec;
	struct tm *tmp = NULL;

	time( &sec );
	tmp = localtime( &sec );

	fprintf( stdout, "%s\n", val_str( "%04d%02d%02d", tmp->tm_year+1900, tmp->tm_mon+1, tmp->tm_mday ) );
	fprintf( stdout, "%s\n", val_str( "%04d%02d%02d%02d%02d%02d", tmp->tm_year+1900, tmp->tm_mon+1, \
							                  tmp->tm_mday, tmp->tm_hour, tmp->tm_min, tmp->tm_sec ) );
	val_int( 2, 4, 6 );
	val_int( 5, 1,2,3,4,5);


    return 0;
}
