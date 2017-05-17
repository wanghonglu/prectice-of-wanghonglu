#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<errno.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<time.h>
char *get_sys_time();

int main( int argc, char ** argv )
{
	int       sockfd;
	char      str[ 1024 ]={0}; 
	char      send_str[ 1024 ]={0};
	struct    sockaddr_in   server_addr;
	char      buf[1024]={0};

	char      addr[30]={0};
	char      file_path[255]={0};
	struct    hostent* host = NULL;
	char      full_file[500]={0};

	char      file_name[255];


	if( argc != 2 )
	{
		fprintf( stderr, "a.out  web " );
		return -1;
	}
	strcpy( full_file, argv[1] );
	if( strstr( full_file,"/" ) != NULL )
	{
		strcpy( addr, strtok( full_file+strlen( "http://" ), "/" ) );
		strcpy( file_path, argv[1]+strlen( addr ) +strlen( "http://" ) );
	}
	fprintf( stdout, "addr:%s\nfile_path:%s\n", addr, file_path );
	if( NULL == ( host = gethostbyname(addr) ) )
	{
		perror( "host" );
		fprintf( stderr, "gethostbyname error:%s\n", strerror( errno ) );
		return -1;
	}

	memset( &server_addr, 0x00, sizeof( server_addr ) );
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr =*((struct in_addr *)host->h_addr) ;
	server_addr.sin_port = htons( 80 );


	if( -1 == ( sockfd = socket( AF_INET, SOCK_STREAM, 0 ) ) )
	{
		perror( "sockfd" );
		fprintf( stderr, "socket error:%s\n", strerror( errno ) );
		return -1;
	}
	if( -1 == ( connect( sockfd, ( struct sockaddr * )&server_addr, sizeof( server_addr ) ) ) )
	{
		perror( "connect" );
		fprintf( stderr, "connect error:%s\n", strerror( errno ) );
		return -1;
	}
	memset( str, 0x00, sizeof( str ) );
	sprintf( str, "GET %s HTTP/1.1\r\nAccept: */*\r\nAccept-Language: zh-cn\r\n"
				"User-Agent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT 5.0)\r\n"
				"Host: %s:80\r\nConnection: Close\r\n\r\n", file_path, addr );
	printf("%s", str);/*准备request，将要发送给主机*/
#if 0
	sprintf( str, "GET %s", file_path  );
   
	strcat( str, " HTTP/1.1 \r\n" );
//	strcat( str, "Connection:Keep-Alive\r\n" );
	strcat( str, "Accept:*/*\r\n" );
	strcat( str, "Accept-Language: zh-cn\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT 5.0)\r\n" );


    sprintf( str+strlen( str ), "HOST:%s:80\r\n", addr  );
	strcat( str, "Connection: Close\r\n\r\n" );
#endif
#if 0
	strcat( str, "Content-Type: text/html\n" );

	strcat( str, "Content-Length: " );
#endif
#if 0
    sprintf( send_str, "hellow   this is the first test for http " );

	sprintf( str+strlen( str ), "%d\n\n", (int)strlen( send_str ) );

	strcat( str, send_str );
#endif

    fprintf( stdout, "====================\n" );
	fprintf( stdout, "%s\n", str );
    fprintf( stdout, "====================\n" );

	write( sockfd, str, strlen( str ) );

	FILE    *fp = NULL;
	
	memset( file_name, 0x00, sizeof( file_name ) );
	snprintf( file_name, sizeof( file_name ), "%s/prectice/HTTP/downloadfile/%d%s",getenv( "HOME" ), getpid(), get_sys_time() );
	if( NULL == ( fp = fopen( file_name, "a" ) ) )
	{
		perror( "fopen" );
		fprintf( stderr, "fopen error:%s\n", strerror( errno ) );
		return -1;
	}

	int  len = 0;
	while( 1 )
	{
		memset( buf, 0x00, sizeof( buf ) );
		len = read( sockfd, buf, sizeof( buf ) );
		if( len == 0 )
			break;
		else if ( len<0 )
			fprintf( stderr, "read error:%s\n", strerror( errno ) );
//		fprintf( stdout, "%s", buf );
		fprintf( fp, "%s", buf );
	}
	fclose ( fp );

	close( sockfd ); 



	return 0;
}
/* 获取系统时间 */
char * get_sys_time( )
{
	static char      sys_time[14+1];
	struct    tm *tmp;
    time_t    second; 
	time( &second );
	tmp = localtime( &second );

	fprintf( stdout, "asctime:%s\n", asctime( tmp ) );

	memset( sys_time, 0x00, sizeof( sys_time ) );
	snprintf( sys_time,sizeof( sys_time ), "%04d%02d%02d%02d%02d%02d", tmp->tm_year+1900, tmp->tm_mon+1, tmp->tm_mday,tmp->tm_hour, tmp->tm_min, tmp->tm_sec ); 

    return  sys_time;	

}
