#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<netinet/in.h>  
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>
#include<unistd.h>

int main( int argc, char**argv )
{
	int    server_sockfd ;
	int    client_sockfd;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	char   buf[ 1024 ]={0};
	char   *ptr = NULL;

	if ( 0 >( server_sockfd = socket( AF_INET, SOCK_STREAM, 0  ) ) )
	{
		perror( "socket" );
		return -1;
	}

	memset( &server_addr, 0x00, sizeof( server_addr ) );
	server_addr.sin_family = AF_INET;
	/* IP设置为INADDR，让系统自动获取IP，这里要把主机字节序转换成网络字节序  */
	/* htonl htons, 将long型、short型 主机字节序转化为网络字节序 */
	/* ntohs, ntohl, short型、long型 网络字节序转化成主机字节序 */
	server_addr.sin_addr.s_addr = htonl( INADDR_ANY );
	server_addr.sin_port = htons( 12345 );

	/* 绑定本地地址到创建的套接字上 */
	if( 0> ( bind( server_sockfd, ( struct sockaddr * )&server_addr, sizeof( server_addr ) ) ) )
	{
		perror( "bind" );
		return -1;
	}
	/* 开始监听 */
	if( listen( server_sockfd, 10 ) < 0 )
	{
		perror( "listen" );
		return -1;
	}
	fprintf( stdout, "===============等待客户端访问================\n" );
	memset( &client_addr, 0x00, sizeof( client_addr ) );

	while( 1 )
	{
		if( -1 == ( client_sockfd = accept( server_sockfd, NULL, NULL ) ) ) 
		{
			perror( "accept" );
			return -1;
		}
		memset( buf, 0x00, sizeof( buf ) );
		if( 0> recv( client_sockfd, buf, sizeof( buf ), 0 ) )
		{
			perror( "recv" );
			return -1;
		}

		fprintf( stdout, "recv  end " );

		buf[ strlen( buf ) ]='\0';
		fprintf( stdout, "来自客户端的信息:%s\n", buf );
		buf[ strlen( buf )]='\0';
		ptr = buf;
		while( *ptr )
		{
			if( *ptr>'a' && *ptr<'z' )
					*ptr = *ptr-32;
			ptr++;
		}
		if( 0> ( send( client_sockfd, buf, sizeof( buf ), 0 ) ) )
		{
            perror( "send" );
			return -1;
		}
		close( client_sockfd );
		client_sockfd = -1;
		fprintf( stdout, "发送给客户端的消息%s\n", buf );
	}

	close( server_sockfd );
#if 0
   while(1){  
//阻塞直到有客户端连接，不然多浪费CPU资源。  
        if( (client_sockfd = accept( server_sockfd, (struct sockaddr*)NULL, NULL)) == -1){  
        printf("accept socket error: %s(errno: %d)",strerror(errno),errno);  
        continue;  
    }  
//接受客户端传过来的数据  
    recv( client_sockfd, buf, sizeof( buf ), 0);  
//向客户端发送回应数据  
    if(!fork()){ /*紫禁城*/  
        if(send( client_sockfd, "Hello,you are connected!\n", 26,0) == -1)  
        perror("send error");  
        close( client_sockfd );  
        exit(0);  
    }  
    buf[ strlen( buf ) ] = '\0';  
    printf("recv msg from client: %s\n", buf);  
    close( client_sockfd );  
    }  
    close( server_sockfd );  
#endif
	return 0;

}
