#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<errno.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
int main( int argc, char **argv )
{
    int    socketfd;
    int    num;
	int    len;


	struct sockaddr_in server_addr;
	char   buf[ 1024 ];

	memset( &server_addr, 0x00, sizeof( server_addr ) );
	server_addr.sin_family=AF_INET,
	/* inet_addr 将点分16进制IP转换成long */
	server_addr.sin_addr.s_addr=inet_addr( "192.168.199.134" );
	server_addr.sin_port = htons( 12345 );

	if( -1 == ( socketfd = socket( AF_INET, SOCK_STREAM, 0 ) ) )
	{
        perror( "socket" );
		return -1;
	}

	if( -1 == ( connect( socketfd, ( struct sockaddr * )&server_addr, sizeof( server_addr ) ) ) )
	{
		perror( "connect" );
		return -1;
	}

	fprintf( stdout, "==============connect to server===================\n" );
#if 0
	if( -1 == ( len = recv( socketfd, buf, sizeof( buf ), 0 ) ) )
	{
		perror( "recv" );
		return -1;
	}
	buf[ strlen( buf ) ] ='\0';

	fprintf( stdout,"receive from server:%s\n", buf );
#endif
	while( 1 )
	{
		fprintf( stdout,  "input msg: \n" );
		fgets( buf, sizeof( buf ), stdin );
		if( -1 == ( len = send( socketfd, buf, sizeof( buf ), 0 ) ) ) 
		{
			perror( "send" );
			return -1;
		}
		fprintf( stdout, "client to server: %s\n", buf );
		memset( buf, 0x00, sizeof( buf ) );
		if( -1 == ( len = recv( socketfd, buf, sizeof( buf ), 0 ) ) )
		{
			perror( "recv" );
			return -1;
		}
		fprintf( stdout, "server to client: %s\n", buf );
	}
	close( socketfd );


	return 0;
}
