#include<netdb.h>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main( int argc, char **argv )
{
	struct hostent *host = NULL;
	char     *addr = NULL;
	uint16_t  addr_1;

	host = gethostbyname( argv[1] );
	addr_1 = ntohs( host->h_addr );

    fprintf( stdout, "host->h_addr%s\n", addr );

	

	return 0;
}
