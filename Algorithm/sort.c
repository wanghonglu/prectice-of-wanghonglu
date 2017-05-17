#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<errno.h>
#include<string.h>

#define FILE_PATH "/home/wanghonglu/prectice/Algorithm/test.txt"
int sys_time( char*msg )
{
	time_t   sec;
	struct   tm* tmp;

	time( &sec );
	tmp = localtime( &sec );

	fprintf( stdout, "%s: %04d%02d%02d%02d%02d%02d\n",msg, tmp->tm_year+1900, tmp->tm_mon+1, tmp->tm_mday,tmp->tm_hour, tmp->tm_min, tmp->tm_sec );

	return 0;
}

int  creat_data_for_test()
{
	FILE   *fp = NULL;

	long    data = 0, i;

	if( NULL == ( fp = fopen( FILE_PATH, "w" ) ) )
	{
		fprintf( stderr, "fopen error:%s\n", strerror( errno ) );
		return -1;
	}
	for( i=0;i<100000;i++ )
	{
		data  = random()%100000;
		fprintf( fp, "%ld\n", data );
	}
	fclose( fp );
}
int read_data( long**p )
{
	FILE    *fp = NULL;
	char    buf[1024]={0};
	int     i = 0;
	long    *tmp = NULL;
	if( NULL == ( *p = ( long* )malloc( 100000*sizeof( long )+10 ) ) )
	{
		fprintf( stderr, "malloc error:%s\n", strerror( errno ) );
		return -1;
	}
	tmp = *p;
	/*  *p的位置不能随着读入数据的移动而移动，这样的话在主程序里是没办法访问这片内存上的东西的，这里需要另一个指针的来读 */
	if( NULL == ( fp = fopen( FILE_PATH, "r" ) ) )
	{
		fprintf( stderr, "fopen error:%s\n", strerror( errno ) );
		return -1;
	}
	i=1;
	while( !feof( fp ) )
	{
		fscanf( fp, "%ld", tmp );
		tmp++;
	}
	fclose( fp );
	return 0;
	
}
int mao_pao_sort( long **p )
{
	long *tmp = *p;
	long  num = 0;
	int  i = 0, j = 0;
	for( i=0;i<99999;i++ )
	{
		for( j=i;j<100000;j++ )
		if( tmp[i]>tmp[j] )
		{
			num = tmp[i];
			tmp[i]=tmp[j];
			tmp[j] = num;
		}
	}
	return 0;
}
int qsort_compare( const void*a, const void*b )
{
	return *(long*)a-*(long*)b;
}
void qsort_for_test( long**p  )
{
	return qsort( *p, 100000, sizeof( long ), qsort_compare );
}
int creat_file( char*file_name,  long **p  )
{
	FILE *fp = NULL;
	char  full_file_name[255]={0};
	long *tmp = NULL;
	sprintf( full_file_name, "/home/wanghonglu/prectice/Algorithm/%s", file_name );
	if( NULL == ( fp = fopen( full_file_name, "w" ) ) )
	{
		fprintf( stderr, "fopen error:%s\n", strerror( errno ) );
		return -1;
	}
	int i=0;
	/* 这里也是指针如果移动就等于改变了原来p的值 */
	tmp = *p;
	for( i=0;i<100000;i++ )
	{
		fprintf( fp, "%ld\t",*tmp  );
		tmp++;
	    if( i%10 == 0 &&i!= 0 )
			fprintf( fp, "\n" );
	}
	fclose( fp );
	return 0;
}
int main( int argc, char **argv )
{
	long *ptr = NULL;
    creat_data_for_test();
	read_data( &ptr );
	creat_file( "qsortfile_before", &ptr ); 

    sys_time( "befor qsort");
	qsort_for_test( &ptr );
    sys_time( "after qsort");
	creat_file( "qsortfile", &ptr ); 

	sys_time( "before maopao_sort" );
	mao_pao_sort( &ptr );
	sys_time( "after maopao_sort" );
	creat_file( "maopaofile", &ptr );

	return 0 ;
}

